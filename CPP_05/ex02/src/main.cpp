/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-29 10:23:11 by nkuydin           #+#    #+#             */
/*   Updated: 2026-06-29 10:23:11 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int main(void) {
    try {
        Bureaucrat bur("Maxim", 136);
        ShrubberyCreationForm shrubbery("Monkey");
        std::cout << shrubbery << std::endl;
        bur.signForm(shrubbery);
        bur.executeForm(shrubbery);
        std::cout << shrubbery << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // try {
    //     Bureaucrat crat("David", 44);
    //     RobotomyRequestForm robot("Groot");
    //     std::cout << crat << std::endl;
    //     std::cout << robot << std::endl;
    //     crat.signForm(robot);
    //     crat.executeForm(robot);
    //     std::cout << robot << std::endl;
    // }
    // catch (const std::exception &e) {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }

    // try {
    //     Bureaucrat Bra;
    //     PresidentialPardonForm president;
    //     std::cout << Bra << std::endl;
    //     std::cout << president << std::endl;
    //     Bra.signForm(president);
    //     Bra.executeForm(president);
    //     std::cout << president << std::endl;

    // }
    // catch (const std::exception &e) {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }

    return 0;
}