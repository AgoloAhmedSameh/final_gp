import { Injectable } from '@angular/core';
import { FullReportData, popupData, TextStyles, UserInfo } from '../models/types';
import { LoadingComponent } from '../loading/loading.component';

@Injectable({
  providedIn: 'root'
})
export class GlobalsService {
  currentLoggedInUser:UserInfo = {
    email: "",
    first_name: "",
    last_name: "",
    phone_number: "",
    position: ""
  }

  loadingData:popupData = {
    message: null,
    element: LoadingComponent,
    buttonNames: [],
    buttonFunctions: [],
    happyState: true,
    defaultButtons: false,
    textStyle: TextStyles.normal,
    code: null,
    language: null
  };

  fullReport:FullReportData | null = null;

  
  constructor() { }


}
