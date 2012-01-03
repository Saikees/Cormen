/*
 * heappriorityquene.cpp
 *
 *  Created on: 2012/1/3
 *      Author: wush
 */

#include"../HeapPriorityQuene.hpp"

int main()
{
	wush::sorting::HeapPriorityQuene<int, int> A;
	A.insert(16, 16);
	A.insert(14, 14);
	A.insert(10, 10);
	A.insert(8, 8);
	A.insert(7, 7);
	A.insert(9, 9);
	A.insert(3, 3);
	A.insert(2, 2);
	A.insert(4, 4);
	A.insert(1, 1);
	A.show();
	A.increase_key(8, 15);
	A.show();
	return 0;
}


