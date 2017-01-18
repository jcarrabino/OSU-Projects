#Name: John Carrabino
#Date: 8/ 7/2016
#Description: This is the makefile for our final project

PROG = RPG
CXX = g++
CXXFLAGS = -g
CXXFLAGS += -g
CXXFLAGS += -Wall
OBJS = main.o Space.o Room.o Chamber.o Secret.o Player.o

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o: 
	$(CXX) $(CXXFLAGS) -c main.cpp
Space.o: Space.hpp
	$(CXX) $(CXXFLAGS) -c Space.cpp
Room.o: Room.hpp
	$(CXX) $(CXXFLAGS) -c Room.cpp
Chamber.o: Chamber.hpp
	$(CXX) $(CXXFLAGS) -c Chamber.cpp
Secret.o: Secret.hpp
	$(CXX) $(CXXFLAGS) -c Secret.cpp
Player.o: Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp
clean:
	rm -f core $(PROG) $(OBJS)
