all : build/quicksort.exe build/heapsort.exe build/heappriorityquene.exe build/countingsort.exe

build/quicksort.exe : build/quicksort.cpp QuickSort.hpp
	g++ build/quicksort.cpp -o build/quicksort.exe
	
build/heapsort.exe : build/heapsort.cpp HeapSort.hpp
	g++ build/heapsort.cpp -o build/heapsort.exe
	
build/heappriorityquene.exe : build/heappriorityquene.cpp HeapPriorityQuene.hpp
	g++ build/heappriorityquene.cpp -o build/heappriorityquene.exe
	
build/countingsort.exe : build/countingsort.cpp CountingSort.hpp
	g++ build/countingsort.cpp -o build/countingsort.exe 

clean :
	rm build/*.exe
	
test :
	build/quicksort.exe
	build/heapsort.exe
	build/heappriorityquene.exe
	build/countingsort.exe