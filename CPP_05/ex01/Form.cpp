/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 01:57:09 by nkuydin           #+#    #+#             */
/*   Updated: 2026/07/15 18:55:50 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

static const std::string className = "Form";

Form::Form(void) : _name("Default"), _isSigned(false), _toSign(30), _toExec(70) {
    std::cout << className << " Default constructor called" << std::endl;
}

Form::Form(const std::string name, const int toSign, const int toExec) : _name(name), 
        _isSigned(false), _toSign(toSign), _toExec(toExec) {

    if (toExec < 1 || toSign < 1)
        throw(Form::GradeTooHighException());
    else if (toExec > 150 || toSign > 150)
        throw(Form::GradeTooLowException());
    std::cout << className << " Parameterized constructor called" << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _isSigned(copy._isSigned), 
        _toSign(copy._toSign), _toExec(copy._toExec) {
    std::cout << className << " Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& copy) {
    std::cout << className << " Copy assignment operator called" << std::endl;
    if (this == &copy) return (*this);
    setIsSigned(copy.getIsSigned());
    return (*this);
}

Form::~Form(void) {
    std::cout << className << " Destructor called" << std::endl; 
}

void Form::beSigned(const Bureaucrat& other) {
    if (other.getGrade() <= this->getToSign())
        setIsSigned(true);
    else
        throw (Form::GradeTooLowException());
}

std::string Form::info(void) const {
    std::ostringstream oss;

    oss << this->getName() << ", grade required to sign - " << this->getToSign()
    << ", grade required to exec - " << this->getToExec() << "; this form is signed - "
    << this->getIsSigned();
    return (oss.str());
}

std::ostream& operator<<(std::ostream &o, const Form& other) {
    o << other.info();
    return (o);
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Required grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Required grade is too low!");
}

void Form::setIsSigned(bool Signed) { this->_isSigned = Signed; }

const std::string Form::getName(void) const { return (this->_name); }
int Form::getToSign(void) const { return (this->_toSign); }
int Form::getToExec(void) const { return (this->_toExec); }
bool Form::getIsSigned(void) const { return (this->_isSigned); }