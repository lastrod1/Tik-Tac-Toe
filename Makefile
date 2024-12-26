APP_NAME = Tic-Tac-Toe
BUILD_DIR = ./bin
SRC_DIR = ./src
IMPL_DIR = $(SRC_DIR)/Implementation
HEADER_DIR = $(SRC_DIR)/Headers
VENDOR_DIR = $(SRC_DIR)/vendors

# Source files
CPP_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(IMPL_DIR)/*.cpp)

# Object files
OBJ_FILES = $(patsubst %.cpp, %.o, $(CPP_FILES))

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -O3 -I$(HEADER_DIR) -I$(VENDOR_DIR)/GLFW -I$(VENDOR_DIR)/GLEW
LDFLAGS = -L$(VENDOR_DIR)/GLFW/lib -lglfw3 -L$(VENDOR_DIR)/GLEW/lib -lGLEW \
          -framework Cocoa -framework OpenGL -framework IOKit

# Build target
$(BUILD_DIR)/$(APP_NAME): $(OBJ_FILES)
	mkdir -p $(BUILD_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Rule for compiling object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(OBJ_FILES)
