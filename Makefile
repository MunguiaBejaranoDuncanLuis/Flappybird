# Variables
CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11
LDFLAGS = -lncurses
SRC = src
BIN = bin
INCLUDE = include

# Objetos
OBJECTS = $(SRC)/FlappyBird.o $(SRC)/main.o

# Ejecutable
EXECUTABLE = $(BIN)/Flappy_Bird

# Reglas
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(SRC)/FlappyBird.o: $(SRC)/FlappyBird.cpp $(INCLUDE)/FlappyBird.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(SRC)/main.o: $(SRC)/main.cpp $(INCLUDE)/FlappyBird.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(SRC)/*.o $(BIN)/Flappy_Bird

run: all
	./$(EXECUTABLE)

.PHONY: all clean run