
SRC_DIR = src
INCLUDE_DIR = include

BIN_DIR = bin
OBJ_DIR = obj

MKDIR = mkdir -p
RM = rm
CP = cp

CXX=g++

CFLAGS= -Iinclude/ -std=c++1y 

SOURCES = $(wildcard src/*.cpp)

SERVER_SOURCES := $(SOURCES) server.cpp
CLIENT_SOURCES := $(SOURCES) client.cpp


OBJECTS=$(SOURCES:%.cpp=$(OBJ_DIR)/%.o)


SERVER_EXECUTABLE = server
CLIENT_EXECUTABLE = client

all:  $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)

rebuild: clean all

$(SERVER_EXECUTABLE):
	$(CXX) $(CFLAGS) $(SERVER_SOURCES) -o $(BIN_DIR)/server

$(CLIENT_EXECUTABLE):
	$(CXX) $(CFLAGS) $(CLIENT_SOURCES) -o $(BIN_DIR)/client


clean:
	rm bin/*
	



         
