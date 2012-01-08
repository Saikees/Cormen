/*
 * binarysearchtree.cpp
 *
 *  Created on: Jan 7, 2012
 *      Author: wush
 */

#include<iostream>
#include"../BinarySearchTree.hpp"

using namespace wush::data_structure;

int main()
{
	BinarySearchTree<int> T;
	T.TreeInsert(1);
	T.TreeInsert(2);
	std::cout << T.TreeMaximum()->get_key() << "," << T.TreeMinimum()->get_key() << std::endl;
	return 0;
}



