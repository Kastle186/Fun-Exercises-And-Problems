CC = gcc
CCP = g++
INCLUDE = ../../Tools
DEPS_C = $(INCLUDE)/hackerrank.c
DEPS_CPP = $(INCLUDE)/hackerrank.cpp

build-c: $(NAME).c
	$(CC) -o $(NAME) $(NAME).c $(DEPS_C) -I$(INCLUDE)

build-cpp: $(NAME).cpp
	$(CCP) -o $(NAME) $(NAME).cpp $(DEPS_CPP) -I$(INCLUDE) -std=c++20
