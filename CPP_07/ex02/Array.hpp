/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-12 04:42:28 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-12 04:42:28 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstdlib>
#include <sys/time.h>

template <typename T>
class Array {
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array<T>& copy);
        Array<T>& operator=(const Array<T>& copy);
        ~Array(void);

        class NumOutOfBound : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "The program tried to access an element out of bound";
                }
        };

        T& operator[](unsigned int n) const;

        unsigned int size(void) const { return (this->_n); }
        T* getArr(void) const { return this->_arr; }
    private:
        unsigned int _n;
        T* _arr;
};

template <typename T>
std::ostream &operator<<(std::ostream &oss, const Array<T>& ref);

#include "Array.tpp"

#endif