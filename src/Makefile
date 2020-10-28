CXX = g++
CXXFLAGS = -std=c++11 -Wall -pedantic -O2

OBJECTS = main.o list.o imbal.o

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS): ./list.h ./imbal.h

make clean:
	rm -f *.o
