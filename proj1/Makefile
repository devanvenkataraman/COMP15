###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Devan Venkataraman

CXX      = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS  = -g3


INCLUDES = $(shell echo *.h)
EXECS    = CalcYouLater

CalcYouLater: Datum.o DatumStack.o RPNCalc.o main.o
	${CXX} ${LDFLAGS} $^ -o $@

DatumStack.o: DatumStack.cpp DatumStack.h Datum.h
RPNCalc.o: RPNCalc.cpp RPNCalc.h DatumStack.h Datum.h
main.o: main.cpp RPNCalc.h DatumStack.h Datum.h
# testRPNCalc.o: testRPNCalc.cpp RPNCalc.h DatumStack.h Datum.h
# testDatumStack.o: testDatumStack.cpp DatumStack.h Datum.h

##
## Put your variables and rules here.  You can use previous Makefiles
## as examples, and you can refer to the "make" documentation on the
## course Reference page.
##  --- Delete this comment and put appropriate comments in ---


##
## Here is a rule for compiling .cyl files for use in your testing
##
%.cylc:  %.cyl
	./cylc $^
