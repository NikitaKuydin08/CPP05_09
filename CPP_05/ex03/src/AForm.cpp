/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-07 01:57:09 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-07 01:57:09 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>
#include <sstream>

static const std::string className = "AForm";

AForm::AForm(void) : _name("Default"), _isSigned(false), _toSign(30), _toExec(70) {
    std::cout << className << " Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int toSign, const int toExec) : _name(name), 
        _isSigned(false), _toSign(toSign), _toExec(toExec) {

    if (toExec < 1 || toSign < 1)
        throw(AForm::GradeTooHighException());
    else if (toExec > 150 || toSign > 150)
        throw(AForm::GradeTooLowException());
    std::cout << className << " Parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _isSigned(copy._isSigned), 
        _toSign(copy._toSign), _toExec(copy._toExec) {
    std::cout << className << " Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy) {
    std::cout << className << " Copy assignment operator called" << std::endl;
    if (this == &copy) return (*this);
    setIsSigned(copy.getIsSigned());
    return (*this);
}

AForm::~AForm(void) {
    std::cout << className << " Destructor called" << std::endl; 
}

void AForm::beSigned(const Bureaucrat& other) {
    if (other.getGrade() <= this->getToSign())
        setIsSigned(true);
    else
        throw (AForm::GradeTooLowException());
}

void AForm::doAction(void) const {
    std::cout << "AForm do action never calls" << std::endl;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (_isSigned == false)
        throw (AForm::FormIsSigned());
    if (executor.getGrade() > getToExec())
        throw (AForm::GradeTooLowException());

    doAction();
}

std::string AForm::info(void) const {
    std::ostringstream oss;

    oss << this->getName() << ", grade required to sign - " << this->getToSign()
    << ", grade required to exec - " << this->getToExec() << "; this AForm is signed - "
    << this->getIsSigned();
    return (oss.str());
}

std::ostream& operator<<(std::ostream &o, const AForm& other) {
    o << other.info();
    return (o);
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Required grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Required grade is too low!");
}

const char* AForm::FormIsSigned::what() const throw() {
    return ("Form isn't signed.");
}

void AForm::setIsSigned(bool Signed) { this->_isSigned = Signed; }

const std::string AForm::getName(void) const { return (this->_name); }
int AForm::getToSign(void) const { return (this->_toSign); }
int AForm::getToExec(void) const { return (this->_toExec); }
bool AForm::getIsSigned(void) const { return (this->_isSigned); }