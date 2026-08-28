/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:36:41 by nkuydin           #+#    #+#             */
/*   Updated: 2026/08/28 19:03:57 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define PURPLE "\033[0;35m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

#include <stack>
#include <deque>
// #include <iterator>

// template <class T, class Container=std::deque<T> >
// class MutantStack : public std::stack<T, Container> {
//     public:
//         MutantStack<T, Container>(void) : std::stack<T, Container>() {};
//         MutantStack<T, Container>(const MutantStack<T, Container>& copy) : std::stack<T, Container>(copy) {};
//         MutantStack<T, Container>& operator=(const MutantStack<T, Container>& copy) {
//             if (this != copy) { this->c = copy.c; }
//             return (*this);
//         }
//         ~MutantStack<T, Container>(void) {};

//         typedef typename std::stack<T, Container>::container_type::iterator iterator;
//         typename std::stack<T, Container>::container_type::const_iterator const_iterator;
//         typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;

//         iterator begin(void) { return (this->c.begin()); }
//         iterator end(void) { return (this->c.end()); }
//         reverse_iterator rbegin(void) { return (this->c.rbegin()); }
//         reverse_iterator rend(void) { return (this->c.rend()); }
// };


template <typename T>
class MutantStack {
    protected:
        std::deque<T> deque;

    public:
        MutantStack(void);
        MutantStack(const MutantStack& copy);
        MutantStack& operator=(const MutantStack& copy);
        ~MutantStack(void);

        typedef typename std::deque<T>::size_type size_type;
        typedef typename std::deque<T>::value_type value_type;
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::reverse_iterator reverse_iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

        size_type size() const { return(deque.size()); }
        bool empty() { return ((deque.empty()) ? true : false); }
        void push(value_type value) { deque.push_back(value); }
        void pop(void) { deque.pop_back(); }
        T& top(void) { return (deque.back()); }

        iterator begin(void) {return(deque.begin()); }
        iterator end(void) { return(deque.end()); }
        reverse_iterator rbegin(void) { return(deque.rbegin()); }
        reverse_iterator rend(void) { return(deque.rend()); }
        const_iterator begin(void) const { return(deque.begin()); }
        const_iterator end(void) const { return(deque.end()); }

        operator std::stack<T, std::deque<T> > () {
            std::stack<T, std::deque<T> > newStack(deque);
            return (newStack);
        }
        operator const std::stack<T, std::deque<T> > () const {
            std::stack<T, std::deque<T> > newStack(deque);
            return (newStack);
        }
        const std::deque<T>& getDeque(void) const { return (this->deque); }
};

#include "MutantStack.tpp"

#endif