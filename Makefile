
CXX = g++
CXXFLAGS += -std=c++11 -Wall
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
BUILD_DIR = build

TARGET = $(BUILD_DIR)/game


SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Regra padrão: compilar todos os arquivos-objeto e criar o executável
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(SFMLFLAGS)

# Regra para cada arquivo-objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove todos os arquivos-objeto e o executável
clean:
	rm -rf $(BUILD_DIR)
