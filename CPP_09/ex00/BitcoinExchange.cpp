/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-31 08:08:40 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-31 08:08:40 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>

void printError(const char* message) {
    std::cout << "Error: " << message << std::endl;
}

void BitcoinExchange::init_n_check(char* file) {
    std::fstream ReadFile(file, std::ios::in);
    std::fstream ReadDB("data.csv", std::ios::in);
    if (!ReadFile.is_open() || !ReadDB.is_open())
        throw(NotOpen());
    std::string line;
    std::string line2;
    if (!getline(ReadDB, line) || line.compare("date,exchange_rate"))
        throw(std::runtime_error("DB empty or invalid format"));
    
    ReadDB.close();
}

void BitcoinExchange::exchange(void) {

}
