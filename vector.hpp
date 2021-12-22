#ifndef VECTOR_HPP
# define VECTOR_HPP
// #include <vector>
#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
namespace ft
{
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		public:
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference; //int &, char &
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef typename ft::Myiterator<pointer>					iterator; // int *
			typedef typename ft::Myiterator<const_pointer>				const_iterator;
			typedef typename ft::MyReverseiterator<iterator>          	reverse_iterator;
			typedef typename ft::MyReverseiterator<const_iterator>    	const_reverse_iterator;

		private:
			T *arr;
			size_type n;
			size_type capacity;
			allocator_type _alloc;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), n(0), arr(nullptr), capacity(0)
			{
			};

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): n(n), _alloc(alloc), capacity(n)  {
				arr = _alloc.allocate(capacity);
				for (size_t i = 0; i < n; i++)
					arr[i] = val;
			};
			
			/* template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()) {
				arr = alloc.allocate(last - first);
				int i = 0;
				while (first != last)
				{
					arr[i] = *first;
					first++;
				}
			}; */
			vector (const vector& x) {
				capacity = x.capacity;
				n = x.n;
				_alloc = x._alloc;
				for (size_type i = 0; i < n; i++)
					_alloc.destroy(arr + i);
				arr = _alloc.allocate(x.capacity);
				for (size_type i = 0; i < x.n; i++)
					arr[i] = x.arr[i];
				
			};
			iterator begin() {
				// std::cout << "Rak hna" << std::endl;
				return (iterator(arr));
			};

			const_iterator begin() const {
				return (iterator(arr));
			};

			iterator end() {
				return (iterator(arr + n));
			};

			const_iterator end() const {
				return (iterator(arr + n));
			};
			reverse_iterator rbegin() {
				// std::cout << "Rak hna" << std::endl;
				return (reverse_iterator(end()));
			};

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			};
			reverse_iterator rend() {
				// std::cout << "Rak hna" << std::endl;
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			};

	};
}

#endif // !VECTOR_HPP
