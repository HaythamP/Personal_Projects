# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98 -g

# Source files
SRCS = main.cpp Arena.cpp Tile.cpp BoobyTrappedTile.cpp LethalTile.cpp EndTile.cpp Player.cpp Pacifist.cpp Villain.cpp Threat.cpp TileException.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run target
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run
