/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-16 10:55:31 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-16 10:55:31 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2)
        std::cout << "Wrong number of arguments" << std::endl;
    ScalarConverter::convert(argv[1]);
}