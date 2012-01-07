/*
 * BinarySearchTree.hpp
 *
 *  Created on: Jan 7, 2012
 *      Author: wush
 */

#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include<vector>
#include"BinaryTree.hpp"

namespace wush
{
	namespace data_structure
	{
		template<class Key>
		class BinarySearchTreeNode : public BinaryTreeNode<Key>
		{
		public:
			BinarySearchTreeNode() : BinaryTreeNode<Key>() { }
			virtual ~BinarySearchTreeNode()
			{
				BinarySearchTreeNode<Key> *x, *y;
				if (!this->get_child().first || !this->get_child().second) {
					y = this;
				}
				else {
					y = this->tree_successor();
				}
				if (y->get_child().first) {
					x = y->get_child().first;
				}
				else {
					x = y->get_child().second;
				}
				if (x) {
					x->set_parent(y->get_parent());
				}
				if (y->get_parent()) {
					if (y == y->get_parent()->get_child().first) {
						y->get_parent()->get_child().first = x;
					}
					else {
						y->get_parent()->get_child().second = x;
					}
				}
				if (y != this) {
					if (this->get_child().first) {
						y->get_child().first = this->get_child().first;
						this->get_child().first->set_parent(y);
					}
					if (this->get_child().second) {
						y->get_child().second = this->get_child().second;
						this->get_child().second->set_parent(y);
					}
					if (!this->get_parent()) {
						return;
					}
					if (this->get_parent()->get_child().first == this) {
						this->get_parent()->get_child().first = y;
					}
					else {
						this->get_parent()->get_child().second = y;
					}
					y->set_parent(this->get_parent());
				}
			}

			void inorder_tree_walk(std::vector<Key>& output)
			{
				if (this->get_child().first) {
					this->get_child().first->inorder_tree_walk(output);
				}
				output.push(this->get_key());
				if (this->get_child().second) {
					this->get_child().second->inorder_tree_walk(output);
				}
			}

			BinarySearchTreeNode<Key>* tree_search(const Key& reference)
			{
				BinarySearchTreeNode<Key> *x(this);
				while( x && reference != x->get_key())
				{
					if (reference < x->get_key) {
						x = x->get_child().first;
					}
					else {
						x = x->get_child().second;
					}
				}
				return x;
			}

			BinarySearchTreeNode<Key>* tree_minimum()
			{
				BinarySearchTreeNode<Key> *x(this);
				while (x->get_child().first)
				{
					x = x->get_child().first;
				}
				return x;
			}

			BinarySearchTreeNode<Key>* tree_maximum()
			{
				BinarySearchTreeNode<Key> *x(this);
				while (x->get_child().second)
				{
					x = x->get_child().second;
				}
				return x;
			}

			BinarySearchTreeNode<Key>* tree_successor()
			{
				BinarySearchTreeNode<Key> *x(this);
				if (x->get_child().second) {
					return x->get_child().second->tree_minimum();
				}
				BinarySearchTreeNode<Key> *y(x->get_parent());
				while (y && x == y->get_child().second)
				{
					x = y;
					y = y->get_parent();
				}
				return y;
			}

			BinarySearchTreeNode<Key>* tree_predecessor()
			{
				BinarySearchTreeNode<Key> *x(this);
				if (x->get_child().first) {
					return x->get_child().first->tree_maximum();
				}
				BinarySearchTreeNode<Key> *y(x->get_parent());
				while (y && x == y->get_child().first)
				{
					x = y;
					y = y->get_parent();
				}
				return y;
			}

			void tree_insert(const Key k)
			{
				BinarySearchTreeNode<Key> *x(this->get_root()), *y(NULL), *z(new BinarySearchTreeNode<Key>());
				while (x)
				{
					y = x;
					if(k < x->get_key()) {
						x = x->get_child().first;
					}
					else {
						x = x->get_child().second;
					}
				}
				z->set_parent(y);
				if (k < y->get_key()) {
					y->get_child().first = z;
				}
				else {
					y->get_child().second = z;
				}
				z->set_key(k);
			}

		    virtual BinarySearchTreeNode<Key> *get_root() const
			{
		    	return reinterpret_cast<BinarySearchTreeNode<Key>* >(BinaryTreeNode<Key>::get_root());
			}

		    virtual std::pair<BinarySearchTreeNode<Key>*,BinarySearchTreeNode<Key>*> get_child() const
		    {
		        return reinterpret_cast<std::pair<BinarySearchTreeNode<Key>*,BinarySearchTreeNode<Key>*> >(_child);
		    }

		    virtual BinarySearchTreeNode<Key> *get_parent() const
		    {
		        return reinterpret_cast<BinarySearchTreeNode<Key>*>(_parent);
		    }

		    void set_child(std::pair<BinarySearchTreeNode<Key>*,BinarySearchTreeNode<Key>*> child)
		    {
		        _child.first = child.first;
		        _child.second = child.second;
		    }

		    void set_parent(BinarySearchTreeNode<Key> *parent)
		    {
		        _parent = parent;
		    }

		};
	}
}


#endif /* BINARYSEARCHTREE_HPP_ */
