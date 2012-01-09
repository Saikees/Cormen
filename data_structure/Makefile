all : build/redblacktree.exe

#build/binarysearchtree.exe : BinarySearchTree.hpp build/binarysearchtree.cpp
#	g++ build/binarysearchtree.cpp -o build/binarysearchtree.exe
	
build/redblacktree.exe : RedBlackTree.hpp build/redblacktree.cpp
	g++ build/redblacktree.cpp -o build/redblacktree.exe
	
test: 
	build/redblacktree.exe

clean:
	rm -r build
