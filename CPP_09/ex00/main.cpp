/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-31 06:46:37 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-31 06:46:37 by nkuydin          ###   ########.fr       */
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
