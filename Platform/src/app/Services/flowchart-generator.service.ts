import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Observable } from 'rxjs';
import { map } from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})
export class FlowchartGeneratorService {
  private apiUrl = 'http://localhost:5000/generate-image';

  constructor(private http: HttpClient) {}

  generateImage(code: string): Observable<string> {
    const headers = new HttpHeaders({ 'Content-Type': 'application/json' });

    return this.http.post<{ image_url: string }>(
      this.apiUrl, 
      JSON.stringify({ code }), // Ensure JSON format
      { headers } // Pass headers
    ).pipe(map(response => response.image_url));
  }
}
