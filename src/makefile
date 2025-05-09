
# OLD Makefile
# run:
# 	gcc -o main ADT/Mesin-Char/charmachine.c ADT/Time/datetime.c ADT/Time/adttime.c ADT/Mesin-Kata/wordmachine.c ADT/pcolor/pcolor.c ADT/boolean.h ADT/ListStatik/liststatik.c ADT/Matrix/matrix.c ADT/Profil/profil.c ADT/User/user.c ADT/Kicau/tweet.c ADT/Balasan/reply.c ADT/Balasan/tree.c ADT/PrioQueue/prioqueueReq.c ADT/Graf/graf.c ADT/Teman/teman.c ADT/MaxHeap/maxheap.c ADT/Draf/draf.c ADT/muat/muat.c ADT/simpan/simpan.c ADT/Inisialisasi/inisialisasi.c ADT/Database/db.c ADT/Perintah/perintah.c ADT/Utas/utas.c main.c
# 	./main

# New Makefile
# Compiler and flags
CC = gcc
CFLAGS = -g -Wall

# Source files and directories
SRCS = $(shell find . -name "*.c")
OBJS = $(patsubst ./%,build/%,$(SRCS:.c=.o))

# Target executable
TARGET = build/main

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	@echo "Linking object files..."
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files into .o files
build/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	@echo "Cleaning up..."
	rm -rf build

# Run target
run: $(TARGET)
	@echo "Running the project..."
	@./$(TARGET)
