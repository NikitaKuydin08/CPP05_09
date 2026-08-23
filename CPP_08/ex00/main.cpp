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

int main(void) {
    try {
        std::vector<int> vec1;
        // vec1.push_back(69);
        // vec1.push_back(42);
        // vec1.push_back(12);
        // vec1.push_back(50);
        // vec1.push_back(50);
        // vec1.push_back(69);

        // Finds occurrence
        int first = easyfind(vec1, 50);
        std::cout << "First occurrence: " << first << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}