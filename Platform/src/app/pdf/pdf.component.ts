import { Component, Inject } from '@angular/core';
import { MAT_DIALOG_DATA } from '@angular/material/dialog';
import { PdfViewerModule } from 'ng2-pdf-viewer';
import { DomSanitizer, SafeResourceUrl } from '@angular/platform-browser';


@Component({
  selector: 'app-pdf',
  imports: [PdfViewerModule],
  templateUrl: './pdf.component.html',
  styleUrl: './pdf.component.css'
})
export class PDFComponent {
  pdfLabel!:string;
  safePdfUrl: SafeResourceUrl;
  path!:string;
  constructor(
    @Inject(MAT_DIALOG_DATA) public data:Array<string|(()=>void)>,
    private sanitizer: DomSanitizer
  ){
    console.log("pdf data is ", data);
    this.safePdfUrl = this.sanitizer.bypassSecurityTrustResourceUrl((data[1] as string));
    console.log('safe : ',this.safePdfUrl);   
    this.path = (data[1] as string)
    this.pdfLabel = (data[0] as string)
  }

  Close(){
    (this.data[2] as (()=>void))();
  }
}
