import { Component, input, Input, InputSignal, OnInit, Signal } from '@angular/core';

@Component({
  selector: 'app-button',
  imports: [],
  templateUrl: './button.component.html',
  styleUrl: './button.component.css'
})
export class ButtonComponent implements OnInit {


  labels = input.required<string[]>();

  functions = input.required<Function[]>();

  skewLevel = input<Number>(15);
  

  buttonHeight:Number = 0;
  ngOnInit(): void {
    this.buttonHeight = (5 / this.labels().length);    
  }


  
}
