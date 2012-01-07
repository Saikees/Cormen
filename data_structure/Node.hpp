/*
 * TreeNode.hpp
 *
 *  Created on: Jan 7, 2012
 *      Author: wush
 */

#ifndef TREENODE_HPP_
#define TREENODE_HPP_

#ifndef NULL
#define NULL 0
#endif

#include <utility>
#include "setting.hpp"
namespace wush
{
	namespace data_structure
	{
		class Node
		{
		protected:
			Node* _parent;
			std::pair<Node* , Node*> _child;
		public:
			Node() : _parent(NULL)
			{
				_child.first = NULL;
				_child.second = NULL;
			}
			virtual ~Node() { };
		public:
		    virtual std::pair<Node*,Node*> get_child() const
		    {
		        return _child;
		    }

		    virtual Node *get_parent() const
		    {
		        return _parent;
		    }

		    void set_child(std::pair<Node*,Node*> child)
		    {
		        _child = child;
		    }

		    void set_parent(Node *parent)
		    {
		        _parent = parent;
		    }

		};
	}
}


#endif /* TREENODE_HPP_ */
