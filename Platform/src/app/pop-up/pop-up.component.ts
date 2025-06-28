import { AfterViewInit, Component, ElementRef, inject, Inject, input, Input, OnInit, Renderer2, Type, viewChild, ViewChild, ViewContainerRef } from '@angular/core';
import { ButtonComponent } from '../button/button.component';
import { MAT_DIALOG_DATA, MatDialogRef } from '@angular/material/dialog';
import { LoadingComponent } from '../loading/loading.component';
import { TextStyles } from '../models/types';
import { CodeAreaComponent } from '../code-area/code-area.component';
import { NgComponentOutlet } from '@angular/common';

@Component({
  selector: 'app-pop-up',
  imports: [ButtonComponent, LoadingComponent, CodeAreaComponent, NgComponentOutlet],
  templateUrl: './pop-up.component.html',
  styleUrl: './pop-up.component.css',
})
export class PopUpComponent implements AfterViewInit, OnInit {


  
  
  @ViewChild('content', {static: true})
  contentElement!: ElementRef;
  
  @ViewChild('text', {static: false})
  textElement!: ElementRef

  
  @ViewChild('buttons', {static: false})
  buttonsElement!: ElementRef

  
  // contentVCR = viewChild('component', {read:ViewContainerRef});

  LoadingComponentProperty = LoadingComponent;
  CodeAreaComponentProperty = CodeAreaComponent;


  happyState:boolean = true;
  message:string;
  element: Element | LoadingComponent | CodeAreaComponent | null;
  buttonNames:string[];
  buttonFunctions:Function[];
  defaultButtons:boolean;
  textStyle:TextStyles;
  code:String;

  protected targetComponent: Type<LoadingComponent> | Type<CodeAreaComponent> | null = null;

  constructor(@Inject(MAT_DIALOG_DATA) public data: any, public dialogRef: MatDialogRef<PopUpComponent>, private renderer: Renderer2) {

      this.message = this.data['message'];
      this.element = this.data['element'];
      this.buttonNames = this.data['buttonNames'];
      this.buttonFunctions = this.data['buttonFunctions'];
      this.happyState = this.data['happyState'];
      this.defaultButtons = this.data['defaultButtons'];
      this.textStyle = this.data['textStyle'];
      this.code = data['code'];


      // Default Buttons
      if(this.defaultButtons)
      {
        this.buttonNames.push('OK');
        this.buttonNames.push('CANCEL');
  
        for(let i:number = 0; i < 2; i++)
        {
  
          this.buttonFunctions.push(
            () => {
              this.dialogRef.close();
            }
          )
        }
      }
  }

  addClass(element: ElementRef, className: string) {
    this.renderer.addClass(element.nativeElement, className);
  }

  removeClass(element: ElementRef, className: string) {
    this.renderer.removeClass(element.nativeElement, className);
  }


  ngAfterViewInit(): void {
    
    if(this.textStyle === TextStyles.green)
    {
      this.addClass(this.textElement, 'green-message')
    }
    else if(this.textStyle === TextStyles.red)
    {
      this.addClass(this.textElement, 'red-message')
    }

    try
    {
      if(this.element != null)
      {
        this.contentElement.nativeElement.insertAdjacentElement('afterbegin', this.element)
      }
    }
    catch
    {
    }
    finally
    {
      if(this.element === LoadingComponent)
        {
          console.log('yessss!');
          // this.contentVCR()?.createComponent(LoadingComponent);
          this.targetComponent = LoadingComponent;
        }
      if(this.element === CodeAreaComponent)
        {
          // console.log('yessss!');
          this.targetComponent = CodeAreaComponent;
          // this.contentVCR()?.createComponent(CodeAreaComponent);
        }

        this.buttonsElement.nativeElement.scrollTop = this.buttonsElement.nativeElement.scrollHeight;
        window.addEventListener("resize", () => {
          this.buttonsElement.nativeElement.scrollTop = this.buttonsElement.nativeElement.scrollHeight;
        });
      
    }
  }

  

  ngOnInit(): void {
  }
}
