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
#include "Form.hpp"

#include <iostream>

int main(void) {
    try {
        Bureaucrat bur("Maxim", 25);
        std::cout << bur << std::endl;
        Form form("Form1", 30, 100);
        std::cout << form << std::endl;
        bur.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}