from fastapi import FastAPI, HTTPException, Query
from fastapi.staticfiles import StaticFiles
from pydantic import BaseModel
from typing import List, Optional
from Enums import ProgrammingLanguages
from CompiledLanguagesScraper import CompiledLanguagesScraper
from PythonScraper import PythonScraper
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import StreamingResponse
from pathlib import Path
import zipfile
import io

import os

app = FastAPI()
API_STORAGE_PATH = 'api_storage'
if not os.path.exists(API_STORAGE_PATH):
    os.makedirs(API_STORAGE_PATH)
app.mount("/static", StaticFiles(directory=API_STORAGE_PATH), name="static")

# Allow CORS for frontend (Angular on port 4200)
app.add_middleware(
    CORSMiddleware,
    allow_origins=["http://localhost:4200"],  # Allow frontend URL
    # allow_origins=["*"], 
    allow_credentials=True,
    allow_methods=["*"],  # Allow all HTTP methods (GET, POST, etc.)
    allow_headers=["*"],  # Allow all headers
)

class FlowchartRequest(BaseModel):
    code:str
    language:str
    get_frames:bool
    include_macros_in_cpp:Optional[bool] = False
    required_format: Optional[str] = None

class FlowchartResponse(BaseModel):
    flow_chart_TB:str
    flow_chart_LR:str
    simulation_path:Optional[List[List[List]]] = [] # List of branches each is List of frames each frame is one or 2 images based on the given format


@app.get("/download-folder/")
def download_folder(include_frames: bool = Query(False)):
    folder_path = Path(os.path.join(API_STORAGE_PATH, 'graph/'))  # Update this path

    if not folder_path.exists() or not folder_path.is_dir():
        return {"error": "Folder not found"}

    print("include_frames=", include_frames)
    # Create a zip file in memory
    zip_io = io.BytesIO()
    with zipfile.ZipFile(zip_io, mode="w", compression=zipfile.ZIP_DEFLATED) as zip_file:
        for file_path in folder_path.rglob("*"):
            print(10 * '===', str(file_path))
            if file_path.is_file() and not(not include_frames and 'frames' in str(file_path)):
                zip_file.write(file_path, arcname=file_path.relative_to(folder_path))
    zip_io.seek(0)

    return StreamingResponse(
        zip_io,
        media_type="application/x-zip-compressed",
        headers={"Content-Disposition": "attachment; filename=Graph.zip"}
    )

# @app.get("/api/get_simulations")
# async def create_file():
#     simulations_dir = os.path.join("api_storage", 'simulations')
    
#     # Ensure the folder exists
#     os.makedirs(simulations_dir, exist_ok=True)

#     simulations = []

#     try:
#         for frames_set in os.listdir(simulations_dir):
#             simulations.append({frames_set: []})
#             frames_set_dir = os.path.join(simulations_dir, frames_set)
#             for frame in os.listdir(frames_set_dir):
#                 full_path = os.path.join(frames_set_dir, frame)
#                 data = []
#                 for image in os.listdir(full_path):
#                     data.append(os.path.join(full_path, image))
#                 simulations[-1][frames_set].append(data)

#         for element in simulations:
#             print(element)
#     except Exception as e:
#         print("Error on creating File '{file_name}' in '{folder_name}'!")
#         return {"error": str(e)}


@app.post('/api/get_flowchart', response_model=FlowchartResponse)
def GetFlowchart(request: FlowchartRequest):
    language = ProgrammingLanguages.Python

    # print(jsonify(request))
    print(request)
    print(request.code)

    
    # pdb.set_trace()
 
    if request.language == 'c++':
        language = ProgrammingLanguages.CPP
    elif request.language == "java":
        language = ProgrammingLanguages.JAVA
    elif request.language == "javascript":
        language = ProgrammingLanguages.JavaScript

    try:
        # export_path = "http://localhost:8001/static/"
        export_path = os.path.join(API_STORAGE_PATH, 'graph/')


        os.makedirs(export_path, exist_ok=True)


        simulations = []


        scraper = None    

        if request.language != 'python':
            scraper = CompiledLanguagesScraper(
                code=request.code, 
                programming_language=language, 
                export_path=export_path, 
                include_macros=request.include_macros_in_cpp,
                get_frames = True if request.get_frames else False,
                output_format=request.required_format
            )
        else:
            scraper = PythonScraper(code=request.code, export_path="", get_frames = True if request.get_frames else False, output_format=request.required_format)

        # pdb.set_trace()

        simulation_path = scraper.simulation_paths or []

        for frames_set in simulation_path:
            for frame in frames_set:
                frame[0] = frame[0].replace('api_storage', 'http://localhost:8001/static')

        return FlowchartResponse(
            flow_chart_TB=f"http://localhost:8001/static/graph/flow-chart-TB.png",
            flow_chart_LR=f"http://localhost:8001/static/graph/flow-chart-LR.png",
            simulation_path = simulation_path
        )

    except Exception as e:
        print(f"❌ Error: {str(e)}")
        raise HTTPException(status_code=500, detail=f"Internal Server Error: {str(e)}")
