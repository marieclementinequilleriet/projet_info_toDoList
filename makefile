CXX=/usr/bin/g++
CXXFLAGS=-std=c++11
EXE=main
OBJS=main.o calcul.OBJS

all: $(EXE)

$(EXE): $(OBJS)
        