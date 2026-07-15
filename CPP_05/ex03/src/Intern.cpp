/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-09 13:05:16 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-09 13:05:16 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static const std::string className = "Intern";

Intern::Intern(void) {
    std::cout << className << " Default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy) {
    (void)copy;
    std::cout << className << " Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& copy) {
    std::cout << className << " Copy assignment operator called" << std::endl;
    if (this == &copy) return (*this);
    (void)copy;
    return (*this);
}

Intern::~Intern(void) {
    std::cout << className << " Destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string _name, const std::string _target) {
    std::string form_name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    int i = 0;
    for (; i < 3; i++)
    {
        if (_name == form_name[i])
            break ;
    }

    switch (i) {
        case (0):
            std::cout << "Intern creates " << _name << std::endl;
            return (new ShrubberyCreationForm(_target));
        case (1):
            std::cout << "Intern creates " << _name << std::endl;
            return (new RobotomyRequestForm(_target));
        case (2):
            std::cout << "Intern creates " << _name << std::endl;
            return (new PresidentialPardonForm(_target));
        default:
            std::cout << "Provided form name doesn't exist" << std::endl;
            break ;
    }
    return (NULL);
}