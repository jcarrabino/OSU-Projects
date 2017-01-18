#Name: John Carrabino
#Date: 8/7/2016
#Description: This is the makefile for our lab G

PROG = SearchSort
CXX = g++
CXXFLAGS = -g
CXXFLAGS += -g
CXXFLAGS += -Wall
LDFLAGS = -lboost_date_time

OBJS = main.o BubbleSort.o LinearSearch.o BinarySearch.o

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o: 
	$(CXX) $(CXXFLAGS) -c main.cpp
BubbleSort.o: BubbleSort.hpp
	$(CXX) $(CXXFLAGS) -c BubbleSort.cpp
LinearSearch.o: LinearSearch.hpp
	$(CXX) $(CXXFLAGS) -c LinearSearch.cpp
BinarySearch.o: BinarySearch.hpp
	$(CXX) $(CXXFLAGS) -c BinarySearch.cpp
clean:
	rm -f core $(PROG) $(OBJS)
