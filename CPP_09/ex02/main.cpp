/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-04 17:10:27 by nkuydin           #+#    #+#             */
/*   Updated: 2026-09-04 17:10:27 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <vector>
#include <deque>
#include <list>
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error. Correct usage of program: ./PmergeMe <positive sequence of ints>." << std::endl;
        return (false);
    }
    try {
        std::deque<unsigned int> _deque;
        std::vector<unsigned int> _vector;
        std::list<unsigned int> _list; 
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (false);
    }
    return (true);
}

/*
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe`shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe`jot -r 3000 1 100000 | tr'\n' ' '`
[..
*/