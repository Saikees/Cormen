/*
 * HeapSort.hpp
 *
 *  Created on: 2012/1/1
 *      Author: wush
 */

#ifndef HEAPSORT_HPP_
#define HEAPSORT_HPP_

namespace wush
{

	namespace sorting
	{
#ifndef COUNT
		typedef unsigned int Count;
#define COUNT
#endif //COUNT

		/**
		 * See page 112 of Cormen
		 */
		inline const Count Parent(const Count i) { return (i+1)/2 - 1; }
		inline const Count Left(const Count i) { return 2*(i+1) - 1; }
		inline const Count Right(const Count i) { return 2*(i+1); }


		/**
		 * See page 115 of Cormen
		 * MaxHeapify assumed that the binary trees rooted at LEFT(i) and RIGHT(i) are max-heaps, but
		 * that A[i] may be smaller than its children, thus violating the max-heap property.
		 * MaxHeapify will correct this violation.
		 *
		 * @params A 	container with operator [] and <
		 */
		template<class Array, class ArrayElement>
		void MaxHeapify(Array& A, Count i, const Count A_size)
		{
			// parent(i) = (i+1)/2 - 1
			// left(i) = 2*(i+1) - 1
			// right(i) = 2*(i+1)
//			std::cout << "MaxHeapify i:" << i << ",A_size:" << A_size << std::endl;
			bool is_continue = true;
			while (is_continue) {
				is_continue = true;
				Count
					l = 2*(i+1) - 1,
					r = 2*(i+1),
					largest;
				if (l < A_size && A[l] > A[i]) {
					largest = l;
				}
				else {
					largest = i;
				}
				if (r < A_size && A[r] > A[largest]) {
					largest = r;
				}
				if (largest != i) {
					ArrayElement temp(A[i]);
					A[i] = A[largest];
					A[largest] = temp;
					i = largest;
//					std::cout << largest << std::endl;
				}
				else {
					is_continue = false;
				}
			}
		}

		template<class Array, class ArrayElement>
		void BuildMaxHeap(Array& A, const Count A_size) {
			for (Count i = A_size/2;i >= 1;i--)
			{
				MaxHeapify<Array, ArrayElement>(A, i-1, A_size);
			}
		}

		template<class Array, class ArrayElement>
		void HeapSort(Array& A, Count A_size)
		{
			BuildMaxHeap<Array, ArrayElement>(A, A_size);
			for (Count i= A_size - 1;i >= 1;i--) {
				Count temp(A[0]);
				A[0] = A[i];
				A[i] = temp;
				A_size--;
				MaxHeapify<Array, ArrayElement>(A, 0, A_size);
			}
		}
	}
}

#endif /* HEAPSORT_HPP_ */
