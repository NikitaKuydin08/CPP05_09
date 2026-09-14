/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-11 10:27:45 by nkuydin           #+#    #+#             */
/*   Updated: 2026-09-11 10:27:45 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <sstream>
#include <string>
#include <iostream>

static int count = 0;
int odd = 0;

// 1) make pair.
// 

template <typename Pairs>
void print_pairs(const Pairs& pairs) {
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "{ " << pairs[i].first << ", " << pairs[i].second << " }" << std::endl;
    }
}

//-------------------------- FUNCTIONS FROM MAIN ------------------------------//
// bool PmergeMe::already_exists(int num) {
//     std::vector<int>::iterator it;
//     for (it = _original.begin(); it != _original.end(); ++it) {
//         if (num == *it)
//             return (true);
//     }
//     return (false);
// }

// PmergeMe::PmergeMe(int argc, char** argv) {
//     for (int i = 1; i < argc; i++) {
//         std::istringstream ss(argv[i]);
//         std::string token;
//         int Num;
//         while (ss >> token) {
//             std::istringstream what(token);
//             if (!(what >> Num) || Num < 0)
//                 throw(std::runtime_error("Not a valid integer sequence."));
//             std::string leftover;
//             if (what >> leftover)
//                 throw(std::runtime_error("Not a valid integer sequence."));
//             if (already_exists(Num))
//                 throw(std::runtime_error("Duplicates are not allowed."));
//             _original.push_back(Num);
//         }
//     }
// }

template <typename Container, typename Pair>
void make_pairs(const Container& cont, Pair& pa) {
    typename Container::const_iterator it1;
    typename Container::const_iterator it2;
    typename Container::const_iterator end;
    end = cont.end();
    if (cont.size() % 2 != 0) { end = cont.end() - 1; odd = cont.back(); }
    for (it1 = cont.begin(), it2 = cont.begin() + 1; it2 < end; it1 += 2, it2 += 2, count++) {
        if (*it1 < *it2)
            pa.push_back(std::make_pair(*it1, *it2));
        else
            pa.push_back(std::make_pair(*it2, *it1));
    }
}

//-------------------------- TWO SORTING FUNCTIONS -----------------------------//
template <typename Container>
void merge_insertion(const Container& cont) {
    std::vector::std::pair<typename Container::value_type, 
        Container::value_type> pairs;
    make_pairs(cont, pairs);
    if (pairs.size() > 1)
        merge_insertion();
    // std::cout << "(1) Pairing expected [n/2] - " << victor.size() / 2 << ", we got - " << count << std::endl;
    // std::cout << "Vector's pairs - ";
    // print_pairs(pair);

}


/*
template <typename Container>
Container merge_insertion(const Container& cont);

void print_vector_seq(std::vector<int> some_victor) {
    std::vector<int>::iterator it;
    for (it = some_victor.begin(); it != some_victor.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error. Correct usage of program: ./PmergeMe <positive sequence of ints>." << std::endl;
        return (false);
    }
    try {
        PmergeMe mergeme(argc, argv);
        std::cout << RED << "Before: ";
        print_vector_seq(mergeme.getVector());
        std::cout << RESET;

        clock_t start, end;
        start = clock();
        // std::vector<int> victor(_original.begin(), _original.end());
        std::vector<int> victor = mergeme.sort_victor();
        end = clock();
        double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

        start = clock();
        // std::deque<int> deque = mergeme.sort_deque();
        std::deque<int> = merge_insertion()
        end = clock();
        double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

        std::cout << "After: ";
        print_vector_seq(victor);
        std::cout << "Time to process a range of " << victor.size() <<
            " elements with std::[vector] : " << vector_time << " us" << std::endl;
        std::cout << "Time to process a range of " << deque.size() <<
            " elements with std::[deque] : " << deque_time << " us" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (false);
    }
    return (true);
}
*/