# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = g++	  # compiler to use
LINKERFLAG = -lm
FLAGS =

LIBS = 

TARGET = main.cpp
BIN = main

SRCS := $(wildcard *.cpp)
SRCS := $(filter-out $(TARGET), $(SRCS))

HDRS = $(wildcard *.h)
OBJS = $(SRCS:%.cpp=%.o)

all: $(OBJS) $(TARGET)

%.o: %.cpp
	@echo "Creating object..."
	${CC} -c $< -o $@ $(LIBS)

%: $(TARGET) $(SRCS) $(HDRS)
	@echo "Compiling.."
	$(CC) $(LINKERFLAG) $(TARGET) $(OBJS) -o $(BIN) $(LIBS)

clean:
	@echo "Cleaning up..."
	$(RM) *.o $(BIN)