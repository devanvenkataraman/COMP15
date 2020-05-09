CXX      = /usr/sup/bin/clang++
CXXFLAGS = --std=c++11 -Wshadow -Wall -Wextra -g3

%.o: %.cpp $(shell echo *.h)
	$(CXX) $(CXXFLAGS) -c $<

findpath: findpath.o Location.o graph.o
	$(CXX) -o $@ $^

findpath.o: findpath.cpp graph.h
testGraph.o: testGraph.cpp graph.h
Location.o: Location.cpp Location.h
graph.o: graph.cpp graph.h vertex.h

clean:
	rm -f rt findpath *.o

# Add some rules for rt website
include Makefile.publish
