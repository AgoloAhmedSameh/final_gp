import { AfterViewInit, Component, ElementRef, signal, ViewChild, Renderer2, OnInit, Inject, inject, Signal } from '@angular/core';
import { ButtonComponent } from '../button/button.component';
import { SingleButtonComponent } from '../single-button/single-button.component';
import { MatDialog, MatDialogModule } from '@angular/material/dialog';
import { ProfileCardComponent } from '../profile-card/profile-card.component';
import { PopUpComponent } from '../pop-up/pop-up.component';
import { LoadingComponent } from '../loading/loading.component';
import { CodeRequest, CodeResponse, CodeTestRequest, CodeTestResponse, FlowchartRequest, FlowchartResponse, popupData, ProfileData, ProgrammingLanguages, TextStyles, TypeOfTesting } from '../models/types';
import { debounceTime, single, Subject, timeout } from 'rxjs';
import { CodeAreaComponent } from '../code-area/code-area.component';
import { FormsModule } from '@angular/forms';
import { FlowchartGeneratorService } from '../Services/flowchart-generator.service';
import { HttpClient, HttpClientModule} from '@angular/common/http';
import { OutputMenuComponent } from '../output-menu/output-menu.component';
import { ApiService } from '../Services/api-service.service';
import { CodemirrorComponent } from '@ctrl/ngx-codemirror';
import { GlobalsService } from '../Services/globals.service';
import { Router } from '@angular/router';
// import {DropDownListModule} from '@syncfusion/ej2-angular-dropdowns';


// async function readDirectory(path: string) {
//   try {
//       const files = await fs.readdir(path);
//       console.log('Files:', files);
//   } catch (error) {
//       console.error('Error reading directory:', error);
//   }
// }

@Component({
  selector: 'app-home-page',
  standalone: true,
  imports: [ButtonComponent, SingleButtonComponent, ProfileCardComponent, LoadingComponent, PopUpComponent, MatDialogModule, CodeAreaComponent, FormsModule, OutputMenuComponent],
  templateUrl: './home-page.component.html',
  styleUrl: './home-page.component.css'
})
export class HomePageComponent implements OnInit, AfterViewInit {

  @ViewChild(CodeAreaComponent) codeArea!: CodeAreaComponent;
  @ViewChild('codeMirror') codeMirrorComponent!: CodemirrorComponent;


  @ViewChild('flowchart', {static: false}) flowchartArea!: ElementRef;
  @ViewChild('description', {static: false}) descriptionArea!: ElementRef;
  @ViewChild('dependencies', {static: false}) dependenciesArea!: ElementRef;
  @ViewChild('profile', {static: true}) profileElement!: ElementRef;
  @ViewChild('descriptionContainer', {static: true}) descriptionContainer!:ElementRef;
  @ViewChild('stepIntoOptions', {static: false}) stepIntoOptions!:ElementRef;

  private clickSubject = new Subject<string|null>();

  
  code:string = ``;
  descriptionText:string = localStorage['description'];
  dependenciesText:string = localStorage['dependencies'];
  
  selectedLanguage:ProgrammingLanguages = ProgrammingLanguages.Python;
  
  
  isSimulatorON = signal(false);
  isSimulatorRunning = signal(false);
  isSimulationPaused = signal(false);
  isSimulationStoped = signal(true);
  skipBranch = signal(false);
  getPreviousBranchRequest = signal(false);
  updateFrameRequest = signal(false);

  counter = signal(1);
  branchesCount = signal(-1);
  simulatorSpeed = signal(10);

  lastFrames:Array<Array<Array<any>>> = [];

  currentBranch:Array<Array<any>> | null = null;
  currentNodeIndex = signal(0);

  delayTime = 80000 / ( 10 * this.simulatorSpeed());

  isProfileOpen = signal(false);
  isCodeWindowActive = signal(0);
  isDescriptionWindowActive = signal(0);
  isDependenciesWindowActive = signal(0);
  isFlowchartWindowActive = signal(0);
  


  selectedTestingType:string = 'Integration';

  flowchartImageURL:string | null = null;
  flowchartRequest:boolean = false;
  flowchartError:boolean = false;
  codeQueue:Array<string> = [];


  user:ProfileData = {
    firstName: "John",
    lastName: "Doe",
    email: "user@example.com",
    phoneNumber: "+1234567890",
    jobTitle: "Software Engineer"
  };
  




  constructor(
    private renderer: Renderer2,
    private dialogRef: MatDialog,
    private router: Router,
    
    @Inject(ApiService) private api:ApiService,
    @Inject(FlowchartGeneratorService) private _flowChartGeneratorService:FlowchartGeneratorService,
    @Inject(GlobalsService) private globals:GlobalsService
  )
  {
    this.clickSubject.pipe(debounceTime(100)).subscribe((elementName:string|null) => {
      // console.log("Button clicked after 100ms delay!");
      // console.log('so you clicked!?');
      
      if(this.codeArea != null && elementName != 'editor-settings')
        this.codeArea.removeClass(this.codeArea.code,'active');
      if(this.descriptionArea != null && elementName != 'description')
        this.removeClass(this.descriptionArea,'active');
      if(this.dependenciesArea != null && elementName != 'dependencies')
        this.removeClass(this.dependenciesArea,'active');
      if(this.flowchartArea != null && elementName != 'flowchart')
      {
        this.removeClass(this.flowchartArea,'active');
        this.removeClass(this.flowchartArea,'horizontal');
        this.flowchartImageURL = (this.flowchartImageURL?.replace('LR','TB'))!;
      }
      if(elementName === 'editor-settings')
      {
        // console.log('code!');
        this.isDescriptionWindowActive.set(0);
        this.isDependenciesWindowActive.set(0);
        this.isFlowchartWindowActive.set(0);

        this.isCodeWindowActive.set(this.isCodeWindowActive() + 1);
        if(this.isCodeWindowActive() >= 2)
        {
          this.isCodeWindowActive.set(0);
          if(this.codeArea != null)
            this.codeArea.addClass(this.codeArea.code,'active');
        }
      }

      else if(elementName === 'description')
      {
        // console.log('description!');
        this.isCodeWindowActive.set(0);
        this.isDependenciesWindowActive.set(0);
        this.isFlowchartWindowActive.set(0);

        this.isDescriptionWindowActive.set(this.isDescriptionWindowActive() + 1);
        if(this.isDescriptionWindowActive() >= 2)
          {
            this.isDescriptionWindowActive.set(0);
            if(this.descriptionArea != null)
              this.addClass(this.descriptionArea, 'active');
          }
      }

      else if(elementName === 'dependencies')
      {
        // console.log('dependencies!');
        this.isCodeWindowActive.set(0);
        this.isDescriptionWindowActive.set(0);
        this.isFlowchartWindowActive.set(0);

        this.isDependenciesWindowActive.set(this.isDependenciesWindowActive() + 1);
        if(this.isDependenciesWindowActive() >= 2)
          {
            this.isDependenciesWindowActive.set(0);
            if(this.dependenciesArea != null)
              this.addClass(this.dependenciesArea,'active');
          }
      }
      else if(elementName === 'flowchart')
      {
        // console.log('flowchart!');

        this.isCodeWindowActive.set(0);
        this.isDescriptionWindowActive.set(0);
        this.isDependenciesWindowActive.set(0);

        this.isFlowchartWindowActive.set(this.isFlowchartWindowActive() + 1);
        if(this.isFlowchartWindowActive() >= 2)
          {
            this.isFlowchartWindowActive.set(0);
            if(this.flowchartArea != null)
            {
              this.addClass(this.flowchartArea,'active');
              this.addClass(this.flowchartArea,'horizontal');
              // console.log(this.flowchartImageURL);
              this.flowchartImageURL = (this.flowchartImageURL?.replace('TB','LR'))!;
              // console.log(this.flowchartImageURL);

            }
          }
      }
      else
      {
        this.isCodeWindowActive.set(0);
        this.isDescriptionWindowActive.set(0);
        this.isDependenciesWindowActive.set(0);
        this.isFlowchartWindowActive.set(0);
      }

      setTimeout(() => {
        this.isCodeWindowActive.set(0);
        this.isDescriptionWindowActive.set(0);
        this.isDependenciesWindowActive.set(0);
        this.isFlowchartWindowActive.set(0);
      }, 200);
    });
  }
 
  addClass(element: ElementRef | CodemirrorComponent, className: string) {
    let targetElement;
  
    if (element instanceof CodemirrorComponent && element.codeMirror) {
      targetElement = element.codeMirror.getWrapperElement(); // Get CodeMirror wrapper
    } else if (element instanceof ElementRef) {
      targetElement = element.nativeElement; // Get native element
    }
  
    if (targetElement) {
      this.renderer.addClass(targetElement, className);
    }
  }
  
  removeClass(element: ElementRef | CodemirrorComponent, className: string) {
    let targetElement;
  
    if (element instanceof CodemirrorComponent && element.codeMirror) {
      targetElement = element.codeMirror.getWrapperElement();
    } else if (element instanceof ElementRef) {
      targetElement = element.nativeElement;
    }
  
    if (targetElement) {
      this.renderer.removeClass(targetElement, className);
    }
  }
  
  // onLanguageSelectionChange(event: Event)
  // {
  //   const selectElement = event.target as HTMLSelectElement;
  //   this.selectedLanguage = selectElement.value;
  // }
  // onTestingSelectionChange(event: Event)
  // {
  //   const selectElement = event.target as HTMLSelectElement;
  //   this.selectedTestingType = selectElement.value;
  // }

  SaveCode(event: Event)
  {
    const selectElement = event.target as HTMLTextAreaElement;
    localStorage[selectElement.id] = selectElement.value
  }

  RunSimulator() {
    if(this.flowchartRequest || this.isSimulatorRunning())
      return;

    this.flowchartRequest = true;
    console.log('Requesting!');
    
    console.log('waiting! .............................................');

    this.GetFlowchart(true);
    
  }
  CloseSimulation()
  {
    this.isSimulatorRunning.set(false);
    this.GetFlowchart(false);
  }
  PauseSimulation()
  {
      this.isSimulationPaused.set(!this.isSimulationPaused());
      this.updateFrameRequest.set(true);
      
      console.log(this.isSimulationPaused());

      if(this.isSimulationPaused())
        this.addClass(this.stepIntoOptions, 'simulation-paused');
      else
        this.removeClass(this.stepIntoOptions, 'simulation-paused');

      // if(this.isSimulationPaused())
      //   this.delayTime = 10000000000;
      // else
      //   this.delayTime = 80000 / ( 10 * this.simulatorSpeed());
  }
  SkipBranch()
  {
    if(this.isSimulationPaused())
      return
    
    this.skipBranch.set(true);
  }
  PreviousBranch()
  {
    if(this.isSimulationPaused())
      return

    this.getPreviousBranchRequest.set(true);
  }
  PreviousFrame()
  {
    this.currentNodeIndex.update(val=>{if(val - 1 >= 0)return val - 1; return val;});
    this.flowchartImageURL = this.currentBranch![this.currentNodeIndex()][0];
    console.log(this.currentNodeIndex());
  }
  NextFrame()
  {
    this.currentNodeIndex.update(val=>{if(val + 1 < this.currentBranch!.length)return val + 1; return val;});
    this.flowchartImageURL = this.currentBranch![this.currentNodeIndex()][0];
    console.log(this.currentNodeIndex());
  }
  SimulatorSpeedChange(event:Event)
  {
    // console.log(event);
    // console.log(event.target);
    // console.log(event.target);
    console.log(this.simulatorSpeed);
    this.delayTime = 80000 / ( 10 * this.simulatorSpeed());
    
  }
  ReplaySimulation()
  {
    if(this.isSimulationPaused())
      this.PauseSimulation();

    this.isSimulatorRunning.set(false);

    const waitUntilFinish = () => {
      setTimeout(() => {
        if(this.isSimulationStoped())
          {
            this.isSimulatorRunning.set(true);
            this.processSimulation(this.lastFrames);
          }
        else
          waitUntilFinish();
      }, this.delayTime);
    }
    waitUntilFinish();

  }

  TestCode(
    feedbackMessage:string,
    chosenCode:string,
    isCodeCorrected:boolean,
  )
  {
     // loading
     let loadingDialog = this.dialogRef.open(PopUpComponent, {
      data: this.globals.loadingData,
      panelClass: 'Qdialog'
    });
    
    let language = 'python';

    if (this.selectedLanguage == ProgrammingLanguages.CPP)
      language = 'c++';
    else if(this.selectedLanguage == ProgrammingLanguages.Java)
      language = 'java';
    else if(this.selectedLanguage == ProgrammingLanguages.JavaScript)
      language = 'javascript';

    let codeTestRequest:CodeTestRequest = {
      code: chosenCode,
      description: this.descriptionText,
      language: language,
      type_of_testing: this.selectedTestingType
    }


    // console.log("chosen code is: ", chosenCode);
    // console.log("is code corrected?", isCodeCorrected);
    

    this.api.testCode(codeTestRequest).subscribe({
      next: (full_report_response:CodeTestResponse)=>{
        loadingDialog.close();

        this.globals.fullReport = {
          code:(isCodeCorrected ? this.code : chosenCode),
          corrected_code: (isCodeCorrected ? chosenCode : ""),
          feedback_message: feedbackMessage,
          response: {
            correctness: full_report_response.correctness,
            coverage: full_report_response.coverage,
            description: full_report_response.description,
            asserts: full_report_response.asserts,
            faild_asserts: full_report_response.faild_asserts
          }
        }

        console.log("\n\n\n\n\nTHE DATA\n\n\n\n");
        console.log(this.globals.fullReport);
        console.log("\n\n\n\n\nTHE DATA\n\n\n\n");
        
        this.router.navigateByUrl('/full-report-page');
        // let outputDialog = this.dialogRef.open(OutputMenuComponent, {
        //   data: [response, ()=>{outputDialog.close()}],
        //   panelClass: 'QdialogLeftPinned'
        // })
      },
      error: ()=>{
        loadingDialog.close();
      }
    })

    // this.api.testCode(codeTestRequest).subscribe(blob => {
    //   loadingDialog.close();
    //   const url = window.URL.createObjectURL(blob);
    //   console.log(url);
    //   // const a = document.createElement('a');
    //   // a.href = url;
    //   // a.download = 'output_file.pdf'; // Change this to match the actual file type
    //   // document.body.appendChild(a);
    //   // a.click();
    //   // document.body.removeChild(a);
    // });
  }

  Run()
  {
      
    let dialogData = this.globals.loadingData;
    let dialog = this.dialogRef.open(PopUpComponent, {
      data: dialogData,
      panelClass: 'Qdialog'
    })

    const dependenciesArray = this.dependenciesText.split(",").map(dep => dep.trim());
    


    let codeRequest:CodeRequest = {
      code: this.code,
      description: this.descriptionText,
      language: this.selectedLanguage,
      dependencies: dependenciesArray
    }
    
    console.log(codeRequest);
    

    this.api.analyzeCode(codeRequest).subscribe({
      next: (response:CodeResponse) => {

        dialog.close()

        let dialog2Data:popupData = {
          message: response.feedback_message,
          element: ((response.matching_flag && response.syntax_flag) ? null : CodeAreaComponent),
          buttonNames: ((response.matching_flag && response.syntax_flag) ? ['cancel','continue'] : ['cancel','corrected','original']),
          buttonFunctions: response.matching_flag && response.syntax_flag 
          ?
            [
              ()=>{
                dialog2.close()
              },
              ()=> {                
                // continue behaviour
                dialog2.close()
                this.TestCode(response.feedback_message, this.code, false)
              }
            ]
          :
            [
              ()=>{
                dialog2.close()
              },
              ()=>{
                // corrected behaviour
                dialog2.close()
                this.TestCode(response.feedback_message, response.enhanced_code, true)
              },
              ()=>{
                // original behaviour
                dialog2.close()
                this.TestCode(response.feedback_message, this.code, false)                
              },
            ],

          happyState: (response.matching_flag && response.syntax_flag?true:false),
          defaultButtons: false,
          textStyle: TextStyles.normal,
          code: response.enhanced_code,
          language: this.selectedLanguage
        };
        
        let dialog2 = this.dialogRef.open(PopUpComponent, {
          data: dialog2Data,
          panelClass: 'Qdialog'
        })
    
      },
      error: () => {
        dialog.close()
      }
    })
    // setTimeout(()=>{
    //   dialog.close();

    //   let message1:string = `Your code is a perfect match for the description you provided, ensuring it aligns well with the intended functionality. However, it contains some syntax errors that may prevent it from running correctly. \n \n Below is the suggested code after applying fixes. \n \n Please choose whether you would like to continue with your original code or proceed with the corrected version.`;

    //   let output:popupData = {
    //     message: message1,
    //     element: CodeAreaComponent,
    //     buttonNames: ['cancel','corrected','original'],
    //     buttonFunctions: [()=>{dialog2.close()},()=>{dialog2.close()},()=>{dialog2.close()}],
    //     happyState: false,
    //     defaultButtons: false,
    //     textStyle: TextStyles.normal,
    //     code: 
    //   };

    //   let dialog2 = this.dialogRef.open(PopUpComponent, {
    //     data: output,
    //     panelClass: 'Qdialog'
    //   })

    // }, 10000);

    // setTimeout(()=>{
    //   // dialog.close();

    //   let message1:string = `Your code does not match the description you provided, and contains syntax errors.\nBelow is a suggested version of your code with fixes.\n\nPlease review the changes and choose whether you would like to continue with your original code or proceed with the corrected version.`;

    //   let output:popupData = {
    //     message: message1,
    //     element: CodeAreaComponent,
    //     buttonNames: ['cancel','corrected','original'],
    //     buttonFunctions: [()=>{dialog3.close()},()=>{dialog3.close()},()=>{dialog3.close()}],
    //     happyState: false,
    //     defaultButtons: false,
    //     textStyle: TextStyles.normal,
    //     code: `
    //         <div class="home-page-body">
    //       <!-- <div class="code">
    //           <div class="editor-settings">
    //               <div class="c1"></div>
    //               <div class="c2"></div>
    //               <div class="c3"></div>

    //               <select name="languae-type" (change)="onLanguageSelectionChange($event)">
    //                   <option value="python">Python</option>
    //                   <option value="java">Java</option>
    //                   <option value="c++">C++</option>
    //                   <option value="javaScript">JavaScript</option>
    //               </select>

    //               <select name="testing-type" (change)="onTestingSelectionChange($event)">
    //                   <option value="integration">Integration</option>
    //                   <option value="unit">Unit</option>
    //               </select>
    //           </div>
    //           <textarea name="code" id="code" #code placeholder="Write your code here ..." (input)="SaveCode($event)"></textarea>
    //       </div> -->
    //       <div class="codeArea">
    //           <app-code-area [forViewOnly]="false"></app-code-area>
    //       </div>

    //       <div class="description">
    //           <!-- <div class="editor-settings"></div> -->
    //           <textarea name="code" id="description" #description placeholder="Write a description for your code here ..." (input)="SaveCode($event)"></textarea>
    //       </div>
    //       <div class="dependencies">
    //           <!-- <div class="editor-settings"></div> -->
    //           <textarea name="code" id="dependencies" #dependencies placeholder="Write your code dependencies ..." (input)="SaveCode($event)"></textarea>
    //       </div>
    //   </div>
    //     `
    //   };

    //    let dialog3 = this.dialogRef.open(PopUpComponent, {
    //     data: output,
    //     panelClass: 'Qdialog'
    //   })

    // }, 20000);

    // setTimeout(()=>{
    //   // dialog.close();

    //   let message1:string = `Your code does not fully match the description you provided, but it is free from syntax errors.\n\nTo better align it with your requirements, I have made some adjustments and prepared a suggested version.\n\nPlease review the suggested code and choose whether you would like to continue with your original code or proceed with the corrected version.`;

    //   let output:popupData = {
    //     message: message1,
    //     element: CodeAreaComponent,
    //     buttonNames: ['cancel','corrected','original'],
    //     buttonFunctions: [()=>{dialog3.close()},()=>{dialog3.close()},()=>{dialog3.close()}],
    //     happyState: false,
    //     defaultButtons: false,
    //     textStyle: TextStyles.normal,
    //     code: `
    //      @if (forViewOnly()) {
    //     <p name="code" id="code" #code placeholder="Write your code here ..." (input)="SaveCode($event)">
    //         {{codeString}}
    //     </p>
    //     }
    //     @else {
    //         <textarea name="code" id="code" #code placeholder="Write your code here ..." (input)="SaveCode($event)">{{codeString | typewriter}}</textarea>
    //     }
    //     `
    //   };

    //    let dialog3 = this.dialogRef.open(PopUpComponent, {
    //     data: output,
    //     panelClass: 'Qdialog'
    //   })

    // }, 30000);

    // setTimeout(()=>{
    //   // dialog.close();

    //   let message1:string = `The code provided is a perfect match to the description, ensuring that all functionalities align precisely with the intended purpose.\n\nAdditionally, it has been thoroughly reviewed to be free from any syntax errors or bugs, guaranteeing smooth execution.\n\nPlease press "Continue" to start testing.`;

    //   let output:popupData = {
    //     message: message1,
    //     element: null,
    //     buttonNames: ['cancel','continue'],
    //     buttonFunctions: [()=>{dialog3.close()},()=>{dialog3.close()}],
    //     happyState: true,
    //     defaultButtons: false,
    //     textStyle: TextStyles.normal,
    //     code: null
    //   };

    //    let dialog3 = this.dialogRef.open(PopUpComponent, {
    //     data: output,
    //     panelClass: 'Qdialog'
    //   })

    // }, 40000);
    // setTimeout(()=>{

    //   let dialog2 = this.dialogRef.open(OutputMenuComponent, {
    //     panelClass: 'Qdialog'
    //   })

    // }, 50000);

    
  }

  
  ToggleProfile()
  {
    console.log("Toggle!");
    
    this.isProfileOpen.set(!this.isProfileOpen());

    if(this.isProfileOpen())
    {
      this.addClass(this.profileElement,'active')
    }
    else
    {
      this.removeClass(this.profileElement,'active')
    }

  
    this.dialogRef.open(ProfileCardComponent, {
      data: this.globals.currentLoggedInUser,
      panelClass: 'Qdialog'
    })

  }

  DownloadGrpah()
  {
    console.log(this.isSimulatorRunning());
    
    this.api.downloadFolder((this.isSimulatorRunning())).subscribe(blob => {
      const url = window.URL.createObjectURL(blob);
      const anchor = document.createElement('a');
      anchor.href = url;
      anchor.download = 'Graph.zip';
      anchor.click();
      window.URL.revokeObjectURL(url);
    });
  }

  ToggleSimulatorButton()
  {
    this.isSimulatorON.set(!this.isSimulatorON());  
    this.onChildTextChanged(this.code);
  
  }

  empty(){}

  ngOnInit(): void {
    if(localStorage['description'] == null)
      localStorage['description'] = "";
    
    if(localStorage['dependencies'] == null)
      localStorage['dependencies'] = "";

    

  }

  onChildLangugaeChange(newLang: ProgrammingLanguages)
  {
    this.selectedLanguage = newLang;
    this.onChildTextChanged(this.code)    
  }
  onChildTypeOfTestingChange(newTypeOfTesting: TypeOfTesting)
  {
    this.selectedTestingType = newTypeOfTesting; 
  }


  processSimulation = async (simulationFrames:Array<Array<Array<any>>>) => {

  
    const delay = (ms: number) => new Promise(resolve => {
      setTimeout(resolve, ms); // Keep checking every 100ms    
    });

    const pause = () => new Promise(resolve => {
      const check = () => {
        console.log('checking!');
        
        if (this.isSimulationPaused()) {
          setTimeout(check, 100); // Keep checking every 100ms
        } else {
          setTimeout(resolve, 50);
        }
      };
      check();
    });



    this.isSimulationStoped.set(false);
    let originalPath = this.flowchartImageURL;
    this.counter.set(1);

    for(let i:number = 0; i < simulationFrames.length; i++)
    {
      if(this.getPreviousBranchRequest())
      {

        if(i > 0)
        {  
          i -= 1;
          this.counter.update(val => val - 1);
        }
        
        console.log(i);
        this.getPreviousBranchRequest.set(false);
      }

      this.currentBranch = simulationFrames[i];

      for(let j:number = 0; j < simulationFrames[i].length; j++)
      {
        
        if(this.updateFrameRequest())
        {
          this.updateFrameRequest.set(false);
          j = this.currentNodeIndex() - 1; // -1 to undo the j++ effect after the loop
          continue;
        }
        if(!this.isSimulatorRunning())
        {
          this.flowchartImageURL = originalPath;
          this.isSimulationStoped.set(true);
          return;
        }
        this.flowchartImageURL = simulationFrames[i][j][0];
        if(this.skipBranch())
        {
          this.skipBranch.set(false);
          break;
        }
        
        if(this.getPreviousBranchRequest())
        {
          i--;
          break;
        }
        
        this.currentNodeIndex.set(j);
        await delay(this.delayTime);
        await pause();
      }
        if(this.getPreviousBranchRequest())
          continue;

        await delay(2000); // Wait for 2000ms before proceeding to the next branch
        this.counter.update(value => value + 1);
    }

    this.isSimulationStoped.set(true);
    this.counter.set(this.branchesCount());
    this.flowchartImageURL = originalPath; // Reset to original image after animation
  
  };

  GetFlowchart(getFrames = false)
  {
    let request: FlowchartRequest = {
      code: this.code,
      language: this.selectedLanguage,
      include_macros_in_cpp: true,
      get_frames: getFrames,
      required_format: getFrames
      ? this.descriptionArea?.nativeElement?.classList.contains('active')
        ? 'LR'
        : 'TB'
      : null
    }

    this.api.getFlowchart(request).subscribe({
      next: (response:FlowchartResponse) => {
        console.log(response.flow_chart_TB);
        console.log('✅ Image generated successfully!');
        this.flowchartRequest = false;
        this.flowchartError = false;
        if(request.get_frames)
        {

          this.counter.set(1);
          console.log(response.simulation_path);
          
          this.isSimulatorRunning.set(true);
          this.branchesCount.set(response.simulation_path!.length);
          this.lastFrames = response.simulation_path!;
        
          // Start the simulation
          this.processSimulation(response.simulation_path!);

        }
        else
        {
          this.flowchartImageURL = `${response.flow_chart_TB}?t=${new Date().getTime()}`;
          if(this.codeQueue.length > 0){
            let lastCodeChange:string = this.codeQueue[this.codeQueue.length - 1];
            this.codeQueue = [];
            this.descriptionContainer.nativeElement.scrollTop =  this.descriptionContainer.nativeElement.scrollHeight;
  
            this.onChildTextChanged(lastCodeChange);
          }
        }
      },

      error: (err) => {
          this.flowchartRequest = false;
          this.flowchartError = true
          console.error('❌ Error generating image:', err);
      }
    });
  }

  onChildTextChanged(newText: string) {
    // console.log('change!');
  

    this.code = newText; // Updates as the child emits changes
  

    
    if(this.isSimulatorON() && !this.flowchartRequest)
    {
      this.flowchartRequest = true;
      console.log('Requesting!');
      
      console.log('waiting! .............................................');
      this.GetFlowchart()
 
    }
    else
    {
      this.codeQueue.push(newText);
    }
  }

  ngAfterViewInit(): void {
    
    document.querySelectorAll('*').forEach(element => {
      element.addEventListener('click',(eventArgs)=>{
        // console.log('click');
        let element = eventArgs.target as HTMLElement;
        if(element.classList.contains('CodeMirror-scroll') || element.classList.contains('CodeMirror-lines') || element.classList.contains('CodeMirror-line'))
          return;
        let elementName = element.getAttribute('name');
        // console.log(element);
        setTimeout(() => {
          this.clickSubject.next(elementName);
        }, 100);

        // console.log(elementName);
      })
    });
    

  }

}
