/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 06:46:37 by nkuydin           #+#    #+#             */
/*   Updated: 2026/09/04 01:25:59 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2)
    {
        std::cerr << "Error: could not open file. Correct use: ./btc path_to_file" << std::endl;
        return (false);
    }

    try {
        BitcoinExchange::fill_map();
        BitcoinExchange::exchange(argv[1]);
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }   
}

/*
    date | value
    2011-01-03 | 3 // passed the check, did multiplication, printed the line
    2011-01-03 | 2
    2011-01-03 | 1
    2011-01-03 | 1.2
    2011-01-09 | 1
    2012-01-11 | -1 // failed check, printed the error line
    2001-42-42
    2012-01-11 | 1
    2012-01-11 | 2147483648
*/

/*
    $> ./btc input.txt
    2011-01-03 => 3 = 0.9
    2011-01-03 => 2 = 0.6
    2011-01-03 => 1 = 0.3
    2011-01-03 => 1.2 = 0.36
    2011-01-09 => 1 = 0.32
    Error: not a positive number.
    Error: bad input => 2001-42-42
    2012-01-11 => 1 = 7.1
    Error: too large a number.
*/