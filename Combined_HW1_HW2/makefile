
CXX = g++ -std=c++11

OBJS = main.o openFile.o insertionSort.o mergeSort.o stooge_sort.o stoogeTime.o
SRCS = main.cpp openFile.cpp insertionSort.cpp mergeSort.cpp stooge_sort.cpp stoogeTime.cpp

HEADERS = openFile.hpp insertionSort.hpp mergeSort.hpp stooge_sort.hpp stoogeTime.hpp

main: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} main

