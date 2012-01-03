all : build/quicksort.exe build/heapsort.exe

build/quicksort.exe : build/quicksort.cpp QuickSort.hpp
	g++ build/quicksort.cpp -o build/quicksort.exe
	
build/heapsort.exe : build/heapsort.cpp HeapSort.hpp
	g++ build/heapsort.cpp -o build/heapsort.exe
	
clean :
	rm build/*.exe
	
test :
	build/quicksort.exe
	build/heapsort.exe