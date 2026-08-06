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
#include <cstdlib>
#include <sstream>

int main(int argc, char **argv) {
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    return (0);
}

// int something(std::string tod) {
//     std::stringstream ss;
//     int i = 0;
//     ss << tod;
//     ss >> i;
//     return (i);
// }

// int main(int argc, char **argv) {

//     // char *end_ptr;
//     // std::string str = "-inf36";
//     // double f = strtof(str.c_str(), &end_ptr);
//     // std::cout << f << std::endl;
//     // if (end_ptr)
//     //     std::cout << "Null pointer" << std::endl;
//     (void)argc;
//     // char d = static_cast<char>(-1);
//     // std::cout << d << std::endl;
//     int i = something(argv[1]);
//     std::cout << i << std::endl;
//     std::cout << static_cast<char>(i) << std::endl;
//     return (0);
// }