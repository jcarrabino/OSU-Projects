PROG = reverse
CXX = g++
CXXFLAGS = -g
CXXFLAGS += -g
CXXFLAGS += -Wall
LDFLAGS = -lboost_date_time

OBJS = main.o Reverse.o

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o: 
	$(CXX) $(CXXFLAGS) -c main.cpp
Reverse.o: Reverse.h
	$(CXX) $(CXXFLAGS) -c Reverse.cpp
clean:
	rm -f core $(PROG) $(OBJS)
