/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-05 11:27:29 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-05 11:27:29 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

Base::~Base(void) { }

Base* generate(void) {

    switch (rand() % 3) {
        case (0) :
            return (new A());
        case (1) :
            return (new B());
        case (2) :
            return (new C());
        default:
            return (NULL);
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A";
    else if (dynamic_cast<B*>(p))
        std::cout << "B";
    else if (dynamic_cast<C*>(p))
        std::cout << "C";
    std::cout << std::endl;
}

void identify(Base &p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A";
    }
    catch (const std::exception &b) {};
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B";
    }
    catch (const std::exception &b) {};
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C";
    }
    catch (const std::exception &b) {};
    std::cout << std::endl;
}