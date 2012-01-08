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
	T.TreeInsert(3);
	T.TreeInsert(6);
	T.TreeInsert(7);
	T.TreeInsert(1);
	T.TreeInsert(2);
	T.TreeInsert(5);
	T.TreeInsert(4);
	std::cout << T.TreeSuccessor(3)->get_key() << std::endl;
	T.TreeDelete(3);
	T.Show();
	return 0;
}



