/*
 * BinarySearchTree.hpp
 *
 *  Created on: Jan 7, 2012
 *      Author: wush
 */

#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_


#include <vector>
#include "Node.hpp"

namespace wush
{
	namespace data_structure
	{
		template<class Key>
		class BinaryTreeNode : public Node
		{
			Key _key;
		public:
			BinaryTreeNode(Key key) : Node(), _key(key) { }
			virtual ~BinaryTreeNode() { }

		    //			BinaryTreeNode(const BinaryTreeNode<Key>& src) : Node()
		    //			{
		    //				this->_key = src._key;
		    //				this->set_child(src.get_child());
		    //				this->set_parent(src.get_parent());
		    //			}
		    //			void operator=(const BinaryTreeNode<Key>& src)
		    //			{
		    //				this->_key = src._key;
		    //				this->set_child(src.get_child());
		    //				this->set_parent(src.get_parent());
		    //			}
		    virtual std::pair<BinaryTreeNode<Key> *,BinaryTreeNode<Key>* > get_child() const
		    {
		        return reinterpret_cast<std::pair<BinaryTreeNode<Key> *,BinaryTreeNode<Key> *> >(_child);
		    }

		    virtual BinaryTreeNode<Key> *get_parent() const
		    {
		        return reinterpret_cast<BinaryTreeNode<Key>*>(_parent);
		    }

		    virtual BinaryTreeNode<Key> *get_root() const
			{
		    	BinaryTreeNode<Key> *x(this);
		    	while(x->get_parent())
		    	{
		    		x = x->get_parent();
		    	}
		    	return x;
			}

		    void set_child(std::pair<BinaryTreeNode<Key> *,BinaryTreeNode<Key> *> child)
		    {
		        _child.first = child.first;
		        _child.second = child.second;
		    }

		    void set_parent(BinaryTreeNode<Key> *parent)
		    {
		        _parent = parent;
		    }

		    Key get_key() const
		    {
		        return _key;
		    }

		    void set_key(Key key)
		    {
		        _key = key;
		    }

		};
	}
}


#endif /* BINARYSEARCHTREE_HPP_ */
