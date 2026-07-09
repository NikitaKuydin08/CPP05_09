/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-08 12:03:11 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-08 12:03:11 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

static const std::string className = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(className, 25, 5), _target("Home") {
    std::cout << className << " Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(className, 25, 5), _target(target) {
    std::cout << className << " Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target) {
    std::cout << className << " Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    std::cout << className << " Copy assignment operator called" << std::endl;
    if (this == &copy) return (*this);
    setIsSigned(copy.getIsSigned());
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << className << " Destructor called" << std::endl; 
}

const std::string PresidentialPardonForm::getTarget(void) const {
    return (this->_target);
}

void PresidentialPardonForm::doAction(void) const {
    std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
