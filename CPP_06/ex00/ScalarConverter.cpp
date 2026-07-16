/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-16 10:59:17 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-16 10:59:17 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    (void)copy;
    return (*this);
}

ScalarConverter::~ScalarConverter(void) { }

static void ScalarConverter::convert(const std::string toConvert) {
    if ()
}