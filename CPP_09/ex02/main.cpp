/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:51:09 by nkuydin           #+#    #+#             */
/*   Updated: 2026/09/15 04:00:32 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque> 
#include <iostream>

int recursion_count = 0;

template <typename Container>
void order_of_insertion(Container& cont, size_t size_pend) {

    if (size_pend == 0)
        return ;

    size_t current_jacob = 3;
    size_t previous_jacob = 1;

    size_t group_start = 0;

    while (group_start < size_pend) {

        size_t group_size = current_jacob - previous_jacob;
        size_t group_end = group_start + group_size;

        if (group_end > size_pend)
            group_end = size_pend;

        size_t index = group_end;
        while (index > group_start) {
            --index;
            cont.push_back(index);
        }

        size_t new_jacob = current_jacob + 2 * previous_jacob; 
        previous_jacob = current_jacob;
        current_jacob = new_jacob;

        group_start = group_end;
    }

}

void merge_insert_vector(std::vector<int>& victor) {
    std::vector<std::pair<int, int> > pairs;
    DEBUG_MSG("\nRecursion is of level - " << recursion_count);
    int leftover = 0;
    if (victor.size() % 2 != 0) {
        leftover = victor.back();
        victor.pop_back();
    }

    for (size_t i = 0; i + 1 < victor.size(); i += 2) {
        if (victor[i] < victor[i + 1])
            pairs.push_back(std::make_pair(victor[i], victor[i + 1]));
        else
            pairs.push_back(std::make_pair(victor[i + 1], victor[i]));
    }
    debug_pairs("Recursion pairing(b, a)", pairs);
    std::vector<int> main_chain;

    for (size_t i = 0; i < pairs.size(); i++) {
        main_chain.push_back(pairs[i].second);
    }
    DEBUG_MSG("Leftover - " << leftover);
    debug_container("Main chain before next recursion", main_chain);
    recursion_count++;
    if (main_chain.size() > 1)
        merge_insert_vector(main_chain);
    debug_container("Main chain at the end/during stack unwiding", main_chain);

    std::vector<std::pair<int, int> > pend_chain;
    for (size_t i = 0; i < main_chain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (main_chain[i] == pairs[j].second) {
                pend_chain.push_back(pairs[j]);
                break ;
            }}}

    if (leftover != 0)
        pend_chain.push_back(std::make_pair(leftover, -1));
    if (pend_chain.size() > 0) {
        main_chain.insert(main_chain.begin(), pend_chain[0].first);
        DEBUG_MSG("Insert b1 = " << pend_chain[0].first << " at the beggining of main_chain => (< a1)");
        pend_chain.erase(pend_chain.begin());
    }
    // sorted main_chain, ready for pend insertion
    debug_container("Main chain (ready for insertion)", main_chain);
    // b_value to insert to main chain and corresponding a_value
    debug_pairs("Pend chain (b. a)", pend_chain);
    std::vector<int> order;
    order_of_insertion(order, pend_chain.size());
    debug_container("JAcobsthal insertion order", order);
    for (size_t i = 0; i < order.size(); i++) {
        size_t pend_index = order[i];
        int b_value = pend_chain[pend_index].first;
        int a_value = pend_chain[pend_index].second;
        DEBUG_MSG("\nInsert b = " << b_value << " | corresponding to a = " << a_value);
        std::vector<int>::iterator high = main_chain.end();
        if (a_value != -1) { high = std::lower_bound(main_chain.begin(), main_chain.end(), a_value); 
            DEBUG_MSG("Search for an insertion only before a = " << a_value);
        }
        // default - search across the whole main chain (high = main_chain.end())
        std::vector<int>::iterator position = std::lower_bound(main_chain.begin(), high, b_value);
        DEBUG_MSG("Insertion index = " << std::distance(main_chain.begin(), position));
        main_chain.insert(position, b_value);
        DEBUG_MSG(GREEN << "Main Chain after insertion =>" << RESET);
        debug_container("", main_chain);
    }
    victor = main_chain;
}

void merge_insert_deque(std::deque<int>& deque) {
    std::deque<std::pair<int, int> > pairs;

    int leftover = 0;
    if (deque.size() % 2 != 0) {
        leftover = deque.back();
        deque.pop_back();
    }

    for (size_t i = 0; i + 1 < deque.size(); i += 2) {
        if (deque[i] < deque[i + 1])
            pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
        else
            pairs.push_back(std::make_pair(deque[i + 1], deque[i]));
    }
    std::deque<int> main_chain;

    for (size_t i = 0; i < pairs.size(); i++) {
        main_chain.push_back(pairs[i].second);
    }
    if (main_chain.size() > 1)
        merge_insert_deque(main_chain);

    std::deque<std::pair<int, int> > pend_chain;
    for (size_t i = 0; i < main_chain.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (main_chain[i] == pairs[j].second) {
                pend_chain.push_back(pairs[j]);
                break ;
            }}}

    if (leftover != 0)
        pend_chain.push_back(std::make_pair(leftover, -1));
    if (pend_chain.size() > 0) {
        main_chain.insert(main_chain.begin(), pend_chain[0].first);
        pend_chain.erase(pend_chain.begin());
    }
    std::deque<int> order;
    order_of_insertion(order, pend_chain.size());

    for (size_t i = 0; i < order.size(); i++) {
        size_t pend_index = order[i];
        int b_value = pend_chain[pend_index].first;
        int a_value = pend_chain[pend_index].second;
        std::deque<int>::iterator high = main_chain.end();
        if (a_value != -1) { high = std::lower_bound(main_chain.begin(), main_chain.end(), a_value); }
        std::deque<int>::iterator position = std::lower_bound(main_chain.begin(), high, b_value);
        main_chain.insert(position, b_value);
    }
    deque = main_chain;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error. Correct usage of program: ./PmergeMe <positive sequence of ints>." << std::endl;
        return (false);
    }
    try {
        struct timespec start, end;
        std::vector<int> original = check_input(argc, argv);
        std::cout << "Before:  ";
        print_vector_seq(original);

        // clock_t start, end;
        // start = clock();
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        std::vector<int> victor(original.begin(), original.end());
        merge_insert_vector(victor);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
        double vector_time = (end.tv_sec - start.tv_sec) * 1000000.0
            + (end.tv_nsec - start.tv_nsec) / 1000.0;
        // end = clock();
        // double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

        // start = clock();
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        std::deque<int> deque(original.begin(), original.end());
        merge_insert_deque(deque);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
        double deque_time = (end.tv_sec - start.tv_sec) * 1000000.0
            + (end.tv_nsec - start.tv_nsec) / 1000.0;
        // end = clock();
        // double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

        std::cout << "After:   ";
        print_vector_seq(victor);
        std::cout << "Time to process a range of " << victor.size() <<
            " elements with std::[vector] : " << vector_time << " us" << std::endl;
        std::cout << "Time to process a range of " << deque.size() <<
            " elements with std::[deque]  : " << deque_time << " us" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (false);
    }
    return (true);
}

/*
    Usage of test.sh : ./test.sh {number of values(default=3000)} {value - end of the range(from 1 to ?)}
    (generates random not duplicate values)

    ++++++++++++++++.  Usage of Debug Mode -   +++++++++++
    make debug
    ./PmergeMe 57 13 91 34 76 22 48 65 8 39 84 19 72 5 61 97 28 53 11 88 44

    ++++++++++++++++.  Usage of Normal Mode -   +++++++++++
    make default
*/
