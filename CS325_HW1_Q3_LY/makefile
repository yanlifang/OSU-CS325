
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o openFile.o insertionSort.o mergeSort.o timing.o
SRCS = main.cpp openFile.cpp insertionSort.cpp mergeSort.cpp timing.cpp

HEADERS = openFile.hpp insertionSort.hpp mergeSort.hpp timing.hpp

main: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} main

