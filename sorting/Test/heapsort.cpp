/*
 * heapsort.cpp
 *
 *  Created on: Jan 2, 2012
 *      Author: wush
 */
#include<iostream>
#include "../HeapSort.hpp"

int main()
{
	int A[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int* testing_input = new int[10];
	for (int i = 0;i < 10;i++)
	{
		testing_input[i] = A[i];
	}
	wush::sorting::BuildMaxHeap<int*, int>(testing_input, 10);
	std::cout << "BuildMaxHeap:";
	for (int i = 0;i < 10;i++)
	{
		std::cout << testing_input[i] << ",";
	}
	std::cout << std::endl;

	for (int i = 0;i < 10;i++)
	{
		testing_input[i] = A[i];
	}
	wush::sorting::HeapSort<int*, int>(testing_input, 10);
	std::cout << "HeapSort:";
	for (int i = 0;i < 10;i++)
	{
		std::cout << testing_input[i] << ",";
	}
	std::cout << std::endl;

	return 0;
}


