#Name: John Carrabino
#Date: 8/12/2016
#Description: This is the makefile for Lab H

PROG = SearchSort
CXX = g++
CXXFLAGS = -g
CXXFLAGS += -g
CXXFLAGS += -Wall
LDFLAGS = -lboost_date_time

OBJS = main.o iMergeSort.o rMergeSort.o

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o: 
	$(CXX) $(CXXFLAGS) -c main.cpp
iMergeSort.o: iMergeSort.hpp
	$(CXX) $(CXXFLAGS) -c iMergeSort.cpp
rMergeSearch.o: rMergeSearch.hpp
	$(CXX) $(CXXFLAGS) -c rMergeSearch.cpp
clean:
	rm -f core $(PROG) $(OBJS)
