import { Component, ElementRef } from "@angular/core";
import { LoadingComponent } from "../loading/loading.component";

export type ProfileData = {
    firstName:string | null;
    lastName:string | null;
    email:string | null;
    phoneNumber:string | null;
    jobTitle:string | null;
}

export type popupData = {

    message:string | null;
    element: HTMLElement | Element | ElementRef | LoadingComponent | null;
    buttonNames:string[];
    buttonFunctions:(() => void)[] | null;
    happyState:boolean | null;
    defaultButtons:boolean | null;
    textStyle:TextStyles | null;
    code:String | null;
    language:ProgrammingLanguages | null;
}


export type ColorPair = {
    background: string;
    font: string;
};

export enum TextStyles {
    normal,
    green,
    red,
}

export enum ProgrammingLanguages {
    Python = "python",
    CPP = "c++",
    Java = "java",
    JavaScript = "javascript"
}

export enum TypeOfTesting
{
    Integration = 'integration',
    Unit = 'unit'
}

// Represents a user's information
export interface UserInfo {
    first_name: string;
    last_name: string;
    email: string;
    phone_number: string;
    position: string;
}

// Request model for user authentication
export interface UserRequest {
    email: string;
    password: string;
}

// Response model for user authentication
export interface UserResponse {
    available: boolean;
    user_info?: UserInfo;
}

// Represents a code request for analysis
export interface CodeRequest {
    code: string;
    description: string;
    language: string;  // Can be an enum if needed
    dependencies: Array<string>;
}

// Response model for code analysis
export interface CodeResponse {
    syntax_flag: boolean;
    matching_flag: boolean;
    feedback_message: string;
    enhanced_code: string;
}

// Represents a request to test the code
export interface CodeTestRequest {
    code: string;
    description: string;
    language: string;
    type_of_testing: string; // Can be an enum
}

// Response model for code testing
export interface CodeTestResponse {
    asserts: Array<string>;
    faild_asserts: Array<string>;
    description: string;
    coverage: number;
    correctness: number;
}


// Represents a request to generate a flowchart
export interface FlowchartRequest {
    code: string;
    language: ProgrammingLanguages;
    get_frames: boolean;
    include_macros_in_cpp?: boolean;
    required_format?: string | null;
}

// Response model for flowchart generation
export interface FlowchartResponse {
    flow_chart_TB: string; // path to the file
    flow_chart_LR: string; // path to the 
    simulation_path:Array<Array<Array<any>>> | undefined | null
}

export interface FullReportData {
    response:CodeTestResponse;
    feedback_message:string;
    code:string;
    corrected_code:string;
}
