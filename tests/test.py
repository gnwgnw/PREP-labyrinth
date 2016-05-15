import sys
import datetime
import subprocess
from time import time
from os import system, path


# --- Help ---------------------------------------------------------

class Tee(object):
    def __init__(self, *files):
        self.files = files

    def write(self, obj):
        for f in self.files:
            f.write(obj)
            f.flush() # If you want the output to be visible immediately

    def flush(self) :
        for f in self.files:
            f.flush()

def measureTime(func):
	if func is None:
		return None

	beginTime = time()
	func()
	endTime = time()

	return round((endTime - beginTime), 3)

# --- Constants ---------------------------------------------------

GENERATOR_FILE = "maze.py"
EXEC_FILE = "./a.out"

COMPILING = "g++ ../*.cpp -std=c++11 -o " + EXEC_FILE

if __name__ == "__main__":
	log = open("test log.log", 'a')
	log.write(str(datetime.datetime.now()) + " " + str(sys.argv))

	sys.stdout = Tee(sys.stdout, log)

	width = 7
	height = 7
	isCompile  = True
	isGenerate = True

	# --- Reading args ---------------------------------------------

	args = sys.argv[1:]

	isCompile = "-c" in args
	if isCompile:
		args.remove("-c")

	isGenerate = "-g" in args
	if isGenerate:
		args.remove("-g")

	if len(args) >= 1:
		height = int(args[0])
	if len(args) >= 2:
		width = int(args[1])
	else:
		width = height

	# --- Preparing ------------------------------------------------

	testFileName = str(height) + "x" + str(width) + ".txt"

	if not path.isfile(testFileName):
		isGenerate = True

	if not path.isfile(EXEC_FILE):
		isCompile = True

	# --- Running --------------------------------------------------

	if isCompile:
		print("\nCompiling... ")
		print("Done:", measureTime(lambda: system(COMPILING)), "s.")
	
	if isGenerate:
		print("\nGenerating...")
		print("Done:", measureTime(lambda: system("python3 " + GENERATOR_FILE + " " + str(height) + " " + str(width) + " > " + testFileName)), "s.")

	print("\nExecuting...")
	subprocess.check_output([EXEC_FILE, testFileName])
	time = measureTime(lambda: print(subprocess.check_output([EXEC_FILE, testFileName])))
	print("Done:", time, "ms")

	log.write("\n\n")
	# log.close()
