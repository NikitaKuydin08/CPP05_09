/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-05 14:04:40 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-05 14:04:40 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Base.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <iostream>

int main(void) {
    srand(time(NULL));

    Base *base = generate();
    identify(base);
    identify(*base);
}

// int main(void) {
//     Base *base = new A();
//     if (dynamic_cast<A*>(base))
//         std::cout << "Expected output" << std::endl;
//     if (dynamic_cast<B*>(base))
//         std::cout << "Shouldn't print this" << std::endl;
// }