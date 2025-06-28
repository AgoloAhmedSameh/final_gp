import { Component, input, signal, Inject, Signal} from '@angular/core';
import { ProfileData, UserInfo } from '../models/types';
import { MAT_DIALOG_DATA } from '@angular/material/dialog';

@Component({
  selector: 'app-profile-card',
  imports: [],
  templateUrl: './profile-card.component.html',
  styleUrl: './profile-card.component.css'
})
export class ProfileCardComponent {


  constructor(@Inject(MAT_DIALOG_DATA) public data: UserInfo){}

}
