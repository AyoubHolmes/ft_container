#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <vector>
#include <iostream>
namespace ft
{
    /* 
		iterator_type	Iterator	Iterator's type
		iterator_category	iterator_traits<Iterator>::iterator_category	Preserves Iterator's category
		value_type	iterator_traits<Iterator>::value_type	Preserves Iterator's value type
		difference_type	iterator_traits<Iterator>::difference_type	Preserves Iterator's difference type
		pointer	iterator_traits<Iterator>::pointer	Preserves Iterator's pointer type
		reference	iterator_traits<Iterator>::reference	Preserves Iterator's reference type

	 */
    /* template< class Iter >
    struct iterator_traits {

    };

    template< class T >
    struct iterator_traits<T*> {

    };
 */
	template < class T>
	class Myiterator
	{
        public:
            /* **** MEMBER TYPES ***** */
            typedef T iterator_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;

        private:
            iterator_type ptr;

        public:
            Myiterator(): ptr(NULL) {
            };
            Myiterator(iterator_type t): ptr(t) {};
            template <class Iter>
            Myiterator(Myiterator<Iter>& i): ptr(i.base()) {};
            iterator_type base() {
                return (ptr);
            };
            Myiterator operator+ (difference_type n) const {
                return ();
            };
            Myiterator& operator++();
            Myiterator  operator++(int);
            Myiterator& operator+= (difference_type n);
            Myiterator operator- (difference_type n) const;
            Myiterator& operator--();
            Myiterator  operator--(int);
            Myiterator& operator-= (difference_type n);
            pointer operator->() const;
            reference operator*() const;
            reference operator[] (difference_type n) const;
           
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
            friend Myiterator<Iterator> operator+ (
                    typename Myiterator<Iterator>::difference_type n,
             const Myiterator<Iterator>& rev_it);
            
            template <class Iterator>
            friend Myiterator<Iterator> operator- (
                    typename Myiterator<Iterator>::difference_type n,
             const Myiterator<Iterator>& rev_it);
    };

}

#endif // !VECTOR_HPP
