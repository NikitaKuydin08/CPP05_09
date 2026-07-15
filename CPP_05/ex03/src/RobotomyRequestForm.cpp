/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormtomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-08 12:03:09 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-08 12:03:09 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

static const std::string className = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(className, 72, 45), _target("Home") {
    std::cout << className << " Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(className, 72, 45), _target(target) {
    std::cout << className << " Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {
    std::cout << className << " Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    std::cout << className << " Copy assignment operator called" << std::endl;
    if (this == &copy) return (*this);
    setIsSigned(copy.getIsSigned());
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << className << " Destructor called" << std::endl; 
}

const std::string RobotomyRequestForm::getTarget(void) const {
    return (this->_target);
}

void RobotomyRequestForm::doAction(void) const {
    if ((rand() % 2) == 0)
        std::cout << "DRRRR... DRRRR.... " << getTarget() << " has been robotomized successfully.\n";
    else
        std::cout << getTarget() << " robotomy failed request." << std::endl;
}
