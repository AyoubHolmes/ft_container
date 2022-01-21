#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <vector>
#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template < class T>
	class Myiterator: public iterator<std::random_access_iterator_tag, T>
	{
        public:
            /* **** MEMBER TYPES ***** */
            typedef T iterator_type;
            typedef typename iterator_traits<T>::difference_type difference_type;
            typedef typename iterator_traits<T>::pointer pointer;
            typedef typename iterator_traits<T>::reference reference;
              // typedef  T& reference;

        private:
            iterator_type ptr;

        public:
            Myiterator(): ptr(NULL) {
            };
            Myiterator(iterator_type t): ptr(t) {};
            template <class Iter>
            Myiterator(Myiterator<Iter>& i): ptr(i.base()) {};
            iterator_type base() const{
                return (ptr);
            };
            Myiterator operator+ (difference_type n) const {
              Myiterator tmp = *this;
              tmp.ptr = tmp.ptr + n;
              return (tmp);
            };
            Myiterator& operator++() {
              ptr++;
              return (*this);
            };
            Myiterator  operator++(int) {
                   Myiterator tmp(*this);
                   ptr++;
                   return (tmp);
            };

            Myiterator& operator+= (difference_type n) {
                   ptr += n;
                   return (*this);
            };
            Myiterator operator- (difference_type n) const {
              Myiterator tmp = *this;
              tmp.ptr = tmp.ptr - n;
              return (tmp);
            };
            Myiterator& operator--() {
              ptr--;
              return (*this);
            };
            Myiterator  operator--(int) {
              Myiterator tmp(*this);
              ptr--;
              return (tmp);
            };
            Myiterator& operator-= (difference_type n) {
              ptr -= n;
              return (*this);
            };
            reference operator*() const {
                   return (*ptr);
            };
            reference operator[] (difference_type n) const {
                   return *(ptr + n);
            };
           
            template <class Iterator>
            friend bool operator== (const Myiterator<Iterator>& lhs,
                   const Myiterator<Iterator>& rhs);
            
            template <class Iterator>
            friend bool operator>= (const Myiterator<Iterator>& lhs,
                   const Myiterator<Iterator>& rhs);
            
            template <class Iterator>
            friend bool operator!= (const Myiterator<Iterator>& lhs,
                   const Myiterator<Iterator>& rhs);

            template <class Iterator>
            friend bool operator<= (const Myiterator<Iterator>& lhs,
                   const Myiterator<Iterator>& rhs);
            
            template <class Iterator>
            friend bool operator> (const Myiterator<Iterator>& lhs,
                   const Myiterator<Iterator>& rhs);

            template <class Iterator>
            friend bool operator< (const Myiterator<Iterator>& lhs,
                   const Myiterator<Iterator>& rhs);
            
            template <class Iterator>
            friend typename Myiterator<Iterator>::difference_type operator- (
              const Myiterator<Iterator>& lhs,
              const Myiterator<Iterator>& rhs);
            
            template <class Iterator>
            friend typename Myiterator<Iterator>::difference_type operator+ (
              const Myiterator<Iterator>& lhs,
              const Myiterator<Iterator>& rhs);
    };
       template <class Iterator>
       bool operator== (const Myiterator<Iterator>& lhs, const Myiterator<Iterator>& rhs) {
              return (lhs.ptr == rhs.ptr);
       };
            
       template <class Iterator>
       bool operator>= (const Myiterator<Iterator>& lhs, const Myiterator<Iterator>& rhs) {
             return (lhs.ptr >= rhs.ptr); 
       };
            
       template <class Iterator>
       bool operator!= (const Myiterator<Iterator>& lhs, const Myiterator<Iterator>& rhs) {
              return (lhs.ptr != rhs.ptr);
       };

       template <class Iterator>
       bool operator<= (const Myiterator<Iterator>& lhs, const Myiterator<Iterator>& rhs) {
              return (lhs.ptr <= rhs.ptr);
       };
            
       template <class Iterator>
       bool operator> (const Myiterator<Iterator>& lhs, const Myiterator<Iterator>& rhs) {
              return (lhs.ptr > rhs.ptr);
       };

       template <class Iterator>
       bool operator< (const Myiterator<Iterator>& lhs, const Myiterator<Iterator>& rhs) {
              return (lhs.ptr < rhs.ptr);
       };
            
       template <class Iterator>
       typename Myiterator<Iterator>::difference_type operator- (
              const Myiterator<Iterator>& lhs,
              const Myiterator<Iterator>& rhs) {
              return (lhs.base() - rhs.base());
       };
            
       template <class Iterator>
       typename Myiterator<Iterator>::difference_type operator+ (
              const Myiterator<Iterator>& lhs,
              const Myiterator<Iterator>& rhs) {
              return (lhs.base() + rhs.base());
       };
}

#endif // !ITERATOR_HPP
