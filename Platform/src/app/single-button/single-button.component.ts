import { Component, input, OnInit } from '@angular/core';

@Component({
  selector: 'app-single-button',
  imports: [],
  templateUrl: './single-button.component.html',
  styleUrl: './single-button.component.css'
})
export class SingleButtonComponent implements OnInit {
    label = input.required<string>();
  
    function = input.required<Function>();
  
    skewLevel = input<Number>(15);

 

    ngOnInit(): void {
      
    }
}
