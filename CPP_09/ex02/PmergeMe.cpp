/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:40:21 by nkuydin           #+#    #+#             */
/*   Updated: 2026/09/15 03:18:41 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <vector>
#include <sstream>
#include <iostream>

bool already_exists(int num, std::vector<int> victor) {
    std::vector<int>::iterator it;
    for (it = victor.begin(); it != victor.end(); ++it) {
        if (num == *it)
            return (true);
    }
    return (false);
}

std::vector<int> check_input(int argc, char **argv) {
    std::vector<int> original;
    for (int i = 1; i < argc; i++) {
        std::istringstream ss(argv[i]);
        std::string token;
        int Num;
        while (ss >> token) {
            std::istringstream what(token);
            if (!(what >> Num) || Num < 0)
                throw(std::runtime_error("Not a valid integer sequence."));
            std::string leftover;
            if (what >> leftover)
                throw(std::runtime_error("Not a valid integer sequence."));
            if (already_exists(Num, original))
                throw(std::runtime_error("Duplicates are not allowed."));
            original.push_back(Num);
        }
    }
    if (original.size() < 2)
        throw(std::runtime_error("Wrong number of integers, less than 2."));
    return (original);
}

void print_vector_seq(const std::vector<int>& some_victor) {
    std::vector<int>::const_iterator it;
    for (it = some_victor.begin(); it != some_victor.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
