#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP
#include <vector>
#include <iostream>
#include "iteratorTraits.hpp"

namespace ft
{
       template <class T>
       class MyReverseiterator : public iterator<std::random_access_iterator_tag, T>
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
              MyReverseiterator() : ptr(NULL){};
              MyReverseiterator(iterator_type t) : ptr(t){};
              template <class Iter>
              MyReverseiterator(MyReverseiterator<Iter> &i) : ptr(i.base()){};
              iterator_type base() const
              {
                     return (ptr);
              };
              MyReverseiterator operator+(difference_type n) const
              {
                     ptr = ptr - n;
                     return (*this);
              };
              MyReverseiterator &operator++()
              {
                     ptr--;
                     return (*this);
              };
              MyReverseiterator operator++(int)
              {
                     MyReverseiterator tmp(*this);
                     ptr--;
                     return (tmp);
              };

              MyReverseiterator &operator+=(difference_type n)
              {
                     ptr -= n;
                     return (*this);
              };
              MyReverseiterator operator-(difference_type n) const
              {
                     ptr = ptr + n;
                     return (*this);
              };
              MyReverseiterator &operator--()
              {
                     ptr++;
                     return (*this);
              };
              MyReverseiterator operator--(int)
              {
                     MyReverseiterator tmp(*this);
                     ptr++;
                     return (tmp);
              };
              MyReverseiterator &operator-=(difference_type n)
              {
                     ptr += n;
                     return (*this);
              };
              reference operator*() const
              {
                     return (*(--base()));
              };
              reference operator[](difference_type n) const
              {
                     return *(ptr + n);
              };

              template <class Iterator>
              friend bool operator==(const MyReverseiterator<Iterator> &lhs,
                                     const MyReverseiterator<Iterator> &rhs);

              template <class Iterator>
              friend bool operator>=(const MyReverseiterator<Iterator> &lhs,
                                     const MyReverseiterator<Iterator> &rhs);

              template <class Iterator>
              friend bool operator!=(const MyReverseiterator<Iterator> &lhs,
                                     const MyReverseiterator<Iterator> &rhs);

              template <class Iterator>
              friend bool operator<=(const MyReverseiterator<Iterator> &lhs,
                                     const MyReverseiterator<Iterator> &rhs);

              template <class Iterator>
              friend bool operator>(const MyReverseiterator<Iterator> &lhs,
                                    const MyReverseiterator<Iterator> &rhs);

              template <class Iterator>
              friend bool operator<(const MyReverseiterator<Iterator> &lhs,
                                    const MyReverseiterator<Iterator> &rhs);

              template <class Iterator>
              friend MyReverseiterator<Iterator> operator+(
                  typename MyReverseiterator<Iterator>::difference_type n,
                  const MyReverseiterator<Iterator> &rev_it);

              template <class Iterator>
              friend MyReverseiterator<Iterator> operator-(
                  typename MyReverseiterator<Iterator>::difference_type n,
                  const MyReverseiterator<Iterator> &rev_it);
       };
       template <class Iterator>
       bool operator==(const MyReverseiterator<Iterator> &lhs, const MyReverseiterator<Iterator> &rhs)
       {
              return (lhs.ptr == rhs.ptr);
       };

       template <class Iterator>
       bool operator>=(const MyReverseiterator<Iterator> &lhs, const MyReverseiterator<Iterator> &rhs)
       {
              return (lhs.ptr >= rhs.ptr);
       };

       template <class Iterator>
       bool operator!=(const MyReverseiterator<Iterator> &lhs, const MyReverseiterator<Iterator> &rhs)
       {
              return (lhs.ptr != rhs.ptr);
       };

       template <class Iterator>
       bool operator<=(const MyReverseiterator<Iterator> &lhs, const MyReverseiterator<Iterator> &rhs)
       {
              return (lhs.ptr <= rhs.ptr);
       };

       template <class Iterator>
       bool operator>(const MyReverseiterator<Iterator> &lhs, const MyReverseiterator<Iterator> &rhs)
       {
              return (lhs.ptr > rhs.ptr);
       };

       template <class Iterator>
       bool operator<(const MyReverseiterator<Iterator> &lhs, const MyReverseiterator<Iterator> &rhs)
       {
              return (lhs.ptr < rhs.ptr);
       };

       template <class Iterator>
       MyReverseiterator<Iterator> operator+(typename MyReverseiterator<Iterator>::difference_type n, const MyReverseiterator<Iterator> &rev_it)
       {
              MyReverseiterator<Iterator> tmp(rev_it.ptr);
              tmp -= n;
              return (tmp);
       };

       template <class Iterator>
       MyReverseiterator<Iterator> operator-(typename MyReverseiterator<Iterator>::difference_type n, const MyReverseiterator<Iterator> &rev_it)
       {
              MyReverseiterator<Iterator> tmp(rev_it.ptr);
              tmp += n;
              return (tmp);
       };
}

#endif // !VECTOR_HPP
