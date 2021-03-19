CC = gcc
CC_FLAGS = -Wall
EXE = anagPalindDetection
P1V1 = partie1_v1
P1V2 = partie1_v2

all: run

partie1_v1:
	$(CC) $(CC_FLAGS) src/partie1_v1/*.c -o $(P1V1)
	./$(P1V1)

partie1_v2:
	$(CC) $(CC_FLAGS) src/partie1_v2/*.c -o $(P1V2)
	./$(P1V2)

run: compile
	./$(EXE)

compile:
	$(CC) $(CC_FLAGS) src/*.c -o $(EXE)

clean:
	rm -rf $(EXE) $(P1V1) $(P1V2)