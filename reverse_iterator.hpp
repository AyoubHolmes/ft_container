#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <vector>
#include <iostream>
namespace ft
{
	template < class T>
	/* 
		iterator_type	Iterator	Iterator's type
		iterator_category	iterator_traits<Iterator>::iterator_category	Preserves Iterator's category
		value_type	iterator_traits<Iterator>::value_type	Preserves Iterator's value type
		difference_type	iterator_traits<Iterator>::difference_type	Preserves Iterator's difference type
		pointer	iterator_traits<Iterator>::pointer	Preserves Iterator's pointer type
		reference	iterator_traits<Iterator>::reference	Preserves Iterator's reference type

	 */
	class MyReverseiterator
	{
        typedef T iterator_type;
	

    };		
}

#endif // !VECTOR_HPP
