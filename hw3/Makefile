CXX      = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3


INCLUDES = $(shell echo *.h)
EXECS    = MetroSim

# Students will need to add other .o files
MetroSim: main.o MetroSim.o MetroLine.o PassengerQueue.o
	${CXX} ${LDFLAGS} $^ -o $@

MetroSim.o: MetroSim.cpp	MetroSim.h	MetroLine.h PassengerQueue.h
main.o: main.cpp	MetroSim.h	MetroLine.h
MetroLine.o: MetroLine.cpp	MetroLine.h	PassengerQueue.h	Passenger.h
PassengerQueue.o: PassengerQueue.cpp	PassengerQueue.h	Passenger.h

%.o: %.cpp ${INCLUDES}
	${CXX} ${CXXFLAGS} -c -o $@ $<

.PHONY: clean
clean:
	rm -f ${EXECS} *.o *.dSYM./
