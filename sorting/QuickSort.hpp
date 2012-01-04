/*
 * QuickSort.hpp
 *
 *  Created on: Jan 2, 2012
 *      Author: wush
 */

#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include<deque>
#include"Setting.hpp"
namespace wush {
	namespace sorting {

		template<class Array, class ArrayElement>
		const Count Partition(Array& A, const Count start, const Count end)
		{
//			std::cout << "Partition start:" << start << ",end:" << end << std::endl;
			Count i = start;
			for (Count j = start;j < end;j++)
			{
				if (A[j] < A[end]) {
					i++;
					ArrayElement temp = A[i-1];
					A[i-1] = A[j];
					A[j] = temp;
				}
			}
			ArrayElement temp = A[i];
			A[i] = A[end];
			A[end] = temp;

//			for (Count k = start;k <= end;k++)
//			{
//				std::cout << A[k] << ",";
//			}
//			std::cout << std::endl;

			return i;
		}

		template<class Array, class ArrayElement>
		void QuickSort(Array& A,const Count start, const Count end)
		{
			std::deque<Count> start_list(1, start);
			std::deque<Count> end_list(1, end);
			while(start_list.size() > 0)
			{
				if (start_list[0] < end_list[0]) {
					Count q = Partition<Array, ArrayElement>(A, start_list[0], end_list[0]);
//					std::cout << "q:" << q << std::endl;
					if (q > 0) {
						start_list.push_back(start_list[0]);
						end_list.push_back(q - 1);
					}
					start_list.push_back(q);
					end_list.push_back(end);
				}
				start_list.pop_front();
				end_list.pop_front();
			}
		}
	}
}




#endif /* QUICKSORT_HPP_ */
