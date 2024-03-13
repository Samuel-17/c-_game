# Makefile para um programa simples em C++

# Compilador
CXX = g++

# Opções de compilação
#CXXFLAGS = -std=c++11 -Wall
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
BUILD_DIR = build

# Nome do executável
TARGET = game

# Lista de arquivos-fonte
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Gera uma lista de arquivos-objeto a partir da lista de fontes
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Regra padrão: compilar todos os arquivos-objeto e criar o executável
$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(SFMLFLAGS)

# Regra para cada arquivo-objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria os diretórios se não existirem
$(shell mkdir -p $(BUILD_DIR))

# Remove todos os arquivos-objeto e o executável
clean:
	rm -rf $(BUILD_DIR)
