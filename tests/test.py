from os import system, path
import sys

GENERATOR_FILE = "maze.py"
EXEC_FILE = "./a.out"

COMPILING = "g++ ../*.cpp -std=c++11 -o " + EXEC_FILE

if __name__ == "__main__":
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
		print("Compiling... ")
		system(COMPILING)
		print("Done.")
	
	if isGenerate:
		system("python3 " + GENERATOR_FILE + " " + str(height) + " " + str(width) + " > " + testFileName)

	print()
	system(EXEC_FILE + " " + testFileName)
