/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-08 09:09:43 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-08 09:09:43 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cerrno>

static const std::string className = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(className, 145, 137), _target("Home") {
    std::cout << className << " Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(className, 145, 137), _target(target) {
    std::cout << className << " Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {
    std::cout << className << " Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    std::cout << className << " Copy assignment operator called" << std::endl;
    if (this == &copy) return (*this);
    setIsSigned(copy.getIsSigned());
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << className << " Destructor called" << std::endl; 
}

const std::string ShrubberyCreationForm::getTarget(void) const {
    return (this->_target);
}

void ShrubberyCreationForm::doAction(void) const {
    std::fstream TreeFile((getTarget() + "_shrubbery").c_str(), std::ios::out);
    if (!TreeFile)
        throw (std::runtime_error("error: " + std::string(strerror(errno))));
    TreeFile << "       ###\n" \
                "      #o###\n" \
                "    #####o###\n" \
                "   #o#\'#|#'###\n" \
                "    ###\'|'#o#\n" \
                "     # }|{  #\n" \
                "       }|{\n";
    TreeFile.close();
}
