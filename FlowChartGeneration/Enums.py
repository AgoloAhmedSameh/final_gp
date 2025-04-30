from enum import Enum

class LineType(Enum):
	Procedural = -1
	Loop = 0
	Condition = 1
	TerminatorOfLoop = 2
	TerminatorOfSwitch = 3
	TerminatorOfProgram = 4
	SwitchStatement = 5

class ProgrammingLanguages(Enum):
	Python = 'pyhton'
	CPP = 'cpp'
	JAVA = 'java'
	JavaScript = 'javascript'

class TypeOfTesting(Enum):
	Unit = "unit"
	Integration = "integration"