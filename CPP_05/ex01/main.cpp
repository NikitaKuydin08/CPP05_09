/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:23:11 by nkuydin           #+#    #+#             */
/*   Updated: 2026/07/15 19:05:12 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main(void) {
    try {
        Bureaucrat bur("Maxim", 25);
        std::cout << bur << std::endl;
        Form form("Form1", 30, 100);
        std::cout << form << std::endl;
        bur.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\033[33mUnable to sign -->\033[0m\n";
    try {
        Bureaucrat crat("Peter", 45);
        std::cout << crat << std::endl;
        Form form("Form1", 30, 100);
        std::cout << form << std::endl;
        crat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e) {
         std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}