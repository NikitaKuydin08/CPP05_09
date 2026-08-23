/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-22 12:35:26 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-22 12:35:26 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
// #include <vector>
#include <algorithm>
#include <iostream>

//  - std::find() is used to find the first occurrence of a given value
// in a specified range. 
//  - std::distance() is used to get a number of increments needed to go from
// first to last. (numebr of elements between two iterators). What in our
// case position of the required integer.

class NoOccurrence : public std::exception {
    public:
        virtual const char* what() const throw() {
            return ("No occurrence was found");
        }
};

// Implementation required by subject - Any sequence containers
template <typename Container>
int easyfind(const Container& c, int number) {
    if (c.empty())  
        throw(NoOccurrence());

    typename Container::value_type::iterator it;

    it = std::find(c.begin(), c.end(), number);
    if (it != c.end())
        return (std::distance(c.begin(), it));
    throw(NoOccurrence());
}

// Implementation for the single container std::vector
// template <typename T>
// int easyfind(T container, int number) {
//     if (container.empty())
//         throw (NoOccurrence());
    
//     std::vector<int>::iterator it;

//     it = std::find(container.begin(), container.end(), number);
//     if (it != container.end())
//         return (std::distance(container.begin(), it));
//     throw(NoOccurrence());
// }