/*
 * BinarySearchTree.hpp
 *
 *  Created on: Jan 7, 2012
 *      Author: wush
 */

#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
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
			void operator=(const BinarySearchTreeNode<Key>& src)
			{
				this->_key = src._key;
				this->_left = src._left;
				this->_right = src._right;
				this->_parent = src._parent;
			}

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
//			std::vector<BinarySearchTreeNode<Key>* > _nodes;
			BinarySearchTreeNode<Key>* _root;
		public:
			BinarySearchTree() : _root(NULL) { }
			virtual ~BinarySearchTree()
			{
				while(_root)
				{
					TreeDelete(_root);
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
			BinarySearchTreeNode<Key>* TreeMaximum(const Key& key)
			{
				return TreeMaximum( TreeSearch(key) );
			}

			BinarySearchTreeNode<Key>* TreeMinimum(const Key& key)
			{
				return TreeMinimum( TreeSearch(key) );
			}

			BinarySearchTreeNode<Key>* TreeSuccessor(const Key& key)
			{
				return TreeSuccessor( TreeSearch(key) );
			}

			BinarySearchTreeNode<Key>* TreePredecessor(const Key& key)
			{
				return TreePredecessor( TreeSearch(key) );
			}



			// Modification
			void TreeInsert(const Key& key)
			{
				BinarySearchTreeNode<Key> *x(_root), *y(NULL), *z(new BinarySearchTreeNode<Key>(key));
//				_nodes.push_back(z);
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

			void TreeDelete(const Key& key)
			{
				TreeDelete(TreeSearch(key));
			}

			void TreeLeftRotate(const Key& key)
			{
				TreeLeftRotate(TreeSearch(key));
			}

			void TreeRightRotate(const Key& key)
			{
				TreeRightRotate(TreeSearch(key));
			}

			//show
			typedef std::pair<BinarySearchTreeNode<Key>*, bool > BinarySearchTreeNodeRelation;
			void Show()
			{
				BinarySearchTreeNode<Key>* x(_root);
				std::vector<BinarySearchTreeNodeRelation > show_list, next_list;
				std::cout << "root:" << x->get_key() << std::endl;
				if (x->get_left()) {
					next_list.push_back(std::make_pair(x->get_left(), true));
				}
				if (x->get_right()) {
					next_list.push_back(std::make_pair(x->get_right(), false));
				}
				while(next_list.size())
				{
					show_list.swap(next_list);
					next_list.clear();
					for (Count i = 0;i < show_list.size();i++)
					{
						BinarySearchTreeNode<Key> *y = show_list[i].first;
						std::cout << y->get_parent()->get_key() << ( show_list[i].second ? "(left)" : "(right)" ) << ":" << y->get_key() << " ";
						if (y->get_left()) {
							next_list.push_back(std::make_pair(y->get_left(), true));
						}
						if (y->get_right()) {
							next_list.push_back(std::make_pair(y->get_right(), false));
						}
					}
					std::cout << std::endl;
				}
			}

		protected:
			//rotation
			void TreeLeftRotate(BinarySearchTreeNode<Key>* x)
			{
				if (!x) {
					return;
				}
				if (!x->get_right()) {
					return;
				}
				BinarySearchTreeNode<Key> *y(x->get_right());
//				x->set_right(y->get_left());
//				if (y->get_left()) {
//					y->get_left()->set_parent(x);
//				}
//				y->set_parent(x->get_parent());
//				if (x->get_parent()) {
//					_root = y;
//				}
//				else {
//					if (x == x->get_parent()->get_left()) {
//						x->get_parent()->set_left(y);
//					}
//					else {
//						x->get_parent()->set_right(y);
//					}
//				}
//				y->set_left(x);
//				x->set_parent(y);
			}

			void TreeRightRotate(BinarySearchTreeNode<Key>* x)
			{
				if (!x) {
					return;
				}
				if (!x->get_left()) {
					return;
				}
				BinarySearchTreeNode<Key> *y(x->get_left());
				x->set_left(y->get_right());
				if (y->get_right()) {
					y->get_right()->set_parent(x);
				}
				y->set_parent(x->get_parent());
				if (x->get_parent()) {
					_root = y;
				}
				else {
					if (x == x->get_parent()->get_right()) {
						x->get_parent()->set_right(y);
					}
					else {
						x->get_parent()->set_left(y);
					}
				}
				y->set_right(x);
				x->set_parent(y);
			}


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
					return TreeMinimum(x->get_right());
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
					return TreeMaximum(x->get_left());
				}
				BinarySearchTreeNode<Key> *y(x->get_parent());
				while ( y && x == y->get_left()) {
					x = y;
					y = y->get_parent();
				}
				return y;
			}

			void TreeDelete(BinarySearchTreeNode<Key>* z)
			{
//				std::vector<BinarySearchTreeNode<Key>* >::iterator z_itor = std::find(_nodes.begin(), _nodes.end(), z);
//				if (z_itor == _nodes.end()) {
//					return;
//				}
				if (!z) {
					return;
				}
				BinarySearchTreeNode<Key> *y, *x;
				if (!z->get_left() || !z->get_right()) {
					y = z;
				}
				else {
					y = TreeSuccessor(z);
				}
				if (y->get_left()) {
					x = y->get_left();
				}
				else {
					x = y->get_right();
				}
				if (x) {
					x->set_parent(y->get_parent());
				}
				if (!y->get_parent()) {
					_root = x;
				}
				else {
					if (y == y->get_parent()->get_left()) {
						y->get_parent()->set_left(x);
					}
					else {
						y->get_parent()->set_right(x);
					}
				}
				if (y != z) {
					z->set_key(y->get_key());
				}
				delete y;
			}
		};
	}
}


#endif /* BINARYSEARCHTREE_HPP_ */
