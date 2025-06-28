import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { UserResponse, CodeRequest, CodeResponse, CodeTestRequest, CodeTestResponse, FlowchartRequest, FlowchartResponse, UserRequest } from '../models/types';

const headers = new HttpHeaders({ 'Content-Type': 'application/json' });


@Injectable({
  providedIn: 'root'
})
export class ApiService {

  private baseUrl = 'http://localhost:8000/api'; // Your FastAPI backend URL
  private baseUrl2 = 'http://localhost:8001/api'; // Your FastAPI backend URL

  constructor(private http: HttpClient) {}

  // Get users
  getUsers(): Observable<UserResponse[]> {
    return this.http.get<UserResponse[]>(`${this.baseUrl}/GetUsers`);
  }

  authenticateUser(request: UserRequest): Observable<UserResponse> {
    return this.http.post<UserResponse>(`${this.baseUrl}/authenticate`, request, {headers});
  }

  analyzeCode(request: CodeRequest): Observable<CodeResponse> {
    return this.http.post<CodeResponse>(`${this.baseUrl}/analyze_code`, request, {headers});
  }

  testCode(request: CodeTestRequest): Observable<CodeTestResponse> {
    return this.http.post<CodeTestResponse>(`${this.baseUrl}/test_code`, request, {headers});
  }

  downloadFolder(includeFrames: boolean) {
    return this.http.get('http://localhost:8001/download-folder/', {
      responseType: 'blob',
      params: { include_frames: includeFrames }
    });
  }

  getFlowchart(request: FlowchartRequest): Observable<FlowchartResponse> {
    return this.http.post<FlowchartResponse>(`${this.baseUrl2}/get_flowchart`, request, {headers});
  }
  // testCode(request: CodeTestRequest): Observable<Blob> {
  //   return this.http.post(`${this.baseUrl}/test_code`, request, {
  //     headers,
  //     responseType: 'blob'// Ensure the response is treated as a Blob
  //   });
  // }
  

}
