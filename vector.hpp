#ifndef VECTOR_HPP
# define VECTOR_HPP
// #include <vector>
#include <iostream>
#include <stdexcept>  
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
			size_type _capacity;
			allocator_type _alloc;

		public:
			explicit vector (const allocator_type& alloc = allocator_type()): _alloc(alloc), n(0), arr(nullptr), _capacity(0)
			{
			};

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): n(n), _alloc(alloc), _capacity(n)  {
				arr = _alloc.allocate(_capacity);
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
				_capacity = x._capacity;
				n = x.n;
				_alloc = x._alloc;
				for (size_type i = 0; i < n; i++)
					_alloc.destroy(arr + i);
				arr = _alloc.allocate(x._capacity);
				for (size_type i = 0; i < x.n; i++)
					arr[i] = x.arr[i];
				
			};
			iterator begin() {
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
				return (reverse_iterator(end()));
			};

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			};
			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			};

			size_type size() const {
				return (n);
			};

			size_type max_size() const {
				return (_alloc.max_size());
			};

			void resize (size_type n, value_type val = value_type()) {
				value_type *tmp;

				if (n < this->n)
				{
					for (size_type i = 0; i < this->n; i++)
						if (i >= n)
							_alloc.destroy(&arr[i]);
					n = this->n;
				}
				else if (n > this->n) {
					if (n < this->_capacity)
					{
						for (size_type i = 0; i < n; i++)
							if (i >= this->n)
								_alloc.construct(&arr[i], val);
						n = this->n;
					}
					else if (n > this->_capacity)
					{
						n = n > 2 * this->_capacity ? n : this->_capacity * 2;
						tmp = _alloc.allocate(n);
						for (size_type i = 0; i < this->n; i++)
							_alloc.construct(&tmp[i], arr[i]);
						for (size_type i = 0; i < this->n; i++)
							_alloc.destroy(&arr[i]);
						_alloc.deallocate(arr, _capacity);
						_capacity = n;
					}
				}
			};

			size_type capacity() const {
				return (this->_capacity);
			};
			bool empty() const {
				return (this->n == 0);
			};

			void reserve (size_type n) {
				value_type *tmp;

				if (n > this->_capacity)
				{
					n = n > 2 * this->_capacity ? n : this->_capacity * 2;
					tmp = _alloc.allocate(n);
					for (size_type i = 0; i < this->n; i++)
						_alloc.construct(&tmp[i], arr[i]);
					for (size_type i = 0; i < this->n; i++)
						_alloc.destroy(&arr[i]);
					_alloc.deallocate(arr, _capacity);
					_capacity = n;
				}
			}

			reference operator[] (size_type n) {
				return (arr[n]);
			};

			const_reference operator[] (size_type n) const {
				return (arr[n]);
			};

			reference at (size_type n) {
				if (n >= this->size)
					throw std::out_of_range("Vector");
				return (arr[n]);
			};

			const_reference at (size_type n) const {
				if (n >= this->size)
					throw std::out_of_range("Vector");
				return (arr[n]);
			};
			reference front() {
				return (arr[0]);
			};
			const_reference front() const {
				return (arr[0]);
			};
			reference back() {
				return (arr[n - 1]);
			};
			const_reference back() const {
				return (arr[n - 1]);
			};
	};
	
}

#endif // !VECTOR_HPP
