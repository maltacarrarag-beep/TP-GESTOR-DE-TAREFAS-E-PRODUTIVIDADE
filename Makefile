CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -I include

TARGET   = agilemanager

SRCS     = src/main.cpp \
           src/AgileManager.cpp \
           src/Coluna.cpp \
           src/Quadro.cpp \
           src/Tarefa.cpp \
           src/Membro.cpp \
           src/Metricas.cpp

OBJS     = $(patsubst src/%.cpp, build/%.o, $(SRCS))

# Regra padrão: compila tudo 
all: build $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra genérica: src/*.cpp → build/*.o 
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria a pasta build/ se não existir (ela sumirá depois do make clean)
build:
	mkdir -p build

# Limpa os arquivos gerados 
clean:
	rm -rf build $(TARGET)

# Recompila do zero 
rebuild: clean all

# Evita conflito com arquivos de mesmo nome 
.PHONY: all clean rebuild build