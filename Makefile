
SRC_DIR = src
INCLUDE_DIR = include

BIN_DIR = bin
OBJ_DIR = obj

MKDIR = mkdir -p
RM = rm
CP = cp

CXX=g++

CFLAGS= -Iinclude/ -std=c++14 

SOURCES = $(wildcard src/*.cpp)

SERVER_SOURCES := $(SOURCES) main.cpp


OBJECTS=$(SOURCES:%.cpp=$(OBJ_DIR)/%.o)


SERVER_EXECUTABLE = server

all: $(SERVER_EXECUTABLE) 

rebuild: clean all

MDIR:
	$(MKDIR) bin

$(SERVER_EXECUTABLE): 
	$(CXX) $(CFLAGS) $(SERVER_SOURCES) -o server



clean:
	rm server 
	



         
