/*
 * PriorityQuene.hpp
 *
 *  Created on: 2012/1/3
 *      Author: wush
 */

#ifndef PRIORITYQUENE_HPP_
#define PRIORITYQUENE_HPP_

#include<iostream>
#include<stdexcept>
#include<utility>
#include<vector>
#include"Setting.hpp"
#include"HeapSort.hpp"

namespace wush {
	namespace sorting {

		/**
		 * class Key has copy constructor and operator =, <
		 * class Job has copy constructor and operator =
		 */
		template<class Key, class Element>
		class HeapPriorityQuene
		{
			typedef std::pair<Key, Element> PriorityObject;
			typedef std::vector<PriorityObject> PriorityArray;
			PriorityArray A;
		public:
			/**
			 *
			 */
			void insert(const Key& key, const Element& element)
			{
				A.push_back(PriorityObject(0, element));
				this->increase_key(A.size() - 1, key);
			}
			/**
			 *
			 */
			const PriorityObject& maximum() const
			{
				return A[0];
			}
			/**
			 * O( lg ( A.size() ) )
			 */
			const PriorityObject extract_maximum()
			{
				if (A.size() < 1) {
					throw std::runtime_error("heap underflow");
				}
				PriorityObject max(A[0]);
				A[0] = A[A.size() - 1];
				A.pop_back();
				MaxHeapify<PriorityArray, PriorityObject>(A, 0, A.size());
				return max;
			}
			void increase_key(Count i, const Key& key)
			{
				if (key < A[i].first) {
					throw std::runtime_error("new key is smaller than current key");
				}
				A[i].first = key;
				while (i > 0 && A[ (i+1)/2 - 1 ].first < A[i].first)
				{
					PriorityObject temp(A[i]);
					A[i] = A[ (i+1)/2 - 1];
					A[ (i+1)/2 - 1] = temp;
					i = (i+1)/2 - 1;
				}
			}
			void show() const
			{
				for (Count i = 0;i < A.size();i++)
				{
					std::cout << A[i].first<< ",";
				}
				std::cout << std::endl;
			}
		};
	}
}


#endif /* PRIORITYQUENE_HPP_ */
