# It is likely that you were compiling with something to the effect of:
#
#    g++ -std=c++11 -o main *.cpp
#
# where as this Makefile is a two step process:
#
#    g++ -std=c++11 -o obj/xyz.o xyz.cpp  # For each .cpp
#    g++ -o main obj/*.o
#
# The first process will recompile *every* compilation unit (source file) with
#  each compilation, as the project grows this may take a significant amount of
#  time. The second process compiles each file once, stores the object file
#  (output) and then links all of these together in the second command to form
#  the binary
# If you modify *only* encryption.cpp and run `make` again, *only*
#  encryption.cpp will be recompiled to obj/encryption.o, and not all three of
#  them

CXX := clang++
CFLAGS := -std=c++11
# One of our targets (end goals) in the compilation process is going to be to
#  create all the object files (see below for more details on this), to have
#  that as a target, we need a list of all the object files before they exist,
#  as there will be one per .cpp file, we can just do a path substitution
OBJS := $(patsubst %.cpp,obj/%.o,$(wildcard *.cpp))
BIN := main

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $^ -o $@

obj/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@ $(IFLAGS)

clean:
	$(RM) $(BIN) $(OBJS)
