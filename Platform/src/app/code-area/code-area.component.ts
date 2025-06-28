import { AfterViewChecked, AfterViewInit, Component, ElementRef, EventEmitter, Inject, input, OnDestroy, OnInit, Optional, Output, Renderer2, ViewChild} from '@angular/core';
import { HighlightOptions } from 'highlight.js';
import { HighlightModule, HIGHLIGHT_OPTIONS  } from 'ngx-highlightjs';
import hljs from 'highlight.js';
import { CodeThemeService } from '../Services/code-theme.service';
import Prism from 'prismjs';
import { FormBuilder, FormsModule, ReactiveFormsModule } from '@angular/forms';
import { fromEvent, Subscription } from 'rxjs';
import { CommonModule } from '@angular/common';
import { TypewriterPipe } from "../Pipes/typewriter.pipe";
import { interval } from 'rxjs';
import { take } from 'rxjs/operators';
import { ProgrammingLanguages, TypeOfTesting } from '../models/types';
import {CodemirrorModule, CodemirrorComponent} from '@ctrl/ngx-codemirror'

import 'codemirror/mode/javascript/javascript';
import 'codemirror/mode/python/python';
import 'codemirror/mode/clike/clike'; // for java and C++
import 'codemirror/mode/markdown/markdown';

import 'codemirror/addon/hint/show-hint';
import 'codemirror/addon/hint/javascript-hint';
import 'codemirror/addon/hint/show-hint';
import 'codemirror/keymap/vim';
import { MAT_DIALOG_DATA } from '@angular/material/dialog';

// import { javascript } from "@codemirror/lang-javascript";
// import { java } from "@codemirror/lang-java";
// import { python } from "@codemirror/lang-python";
// import { cpp } from "@codemirror/lang-cpp";

@Component({
  selector: 'app-code-area',
  imports: [HighlightModule, FormsModule, ReactiveFormsModule, CommonModule, CodemirrorModule],
  templateUrl: './code-area.component.html',
  styleUrl: './code-area.component.css',
  "styles": [
    "node_modules/highlight.js/styles/github-dark.css"
  ]
})


export class CodeAreaComponent implements  OnInit, AfterViewInit{

  @ViewChild('code', { static: false }) code!: ElementRef;
  @ViewChild('code') codeMirrorComponent!: CodemirrorComponent;

  @Output() valueChange = new EventEmitter<string>();  // Sends updates
  @Output() languageChange = new EventEmitter<ProgrammingLanguages>();  // Sends updates
  @Output() typeOfTestingChange = new EventEmitter<TypeOfTesting>();  // Sends updates

 
  forViewOnly = input(true);
  inputCode = input("");
  playAnimation = input(true);

  codeString:string = "";
  options!:any;
 

  LangHighliter()
  {
    console.log('the selected language is ', this.selectedLanguage);
    
    if(this.selectedLanguage == ProgrammingLanguages.CPP)
      this.options.mode = 'text/x-c++src';
    else if(this.selectedLanguage == ProgrammingLanguages.Java)
      this.options.mode = 'text/x-java';
    else if(this.selectedLanguage == ProgrammingLanguages.JavaScript)
      this.options.mode = 'text/javascript';
    else
      this.options.mode = 'text/x-python';
  }


  selectedLanguage:ProgrammingLanguages|undefined = ProgrammingLanguages.Python;
  selectedTestingType:TypeOfTesting|undefined = TypeOfTesting.Integration;

  constructor(

    
    // @Inject(CodeThemeService) private syntaxProvider:CodeThemeService,
    private renderer: Renderer2,
    @Inject(MAT_DIALOG_DATA) @Optional() private data: any
  )
  {
    console.log("=============================================", this.inputCode());

    console.log("data is :", data);
    // console.log("the given code isssssssss:", this.inputCode());
    
    // this.codeString = this.inputCode();
    if(this.data != null)
    {
      
      // console.log('selecteeeeed!',this.data['selectedLanguage']);
      this.codeString = this.data['code'];
      this.selectedLanguage = this.data['selectedLanguage'];
      // console.log("this is the codeString: ", this.codeString);
    }

    // console.log(this.forViewOnly());
    // console.log(this.inputCode());
    // console.log(this.codeString);
    // console.log(this.options);
    

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
  getLanguage(lang: string): ProgrammingLanguages | undefined {
    return {
      "python": ProgrammingLanguages.Python,
      "java": ProgrammingLanguages.Java,
      "c++": ProgrammingLanguages.CPP,
      "javascript": ProgrammingLanguages.JavaScript
    }[lang];
  }
  getTestingType(lang: string): TypeOfTesting | undefined {
    return {
      "integration": TypeOfTesting.Integration,
      "unit": TypeOfTesting.Unit,
    }[lang];
  }

  
  onLanguageSelectionChange(event: Event)
  {
    const selectElement = event.target as HTMLSelectElement;
    this.selectedLanguage = this.getLanguage(selectElement.value);
    this.languageChange.emit(this.selectedLanguage);
    this.LangHighliter()
  }
  onTestingSelectionChange(event: Event)
  {
    const selectElement = event.target as HTMLSelectElement;
    this.selectedTestingType = this.getTestingType(selectElement.value);
    this.typeOfTestingChange.emit(this.selectedTestingType);
  }

  SaveCode(updatedValue: string)
  {
    if(!this.forViewOnly())
    {
      localStorage.setItem('codeEditorContent', updatedValue);
      this.valueChange.emit(updatedValue);
    }
  }

  ngOnInit(): void {

    if(this.playAnimation())
    {
      this.animateText();
    }
    else if(this.forViewOnly())
    {
      this.codeString = this.inputCode();
    }
    else
    {
      this.codeString = localStorage.getItem('codeEditorContent') || '';
      this.valueChange.emit(this.codeString);
    }

  }

  animateText() {
    
      // let temp: string = this.inputCode();
      // this.codeString = '';
  
      // interval(1).pipe(take(temp.length)).subscribe(index => {
      //   this.codeString += temp[index];
      //   const container = this.code.nativeElement;
      //   container.scrollTop = container.scrollHeight;
      // });

      this.simulateTypingEffect();
      // this.codeString = temp;
  }

  simulateTypingEffect() {
    let toBeAnimatedString = this.codeString;

    let speed = (this.codeString.length >= 50 ? 1 : 100);

    this.codeString = '';

    interval(speed)
      .pipe(take(toBeAnimatedString.length))
      .subscribe(index => {
        this.codeString += toBeAnimatedString[index]; // Append character
        this.updateCodeMirror();
      });
  }

  updateCodeMirror() {
    if (this.codeMirrorComponent?.codeMirror) {
      const cm = this.codeMirrorComponent.codeMirror;
      cm.setValue(this.codeString); // Update the editor
      cm.scrollTo(0, cm.getScrollInfo().height); // Scroll to bottom
    }
  }
  
  ngAfterViewInit(): void {

    this.options = {
      lineNumbers: true,         // Show line numbers
      mode: 'text/x-c++src',     // Language mode (C++)
      theme: 'material',         // Theme (Choose any)
      tabSize: 4,                // Number of spaces for a tab
      indentWithTabs: true,      // Use tabs instead of spaces
      smartIndent: true,         // Auto-indent new lines
      // lineWrapping: true,        // Wrap long lines
      // autofocus: true,          // Auto-focus on editor load
      // matchBrackets: true,      // Highlight matching brackets
      // autoCloseBrackets: true,  // Automatically close brackets `()`, `{}`, `[]`
      // styleActiveLine: true,    // Highlight the current line
      // gutters: ['CodeMirror-linenumbers', 'breakpoints'], // Custom gutters
      // extraKeys: { 'Ctrl-Space': 'autocomplete' }, // Enable autocomplete with Ctrl+Space
      // hintOptions: { completeSingle: true },     // Don't auto-select first suggestion
      // readonly: true // (this.forViewOnly()?true:false)
      // // highlightSelectionMatches: { showToken: /\w/, annotateScrollbar: true }, // Highlight matching words
    };
    this.LangHighliter()
    
  }
}

