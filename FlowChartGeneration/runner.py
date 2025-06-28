from Enums import ProgrammingLanguages
from PythonScraper import PythonScraper
from CompiledLanguagesScraper import CompiledLanguagesScraper

import multiprocessing

if __name__ == "__main__":
    multiprocessing.freeze_support()  # Required for Windows

    with open('CPPExamples/cpp_example3.cpp','r') as f: CompiledLanguagesScraper(f.read(), programming_language=ProgrammingLanguages.CPP)
    # with open('PythonExamples\python_example3.py','r') as f: PythonScraper(f.read(), get_frames=False, output_format='TB')