# QAgent 2.0

**QAgent 2.0** is an AI-powered platform designed to automate code analysis, generate test cases, and visualize code logic through flowcharts. Built for software engineers, students, and researchers, QAgent 2.0 leverages advanced large language models to streamline the process of understanding, testing, and documenting code in multiple programming languages.

---

## Project Description
QAgent 2.0 aims to bridge the gap between code and comprehension by providing:
- **Automated Code Analysis:** Instantly analyze code for logic, structure, and potential issues using state-of-the-art AI models.
- **Test Case Generation:** Automatically generate relevant test cases to improve code reliability and coverage.
- **Flowchart Visualization:** Convert code into interactive flowcharts, making it easier to understand complex logic and algorithms.
- **Multi-language Support:** Works with Python, C++, Java, and JavaScript, supporting a wide range of software projects.
- **User-friendly Web Interface:** An Angular-based frontend for seamless interaction with the platform's features.

QAgent 2.0 is ideal for:
- Software developers seeking to improve code quality and documentation
- Students and educators aiming to visualize and understand code logic
- QA engineers automating test case generation

---

## Project Overview
QAgent 2.0 is composed of three main components:
- **Backend (FastAPI):** Handles code analysis, authentication, and test case generation using large language models (LLMs).
- **FlowChartGeneration Service:** Processes code to generate flowcharts and simulation data, supporting multiple programming languages.
- **Frontend (Angular):** Provides an intuitive web interface for users to submit code, view analysis results, and interact with generated flowcharts.

The platform is designed for high performance and scalability, utilizing GPU acceleration to run advanced AI models efficiently. QAgent 2.0 is a collaborative effort, sponsored by Siemens and developed as a graduation project under expert supervision.

---

## Table of Contents
- [Project Overview](#project-overview)
- [Hardware Requirements](#hardware-requirements)
- [Setup Instructions](#setup-instructions)
- [How to Run](#how-to-run)
- [Project Structure](#project-structure)
- [Credits](#credits)

---

## Hardware Requirements
> **Note:** This project requires a machine equipped with at least **2x NVIDIA T4 GPUs** to run the large language model (Qwen2.5-Coder-7B-Instruct) efficiently. CPU-only or single-GPU setups are not supported for production use.

---

## Setup Instructions

### 1. Clone the Repository
```bash
git clone <repo-url>
cd final_gp
```

### 2. Python Environment (Backend & FlowChartGeneration)
- Ensure you have Python 3.9+ and pip installed.
- Install required Python packages (for both services):

```bash
# Backend (app/)
pip install fastapi uvicorn transformers torch

# FlowChartGeneration/
cd FlowChartGeneration
pip install -r requirements.txt
# Also install system dependencies as listed in requirements.txt
# For example:
brew install clang-format  # macOS
# or
sudo apt-get install clang-format  # Linux
cd ..
```

### 3. Frontend (Platform)
- Ensure you have Node.js (v18+) and npm installed.
- Install frontend dependencies:

```bash
cd Platform
npm install
cd ..
```

---

## How to Run

The easiest way to start all services is to run:

```bash
python runner.py
```

This will:
- Start the FastAPI backend on [http://localhost:8000](http://localhost:8000)
- Start the FlowChartGeneration service on [http://localhost:8001](http://localhost:8001)
- Start the Angular frontend on [http://localhost:4200](http://localhost:4200)

> **Note:** Make sure your machine has the required GPUs and all dependencies are installed before running.

---

## Project Structure
```
final_gp/
├── app/                  # FastAPI backend (main.py)
├── FlowChartGeneration/  # Flowchart generation service (integration2.py)
├── Platform/             # Angular frontend
├── runner.py             # Script to launch all services
└── README.md             # Project documentation
```

---

## Credits
- **Sponsored by:** Siemens
- **Supervised by:**
  - Eng. Mohamed Abdelkerim
  - Dr. Dina Khattab
  - T.A Omar Sherif
- **Developed by QAgent 2.0 Team:**
  - Ahmed Sameh Ahmed Abdelaziz
  - Abdelrahman Wael Hassan
  - Jannah Mahmoud Salah
  - Rawan Mohamed Abdelrahman
  - Amjad Feras Bakri

---

For any questions or support, please contact the QAgent 2.0 team.
