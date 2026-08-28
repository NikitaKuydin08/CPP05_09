/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-23 09:57:26 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-23 09:57:26 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void) {
    try {
        // Vector
        std::vector<int> vec1;
        vec1.push_back(69);
        vec1.push_back(42);
        vec1.push_back(12);
        vec1.push_back(50);
        vec1.push_back(50);
        vec1.push_back(69);

        int first_vector = easyfind(vec1, 50);
        std::cout << "Vector's first occurrence: " << first_vector << std::endl;

        // List
        std::list<int> list1;
        list1.push_back(20);
        list1.push_back(50);
        list1.push_back(67);
        list1.push_back(5);

        int first_list = easyfind(list1, 67);
        std::cout << "List's first occurrence: " << first_list << std::endl;

        // Deque
        std::deque<int> deque1;
        deque1.push_back(80);
        deque1.push_back(90);
        deque1.push_back(50);
        deque1.push_front(70);
        deque1.push_front(60);
        deque1.push_front(50);

        int first_deque = easyfind(deque1, 50);
        // int no_deque = easyfind(deque1, 1000);
        // std::cout << no_deque << std::endl;
        std::cout << "Deque's first occurrence: " << first_deque << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}