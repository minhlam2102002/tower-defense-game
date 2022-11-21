# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = g++
LINKERFLAG = -lm
FLAGS =

LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

TARGET = main.cpp
BIN = main

# SRCS := $(wildcard *.cpp)
# SRCS := $(filter-out $(TARGET), $(SRCS))

SRCS = Intro.cpp BaseObject.cpp App.cpp Game.cpp Bullet.cpp Machine.cpp Monster.cpp

HDRS = $(wildcard *.h)
OBJS = $(SRCS:%.cpp=%.o)

all: $(OBJS) $(BIN) $(TARGET) $(SRCS) $(HDRS)

%.o: %.cpp
	@echo "Creating object..."
	${CC} -c $< -o $@ $(LIBS)

$(BIN): $(TARGET) $(SRCS) $(HDRS)
	@echo "Compiling.."
	$(CC) $(LINKERFLAG) $(TARGET) $(OBJS) -o $(BIN) $(LIBS)

clean:
	@echo "Cleaning up..."
	$(RM) *.o $(BIN)