# Makefile para um programa simples em C++

# Compilador
CXX = g++
CXXFLAGS += -std=c++11 -Wall
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
BUILD_DIR = build

# Nome do executável
TARGET = $(BUILD_DIR)/game

# Encontra todos os arquivos .cpp em SRC_DIR e subdiretórios
SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')
# Gera uma lista de arquivos-objeto a partir da lista de fontes, preservando a estrutura de diretórios em BUILD_DIR
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
