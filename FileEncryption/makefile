PROG = CryptKeeper
CXX = g++
CXXFLAGS = -g
CXXFLAGS += -g
CXXFLAGS += -Wall
LDFLAGS = -lboost_date_time

OBJS = main.o Transformer.o Copy.o Encryption.o ToUpper.o OrderedOutput.o

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o: 
	$(CXX) $(CXXFLAGS) -c main.cpp
Transformer.o: Transformer.h
	$(CXX) $(CXXFLAGS) -c Transformer.cpp
Copy.o: Copy.h
	$(CXX) $(CXXFLAGS) -c Copy.cpp
Encryption.o: Encryption.h
	$(CXX) $(CXXFLAGS) -c Encryption.cpp
ToUpper.o: ToUpper.h
	$(CXX) $(CXXFLAGS) -c ToUpper.cpp
OrderedOutput.o: OrderedOutput.h
	$(CXX) $(CXXFLAGS) -c OrderedOutput.cpp
clean:
	rm -f core $(PROG) $(OBJS)
