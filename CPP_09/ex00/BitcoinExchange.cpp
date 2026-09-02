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
#include <sstream>
#include <ctime>

// printing function to print input file errors 
void printError(const char* message) {
    std::cout << "Error: " << message << std::endl;
}

std::map<std::string, float> _data;

bool check_value_format(std::string value, float& res) {
    char *end_ptr;

    double temp_res = std::strtod(value.c_str(), &end_ptr);
    if (*end_ptr != '\0' || temp_res < 0)
        return (false);
    res = static_cast<float>(temp_res);
    return (true);
}

bool check_date_format(std::string dateStr) {
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
        return (false);

    char dash;
    std::stringstream ss(dateStr);

    struct tm Date;
    std::memset(&Date, 0, sizeof(Date));
    struct tm NewDate;

    ss >> Date.tm_year >> dash >> Date.tm_mon >> dash >> Date.tm_mday;
    Date.tm_year -= 1900; Date.tm_mon -= 1;
    Date.tm_hour = 1;
    Date.tm_min = 0;
    Date.tm_sec = 0;

    NewDate = Date;
    mktime(&NewDate);
    if (
        Date.tm_year == NewDate.tm_year &&
        Date.tm_mon == NewDate.tm_mon &&
        Date.tm_mday == NewDate.tm_mday
    )
        return (true);
    return (false);
}

// std::pair<map::iterator, bool > temp = _data.insert(std::make_pair(line.substr(0, 10), line.substr(11)));
bool make_pairs(std::string line, std::string& exception) {
    std::string date = line.substr(0, 10);
    if (!check_date_format(date)) {
        exception = "Database's date format is invalid => " + date;
        return (false);
    }
    float fvalue;
    std::string value = line.substr(11);
    if (!check_value_format(value, fvalue)) {
        exception = "Database's value format is invalid => " + value;
        return (false);
    }
    if (_data.insert(std::make_pair(date, fvalue)).second == false) {
        exception = "Insertion to container failed. Duplicate date in database => " + date;
        return (false);
    }
    return (true);
}

// check database, and exctract data key-value into map container
void BitcoinExchange::fill_map(void) {
    std::string exception;
    std::fstream ReadDB("data.csv", std::ios::in);
    if (!ReadDB.is_open())
        throw(NotOpen());
    std::string line;
    if (!std::getline(ReadDB, line) || line.compare("date,exchange_rate"))
        throw(std::runtime_error("DB empty or invalid format"));
    while (std::getline(ReadDB, line)) {
        if (!make_pairs(line, exception)) {
            ReadDB.close();
            throw (std::runtime_error(exception));
        }
    }
    ReadDB.close();
}

// check input file and do multiplication
void BitcoinExchange::exchange(char* file) {
    std::fstream ReadFile(file, std::ios::in);
    if (!ReadFile.is_open())
        throw(NotOpen());
    
    ReadFile.close();
}
