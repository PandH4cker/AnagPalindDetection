CC = gcc
CC_FLAGS = -Wall
EXE = anagPalindDetection

P1V1 = partie1_v1
P1V2 = partie1_v2
P1V3 = partie1_v3


all: run

partie1_v1:
	$(CC) $(CC_FLAGS) src/partie1_v1.d/*.c -o $(P1V1)
	./$(P1V1)

partie1_v2:
	$(CC) $(CC_FLAGS) src/partie1_v2.d/*.c -o $(P1V2)
	./$(P1V2)

partie1_v3:
	$(CC) $(CC_FLAGS) src/partie1_v3.d/*.c -o $(P1V3)
	./$(P1V3)

run: compile
	./$(EXE)

compile:
	$(CC) $(CC_FLAGS) src/*.c -o $(EXE)

clean:
	rm -rf $(EXE) $(P1V1) $(P1V2) $(P1V3)