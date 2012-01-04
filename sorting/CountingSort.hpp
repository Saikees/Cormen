/*
 * CountingSort.hpp
 *
 *  Created on: 2012/1/4
 *      Author: wush
 */

#ifndef COUNTINGSORT_HPP_
#define COUNTINGSORT_HPP_

#include<memory>
#include"Setting.hpp"

namespace wush
{
	namespace sorting
	{
		/**
		 * @param element_set[ element ] = unique index of element
		 */
		template<class Array, class Element, class ElementSet>
		void CountingSort(const ElementSet& element_set, const Count element_set_size, const Array& input, const Count input_size, Array& output)
		{
			std::auto_ptr<Count> element_size(new Count[element_set_size]);
			for (Count i = 0;i < element_set_size;i++)
			{
				*(element_size.get() + i) = 0;
			}
			for (Count i = 0;i < input_size;i++)
			{
				*(element_size.get() + element_set[ input[i] ]) += 1;
			}
			for (Count i = 1;i < element_set_size;i++)
			{
				*(element_size.get() + i) += *(element_size.get() + i - 1);
			}
			for (Count i = input_size;i >= 1;i--)
			{
				output[ *(element_size.get() + element_set[ input[i - 1] ] ) - 1 ] = input[ i - 1 ];
				*(element_size.get() + element_set[ input[i - 1] ] ) -= 1;
			}
		}

	}
}


#endif /* COUNTINGSORT_HPP_ */
