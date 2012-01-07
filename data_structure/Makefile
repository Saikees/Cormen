all : build/node.exe build/binarytree.exe build/binarysearchtree.exe

build/node.exe : Node.hpp build/node.cpp
	g++ build/node.cpp -o build/node.exe
	
build/binarytree.exe : BinaryTree.hpp build/binarytree.cpp
	g++ build/binarytree.cpp -o build/binarytree.exe 
	
build/binarysearchtree.exe : BinarySearchTree.hpp build/binarysearchtree.cpp
	g++ build/binarysearchtree.cpp -o build/binarysearchtree.exe