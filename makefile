CFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

C = City
M = Map
P = program3

$(P): $(C).o $(M).o $(P).o
	g++ $(CFLAGS) -o $(P) $(C).o $(M).o $(P).o

$(P).o: $(P).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(C).o: $(C).cpp $(C).h
	g++ $(CFLAGS) -c $(C).cpp -o $(C).o

$(M).o: $(M).cpp $(M).h
	g++ $(CFLAGS) -c $(M).cpp -o $(M).o

all: $(P)

run: all
	./$(P)

checkmem: all
	valgrind ./$(P)

clean:
	rm -f $(D).o
	rm -f $(M).o
	rm -f $(P).o
	rm -f $(P)
	rm -f $(P).exe
