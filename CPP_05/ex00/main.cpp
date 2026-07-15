/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:23:11 by nkuydin           #+#    #+#             */
/*   Updated: 2026/07/15 18:45:38 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int main(void) {
    try {
        Bureaucrat bur("Maxim", 149);
        // Bureaucrat petya("Peter", 151); // failed attempt to initialise
        std::cout << bur << std::endl;
        bur.increment_grade();
        std::cout << bur << std::endl;
        bur.decrement_grade();
        std::cout << bur << std::endl;
        bur.decrement_grade();
        std::cout << bur << std::endl;
        // bur.decrement_grade(); // grade becomes too low
        Bureaucrat crat;
        crat = bur;
        std::cout << crat << std::endl;
        crat.increment_grade();
        std::cout << crat << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}