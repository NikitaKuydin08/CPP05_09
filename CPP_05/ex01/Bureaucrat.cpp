/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 07:51:47 by nkuydin           #+#    #+#             */
/*   Updated: 2026/07/15 18:56:39 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Form.hpp"
#include <iostream>
#include <sstream>

static const std::string className = "Bureaucrat";

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(149) {
    std::cout << className << " Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());

    setGrade(grade);
    std::cout << className << " Parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
    std::cout << className << " Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
    std::cout << className << " Copy assignment operator called" << std::endl;
    if (this == &copy) return (*this);
    setGrade(copy.getGrade());
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << className << " Destructor called" << std::endl;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName()
        << " successfully." << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << form.getName() 
        << " because " << e.what() << std::endl;
    }
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
    if (temp == 1)
        throw (Bureaucrat::GradeTooHighException());
    temp--;
    std::cout << "Incremented successfully." << std::endl; 
    setGrade(temp);
}

void Bureaucrat::decrement_grade(void) {
    int temp = getGrade();
    if (temp == 150)
        throw (Bureaucrat::GradeTooLowException());
    temp++;
    std::cout << "Decremented successfully." << std::endl; 
    setGrade(temp);
}

const std::string Bureaucrat::getName(void) const { return (this->_name); }

void Bureaucrat::setGrade(int grade) { this->_grade = grade; }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}
