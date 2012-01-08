/*
 * countingsort.cpp
 *
 *  Created on: 2012/1/4
 *      Author: wush
 */

#include<iostream>
#include "../CountingSort.hpp"

int main()
{
	int A[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	int B[8];
	int C[6] = { 0, 1, 2, 3, 4, 5 };
	wush::sorting::CountingSort< int [8], int, int [6]>(C, 6, A, 8, B);
	for (unsigned int i = 0;i < 8;i++) {
		std::cout << B[i] << ",";
	}
	std::cout << std::endl;
	return 0;
}
