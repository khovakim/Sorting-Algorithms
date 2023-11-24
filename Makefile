# Makefile for C++ project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source directory
SRC_DIR = source

BIN     = .bin

# Object directory
OBJ_DIR = $(BIN)/obj

# Include directory
INCLUDE_DIR = includes

# Source files
SRC = $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Executable name
TARGET = sortingAlgorthms

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
	mv $(TARGET) $(BIN)/

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Run rule
run:
	@$(BIN)/$(TARGET)

# Clean rule
clean:
	rm -rf $(BIN)

re: clean all

PHONY: all re clean run 
