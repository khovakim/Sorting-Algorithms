# Colors
_GREY=	\033[1;30m
_RED=	\033[1;31m
_GREEN=	\033[1;32m
_YELLOW=\033[1;33m
_BLUE=	\033[1;34m
_PURPLE=\033[1;35m
_CYAN=	\033[1;36m
_WHITE=	\033[1;37m
_NC=	\033[0m

# Colored messages
SUCCESS=$(GREEN)SUCCESS$(NC)
COMPILING=$(_BLUE)COMPILING$(NC)

# Makefile for C++ project

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g3 -fsanitize=address

# Timer with command in linux
TIMER = time

# Source directory
SRC_DIR = source

BIN     = .bin

# Object directory
OBJ_DIR = $(BIN)/obj

# Include directory
INCDIR = includes
INC    = $(shell find $(INCDIR) -type d)
IFLAGS = $(foreach dir, $(INC), -I $(dir))

# Source files
SRC := $(wildcard $(SRC_DIR)/**/*.cpp)
SRC += $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Executable name
TARGET = sortingAlgorthms

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@mv $(TARGET) $(BIN)/
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(_GREEN)DONE$(_WHITE)"

# Run rule
run:
	@$(BIN)/$(TARGET)

runTimer:
	@$(TIMER) $(BIN)/$(TARGET)

# Clean rule
clean:
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -rf $(BIN)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

re: clean all

# Show macro details
show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CXXFLAGS :\n$(_YELLOW)$(CXXFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) $(_WHITE)"

PHONY: all re clean run runTimer show
