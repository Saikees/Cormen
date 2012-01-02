all : Test/quicksort.exe Test/heapsort.exe

Test/quicksort.exe : Test/quicksort.cpp QuickSort.hpp
	g++ Test/quicksort.cpp -o Test/quicksort.exe
	
Test/heapsort.exe : Test/heapsort.cpp HeapSort.hpp
	g++ Test/heapsort.cpp -o Test/heapsort.exe
	
clean :
	rm Test/*.exe
	
test :
	Test/quicksort.exe
	Test/heapsort.exe