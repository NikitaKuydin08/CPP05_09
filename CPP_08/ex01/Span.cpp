/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-25 11:34:48 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-25 11:34:48 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

// shortestSpan() - two numebrs, so that difference in their values were the minimal
// across all others pair of numbers
// longestSpan() - reverse, the number/difference is biggest across all other pairs
// of numbers
Span::Span(void) {
    this->_N = 0;
    std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _N(n) { }

Span::Span(const Span& copy) : _vn(copy._vn), _N(copy._N) { }

Span::~Span(void) {}

Span& Span::operator=(const Span& copy) {
    if (this == &copy)
        return (*this);
    this->_vn = copy._vn;
    this->_N = copy._N;
    return (*this);
}

void Span::addNumber(int n) {
    if (this->_vn.size() == this->_N)
        throw (Span::Full());
    this->_vn.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    if (this->_vn.size() + std::distance(first, last) > this->_N)
        throw (Span::Full());
    this->_vn.insert(this->_vn.end(), first, last);
}

void Span::recursion(std::vector<int>::iterator first, std::vector<int>::iterator y, int& difference) {
    if (this->_vn.end() == y)
        return ;
    int new_difference = abs(*first - *y);
    if (new_difference < difference)
        difference = new_difference;
    recursion(first, ++y, difference);
}

int Span::shortestSpan(void) {
    if (this->_vn.empty() || this->_vn.size() == 1)
        throw (Span::NoSpan());
    int shortestSpan = std::numeric_limits<int>::max();
    std::vector<int>::iterator iterator;
    for (iterator = this->_vn.begin(); iterator != this->_vn.end(); iterator++)
        recursion(iterator, iterator + 1, shortestSpan);
    return (shortestSpan);
}

int Span::longestSpan(void) {
    if (this->_vn.empty() || this->_vn.size() == 1)
        throw (Span::NoSpan());
    return (*std::max_element(this->_vn.begin(), this->_vn.end()) -
        *std::min_element(this->_vn.begin(), this->_vn.end()));
}
