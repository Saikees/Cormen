/*
 * BinarySearchTree.hpp
 *
 *  Created on: Jan 7, 2012
 *      Author: wush
 */

#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include<vector>
#include"setting.hpp"

#ifndef NULL
#define NULL 0
#endif

namespace wush
{
	namespace data_structure
	{
		/**
		 * class Key must have:
		 * Copy constructor and operator = for STL
		 * operator < and == for ordering
		 */
		template<class Key>
		class BinarySearchTreeNode
		{
			Key _key;
			BinarySearchTreeNode<Key>* _parent;
			BinarySearchTreeNode<Key>* _left;
			BinarySearchTreeNode<Key>* _right;
		public:
			BinarySearchTreeNode(const Key& key) : _key(key), _parent(NULL), _left(NULL), _right(NULL) { }

		    Key get_key() const
		    {
		        return _key;
		    }

		    BinarySearchTreeNode<Key> *get_left() const
		    {
		        return _left;
		    }

		    BinarySearchTreeNode<Key> *get_parent() const
		    {
		        return _parent;
		    }

		    BinarySearchTreeNode<Key> *get_right() const
		    {
		        return _right;
		    }

		    void set_key(Key key)
		    {
		        _key = key;
		    }

		    void set_left(BinarySearchTreeNode<Key> *left)
		    {
		        _left = left;
		    }

		    void set_parent(BinarySearchTreeNode<Key> *parent)
		    {
		        _parent = parent;
		    }

		    void set_right(BinarySearchTreeNode<Key> *right)
		    {
		        _right = right;
		    }
		};


		template<class Key>
		class BinarySearchTree
		{
			std::vector<BinarySearchTreeNode<Key>* > _nodes;
			BinarySearchTreeNode<Key>* _root;
		public:
			BinarySearchTree() : _root(NULL) { }
			~BinarySearchTree()
			{
				for (Count i = _nodes.size();i > 0;i--)
				{
					delete _nodes[i - 1];
				}
			}

			// Query Algorithm

			BinarySearchTreeNode<Key>* TreeSearch(const Key& key)
			{
				BinarySearchTreeNode<Key> *x(_root);
				while ( x && !(x->get_key() == key))
				{
					if (key < x->get_key()) {
						x = x->get_left();
					}
					else {
						x = x->get_right();
					}
				}
				return x;
			}

			BinarySearchTreeNode<Key>* TreeMaximum()
			{
				return TreeMaximum(_root);
			}
			BinarySearchTreeNode<Key>* TreeMinimum()
			{
				return TreeMinimum(_root);
			}

			// Modification
			void TreeInsert(const Key& key)
			{

				BinarySearchTreeNode<Key> *x(_root), *y(NULL), *z(new BinarySearchTreeNode<Key>(key));
				_nodes.push_back(z);
				while (x)
				{
					y = x;
					if (key < x->get_key()) {
						x = x->get_left();
					}
					else {
						x = x->get_right();
					}
				}
				z->set_parent(y);
				if (!y) {
					_root = z;
				}
				else {
					if (key < y->get_key()){
						y->set_left(z);
					}
					else {
						y->set_right(z);
					}
				}
			}

			//show


		private:
			BinarySearchTreeNode<Key>* TreeMaximum(BinarySearchTreeNode<Key>* x)
			{
				if (!x)
					return x;
				while (x->get_right())
				{
					x = x->get_right();
				}
				return x;
			}

			BinarySearchTreeNode<Key>* TreeMinimum(BinarySearchTreeNode<Key>* x)
			{
				if (!x)
					return x;
				while (x->get_left())
				{
					x = x->get_left();
				}
				return x;
			}

			BinarySearchTreeNode<Key>* TreeSuccessor(BinarySearchTreeNode<Key>* x)
			{
				if (!x)
					return x;
				if (x->get_right()) {
					return TreeMinimum(x);
				}
				BinarySearchTreeNode<Key> *y(x->get_parent());
				while ( y && x == y->get_right()) {
					x = y;
					y = y->get_parent();
				}
				return y;
			}


			BinarySearchTreeNode<Key>* TreePredecessor(BinarySearchTreeNode<Key>* x)
			{
				if (!x)
					return x;
				if (x->get_left()) {
					return TreeMaximum(x);
				}
				BinarySearchTreeNode<Key> *y(x->get_parent());
				while ( y && x == y->get_left()) {
					x = y;
					y = y->get_parent();
				}
				return y;
			}

		};
	}
}


#endif /* BINARYSEARCHTREE_HPP_ */
