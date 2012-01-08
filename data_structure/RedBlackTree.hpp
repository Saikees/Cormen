/*
 * RedBlackTree.hpp
 *
 *  Created on: Jan 8, 2012
 *      Author: wush
 */

#ifndef REDBLACKTREE_HPP_
#define REDBLACKTREE_HPP_
#include"BinarySearchTree.hpp"

namespace wush
{
	namespace data_structure
	{
		template<class Key>
		class RedBlackTreeNode
			: public BinarySearchTreeNode<Key>
		{
			bool _color;
		public:
			RedBlackTreeNode(const Key& key) : BinarySearchTreeNode<Key>(key), _color(BLACK) { }

		};

		template<class Key>
		class RedBlackTree
			: public BinarySearchTree<Key>
		{
		public:
			RedBlackTree() : BinarySearchTree<Key>() { }
			virtual ~RedBlackTree() { }
		};
	}
}


#endif /* REDBLACKTREE_HPP_ */
