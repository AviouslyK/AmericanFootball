# all - compile the program if any source files have changed
all: Team.o Game.o Field.o
	g++ Team.o Game.o Field.o main.cpp -o main

# the Team.o object file needs recompiled if Team.cpp or Team.hpp changes
Team.o: Team.cpp Team.hpp
	g++ -c Team.cpp -o Team.o

# the Game.o object file needs recompiled if Game.cpp or Game.hpp changes
Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp -o Game.o

# the Field.o object file needs recompiled if Field.cpp or Field.hpp changes
Field.o: Field.cpp Field.hpp
	g++ -c Field.cpp -o Field.o

# clean - delete the compiled version of your program and
# any object files or other temporary files created during compilation.
clean:
	rm -f *.o main
