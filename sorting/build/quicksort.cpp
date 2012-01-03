/*
 * test.cpp
 *
 *  Created on: Jan 2, 2012
 *      Author: wush
 */
#include<iostream>
#include "../QuickSort.hpp"

int main()
{
	int A[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	wush::sorting::QuickSort<int [8], int>(A, 0, 7);
	for (int i = 0;i < 8;i++)
	{
		std::cout << A[i] << ",";
	}
	std::cout << std::endl;
	return 0;
}




