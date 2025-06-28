import { AfterViewInit, Component, ElementRef, Inject, OnInit, signal, ViewChild, ViewEncapsulation} from '@angular/core';
import { CodeTestResponse, ColorPair, popupData, TextStyles } from '../models/types';
import { GlobalsService } from '../Services/globals.service';
import { CodeAreaComponent } from '../code-area/code-area.component';

import jsPDF from 'jspdf';
import html2canvas from 'html2canvas';




@Component({
  selector: 'app-output-menu',
  imports: [CodeAreaComponent],
  templateUrl: './output-menu.component.html',
  styleUrl: './output-menu.component.css',
  encapsulation: ViewEncapsulation.None, // Disables scoped styles

})
export class OutputMenuComponent implements AfterViewInit {
  
  @ViewChild('page', { static: true }) page!: ElementRef;
  @ViewChild('page1', { static: true }) page1!: ElementRef;
  @ViewChild('page2', { static: false }) page2!: ElementRef;
  @ViewChild('page3', { static: false }) page3!: ElementRef;

  // async generatePDF() {
  //   const pdf = new jsPDF('p', 'mm', 'a4');

  //   const addPage = async (element: ElementRef, isFirst = false) => {
  //     const canvas = await html2canvas(element.nativeElement);
  //     const imgData = canvas.toDataURL('image/png');
  //     const imgProps = pdf.getImageProperties(imgData);
  //     const pdfWidth = pdf.internal.pageSize.getWidth();
  //     const pdfHeight = (imgProps.height * pdfWidth) / imgProps.width;

  //     if (!isFirst) pdf.addPage();
  //     pdf.addImage(imgData, 'PNG', 0, 0, pdfWidth, pdfHeight);
  //   };

  //   if(this.page)
  //   {
  //     await addPage(this.page, true);
  //   }

  //   // if(this.page1)
  //   // {
  //   //   console.log(this.page1);
      
  //   //   await addPage(this.page1, true); // Page 1
  //   // }
  //   // if(this.page2)
  //   // {
  //   //   console.log(this.page2);

  //   //   await addPage(this.page2);       // Page 2
  //   // }
  //   // if(this.page3)
  //   // {
  //   //   console.log(this.page3);

  //   //   await addPage(this.page3);       // Page 2
  //   // }

  //   pdf.save('custom-pages.pdf');
  // }

  generatePDF() {
    const content = document.getElementById('pdf-content');
    if (!content) return;
  
    // Temporarily remove scroll to capture full content
    const originalOverflow = content.style.overflow;
    content.style.overflow = 'visible';
  
    html2canvas(content, {
      scale: 2,
      useCORS: true,
      windowWidth: content.scrollWidth,
      windowHeight: content.scrollHeight
    }).then(canvas => {
      const imgData = canvas.toDataURL('image/png');
      const imgProps = {
        width: canvas.width,
        height: canvas.height
      };
  
      const pdf = new jsPDF('p', 'mm', 'a4');
      const pdfWidth = pdf.internal.pageSize.getWidth();
      const pdfHeight = pdf.internal.pageSize.getHeight();
  
      const imgWidth = pdfWidth;
      const imgHeight = (imgProps.height * imgWidth) / imgProps.width;
  
      let heightLeft = imgHeight;
      let position = 0;
  
      while (heightLeft > 0) {
        pdf.addImage(imgData, 'PNG', 0, position, imgWidth, imgHeight);
        heightLeft -= pdfHeight;
        position -= pdfHeight;
        if (heightLeft > 0) pdf.addPage();
      }
  
      // Restore original style
      content.style.overflow = originalOverflow;
  
      pdf.save('report.pdf');
    });
  }
  

  // response!:CodeTestResponse;

  ngAfterViewInit(): void {

    const tagColorPairs: { background: string; font: string }[] = [
      { background: "#E0F7FA", font: "#006064" },
      { background: "#FCE4EC", font: "#880E4F" },
      { background: "#FFF3E0", font: "#E65100" },
      { background: "#E8F5E9", font: "#1B5E20" },
      { background: "#F3E5F5", font: "#4A148C" },
      { background: "#E1F5FE", font: "#01579B" },
      { background: "#FBE9E7", font: "#BF360C" },
      { background: "#F0F4C3", font: "#827717" },
      { background: "#FFEBEE", font: "#B71C1C" },
      { background: "#EDE7F6", font: "#311B92" },
      { background: "#ECEFF1", font: "#263238" },
      { background: "#FFFDE7", font: "#F57F17" },
    ];
  
    let counter = 0;
    const tags = document.querySelectorAll('.tag');
  
    tags.forEach((element) => {
      const colors = tagColorPairs[counter % tagColorPairs.length];
      (element as HTMLElement).style.backgroundColor = colors.background;
      (element as HTMLElement).style.color = colors.font;
      counter++;
    });

  }

  old_code!:string;
  new_code!:string;
  message!:string;
 
  // ngOnInit(): void {

  //   console.log('old_code', this.globals.fullReport?.code);
  //   console.log('new_code', this.globals.fullReport?.corrected_code);
    



  //   // console.log("corrected code: ",this.globals.fullReport?.corrected_code);
  //   // console.log(this.old_code);
  // }

  constructor(
    @Inject(GlobalsService) public globals:GlobalsService
  ){

  
    this.old_code = this.globals.fullReport?.code!;
    this.new_code = this.globals.fullReport?.corrected_code!;
    const lines = this.globals.fullReport?.feedback_message.split('\n');
    this.message = lines!.slice(0, -1).join('\n');
    
    // console.log(this.new_code);
    
    
  }
  
  // Close()
  // {
  //   if (typeof this.data[1] === "function") {
  //     (this.data[1] as () => void)();
  //   }  
  // }
  
  // // TestCasesBehaviour()
  // // {
  // //   console.log(this.data);
  // //   let iframe = this.dialogRef.open(PDFComponent, {
  // //     data: this.data[0],
  // //     panelClass: 'QdialogIframe'
  // //   })
  // // }
  

  // GetReport(reportName:string, path:string)
  // {
  //   let iframe = this.dialogRef.open(PDFComponent, {
  //     data: [reportName, path, ()=>{iframe.close()}],
  //     panelClass: 'QdialogIframe' 
  //   })
  // }

  // GetText(text:string, code:boolean = false)
  // {

  //   if(code)
  //   {
  //     let iframe = this.dialogRef.open(CodeAreaComponent, {
  //       data: {
  //         code: text
  //       },
  //       panelClass: 'QdialogIframe' 
  //     })
  //   }
  //   else
  //   {
  //     let popupData:popupData = {
  //       message: text,
  //       element: null,
  //       buttonNames: [],
  //       buttonFunctions: [],
  //       defaultButtons: true,
  //       code: null,
  //       happyState: true,
  //       language: null,
  //       textStyle: TextStyles.normal
  //     }
  
  //     let iframe = this.dialogRef.open(PopUpComponent, {
  //       data: popupData,
  //       panelClass: 'Qdialog' 
  //     })
  //   }


  // }


  // FullReportBehaviour()
  // {
  //   let path = (this.response).full_report;
  //   this.GetReport("Full Report", path);
  // }

  // TestCasesReportBehaviour()
  // {
  //   let path = (this.response).test_cases_status_report;
  //   this.GetReport("Test Cases Report",path);
  // }
  // BugReportBehaviour()
  // {
  //   let path = (this.response).bug_report;
  //   this.GetReport("Bug Report",path);
  // }
  // TestCasesBehaviour()
  // {
  //   this.GetText(this.response.test_cases);
  // }
  // CodeDescriptionBehaviour()
  // {
  //   this.GetText(this.response.description);
  // }
  // CodeBehaviour()
  // {
  //   this.GetText(this.response.code_after_bug_fixing, true);
  // }
  // DepenenciesBehaviour()
  // {
  //   this.GetText(this.response.dependencies);
  // }



  // FlowchartBehaviour()
  // {

  //   let label = document.createElement('p');
  //   label.textContent = "Flowchart download options\n";
  //   label.style.fontWeight = 'bold';
  //   label.style.fontSize = '2em';

  //   let popupData:popupData = {
  //     message: "\nhorizontal and vertical original flowcharts images will be downloaded automatically\n\nplease choose which simulation frames to be downloaded",
  //     element: label,
  //     buttonNames: ["horizontal frames","vertical frames", "both frames"],
  //     buttonFunctions: [()=>{iframe.close()}, ()=>{iframe.close()}, ()=>{iframe.close()}],
  //     defaultButtons: true,
  //     code: null,
  //     happyState: true,
  //     language: null,
  //     textStyle: TextStyles.normal
  //   }

  //   let iframe = this.dialogRef.open(PopUpComponent, {
  //     data: popupData,
  //     panelClass: 'Qdialog' 
  //   })
  // }

  // empty(){}

}
