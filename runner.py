import subprocess
import time
import os

# Function to run a command in a new terminal window (cross-platform)
def run_in_terminal(command):
    if os.name == 'nt':  # Windows
        subprocess.Popen(f'start cmd /k "{command}"', shell=True)
    else:  # macOS / Linux
        subprocess.Popen(f'gnome-terminal -- bash -c "{command}; exec bash"', shell=True)

# Start FastAPI app on port 8000
run_in_terminal("uvicorn app.main:app --port 8000 --reload")
time.sleep(2)  # Small delay to avoid overlaps

# Change to FlowChartGeneration directory and start FastAPI app on port 8001
run_in_terminal("cd FlowChartGeneration && uvicorn integration2:app --port 8001 --reload")
time.sleep(2)

# Change to Platform directory and start npm
run_in_terminal("cd Platform && npm start")
