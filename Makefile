CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/game

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(BIN_DIR)/*.o $(EXECUTABLE)