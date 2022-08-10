# MakeFile
# @matiaslanzi
# Great MakeFile and SDL setup video https://www.youtube.com/watch?v=Dyz9O7s7B8w

# Define some variables
OBJ_NAME = MicroEngine
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
BUILD_DIR = build/debug

CC = clang++
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g
LINKER_FLAGS = -lsdl2
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib

# Compile command
all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME).app

clean:
	rm -f $(BUILD_DIR)/$(OBJ_NAME).app
	rm -fR $(BUILD_DIR)/$(OBJ_NAME).app.dSYM
	