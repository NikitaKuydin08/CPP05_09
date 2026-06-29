/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-29 07:51:47 by nkuydin           #+#    #+#             */
/*   Updated: 2026-06-29 07:51:47 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <sstream>

static const std::string className = "Bureaucrat";

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(18) {
    std::cout << className << " Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {

    try {
        setGrade(grade);

        if (this->getGrade() < 1)
            throw "GradeTooHighException";
        else if (this->getGrade() > 150)
            throw "GradeTooLowException";

    std::cout << className << " Constructor successfully called" << std::endl;
    }
    catch (const char* msg) {
        std::cout << "Exception - Bureaucrat::" << msg << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    std::cout << className << " Copy constructor called" << std::endl;
    setGrade(copy.getGrade());
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
    std::cout << className << " Copy assignment operator called" << std::endl;
    if (this == &copy) return (*this);
    setGrade(copy.getGrade());
    return (*this);
}

~Bureaucrat(void) {
    std::cout << className << " Destructor called" << std::endl;
}

std::string Bureaucrat::info(void) const {
    std::ostringstream oss;

    oss << this->getName() << ", bureaucrat grade " << this->getGrade()
    << ".";
    return(oss.str());
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat& clone) {
    o << clone.info();
    return (o);
}

void Bureaucrat::increment_grade(void) {
    int temp = getGrade();
    temp--;
    std::cout << "Incremented successfully." << std::endl; 
    setGrade(temp);
}

void Bureaucrat::decrement_grade(void) {
    int temp = getGrade();
    temp++;
    std::cout << "Decremented successfully." << std::endl; 
    setGrade(temp);
}

const std::string Bureaucrat::getName(void) const { return (this->_name); }

void Bureaucrat::setGrade(int grade) { this->_grade = grade; }

int Bureaucrat::getGrade(void) const { return (this->_grade); }