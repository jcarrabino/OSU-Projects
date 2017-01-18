#Name: John Carrabino
#Date: 8/12/2016
#Description: This is the makefile for lab Fb

PROG = labfb
CXX = g++
CXXFLAGS = -g
CXXFLAGS += -g
CXXFLAGS += -Wall
LDFLAGS = -lboost_date_time

OBJS = main.o RPN.o Stack.o

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o: 
	$(CXX) $(CXXFLAGS) -c main.cpp
RPN.o: RPN.hpp
	$(CXX) $(CXXFLAGS) -c RPN.cpp
Stack.o: Stack.hpp
	$(CXX) $(CXXFLAGS) -c  Stack.cpp
clean:
	rm -f core $(PROG) $(OBJS)
