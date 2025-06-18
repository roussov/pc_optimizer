# Compilateur et options
CC = gcc
INCLUDE = -Iinclude
SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build/bin
TARGET = $(BIN_DIR)/pc_optimizer.exe

# Fichiers sources
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Flags
CFLAGS_DEBUG = -g -Wall -Wextra $(INCLUDE)
CFLAGS_RELEASE = -O2 -Wall -Wextra $(INCLUDE)

# Choix par défaut : debug
CFLAGS = $(CFLAGS_DEBUG)

.PHONY: all debug release clean run

all: debug

debug: CFLAGS = $(CFLAGS_DEBUG)
debug: $(TARGET)

release: CFLAGS = $(CFLAGS_RELEASE)
release: $(TARGET)

# Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création des dossiers si manquants
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

# Link
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $(TARGET) -lws2_32

clean:
	-rmdir /S /Q $(OBJ_DIR) 2>nul
	-rmdir /S /Q $(BIN_DIR) 2>nul

run: $(TARGET)
	$(TARGET)
