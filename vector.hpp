#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <vector>
#include <iostream>
namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference; //int &, char &
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			// typedef implementation-defined                   const_iterator;
			// typedef implementation-defined                   iterator;
			// typedef std::reverse_iterator<iterator>          reverse_iterator;
			// typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
	};
}

#endif // !VECTOR_HPP
