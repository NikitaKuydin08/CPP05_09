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
#include "Intern.hpp"

#include <iostream>

int main(void) {

    Intern someRandomIntern;
    AForm* rrf;

    // rrf = someRandomIntern.makeForm("UndefinedFrom", "David");
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << rrf << std::endl;

    delete rrf;
    return 0;
}