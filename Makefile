# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall

# Linker flags
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = main.cpp background.cpp menu.cpp Shooting.cpp movement.cpp playerOne.cpp playerTwo.cpp mine.cpp endScreen.cpp Tank.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = game

.PHONY: all debug release clean

all: release

debug: CXXFLAGS += -g
debug: $(EXEC)

release: CXXFLAGS += -O2
release: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)
