EXEC = PJ1
CC = g++
CFLAGS = -c -Wall
#
$(EXEC) :main.o InsertionSort.o MergeSort.o QuickSort.o
	$(CC) -o $(EXEC) main.o InsertionSort.o MergeSort.o QuickSort.o
#
main.o	:main.cpp InsertionSort.h MergeSort.h QuickSort.h
	$(CC) $(CFLAGS) main.cpp
#
InsertionSort.o	:InsertionSort.cpp InsertionSort.h
		$(CC) $(CFLAGS) InsertionSort.cpp
#
MergeSort.o	:MergeSort.cpp MergeSort.h
		$(CC) $(CFLAGS) MergeSort.cpp
#
QuickSort.o	:QuickSort.cpp QuickSort.h
		$(CC) $(CFLAGS) QuickSort.cpp
