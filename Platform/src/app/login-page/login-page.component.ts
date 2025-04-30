import { Component, ElementRef, Inject, input } from '@angular/core';
import { Router } from '@angular/router';
import { FormsModule } from '@angular/forms';
import { MatDialog, MatDialogModule } from '@angular/material/dialog';
import { PopUpComponent } from '../pop-up/pop-up.component';
import { popupData, TextStyles, UserResponse } from '../models/types';
import { ApiService } from '../Services/api-service.service';
import { GlobalsService } from '../Services/globals.service';

@Component({
  selector: 'app-login-page',
  imports: [FormsModule, MatDialogModule],
  templateUrl: './login-page.component.html',
  styleUrl: './login-page.component.css'
})
export class LoginPageComponent {
  dummyMail: string = 'user';
  dummyPassword: string = '123';

  username: string = '';
  password: string = '';



  constructor(
    private router: Router,
    private dialogRef: MatDialog,
    @Inject(ApiService) private api: ApiService,
    @Inject(GlobalsService) private globals: GlobalsService
  ) {

  }

  onClick() {
    console.log(this.username);

    let dialog = this.dialogRef.open(PopUpComponent, {
      data: this.globals.loadingData,
      panelClass: 'Qdialog'
    })

    this.api.authenticateUser({
      email: this.username,
      password: this.password
    }).subscribe({
      next: (response: UserResponse) => {
        dialog.close()
        if (response.user_info && response.available) {
          this.globals.currentLoggedInUser = response.user_info;
          this.router.navigateByUrl('/home-page');
          this.OpenDialog(true);
        }
        else
        {
          this.OpenDialog(false);
        }
      }, error: () => {
        dialog.close()
        this.OpenDialog(false);
      }
    })


    // if (this.username == this.dummyMail && this.password == this.dummyPassword) {
    //   this.OpenDialog(true);
    //   this.router.navigateByUrl('/home-page');
    // }
    // else {
    //   this.OpenDialog(false);
    // }
  }

  OpenDialog(sucess: boolean) {

    let message = "";


    if (sucess) {
      message = "Wellcome!";
    }
    else {
      message = "Unauthorized!";
    }

    let loginData: popupData = {
      message: message,
      element: null,
      buttonNames: [],
      buttonFunctions: [],
      happyState: (sucess ? true : false),
      defaultButtons: true,
      textStyle: (sucess ? TextStyles.green : TextStyles.red),
      code: null,
      language: null
    }

    console.log(loginData);

    this.dialogRef.open(PopUpComponent, {
      data: loginData,
      panelClass: 'Qdialog'
    });
  }

}
