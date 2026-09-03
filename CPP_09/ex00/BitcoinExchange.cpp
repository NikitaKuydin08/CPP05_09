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

// int compare (size_t pos, size_t len, const string& str) - compare(10, 3, " | ")

bool global_valid = true;
std::map<std::string, float> _data;

// printing function to print input file errors 
void printError(std::string message) {
    std::cout << "Error: " << message << std::endl;
}

void printGoodOutput(std::string& date, float& fvalue) {
    (void)date;
    (void)fvalue;
    std::cout << std::endl;
}

bool check_value_format(std::string value, float& res, bool isInput) {
    char *end_ptr;

    double temp_res = std::strtod(value.c_str(), &end_ptr);
    if (*end_ptr != '\0' || temp_res < 0)
        return (false);
    res = static_cast<float>(temp_res);
    if (isInput && (res <= 0 || res > 1000))
        return (false);
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
    if (!check_value_format(value, fvalue, false)) {
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

void find_t_closest_date(std::string& date) {
    std::map<std::string, float>::iterator low, prev;
    low = _data.lower_bound(date);
    if (low == _data.end())
        std::cout << "When do we hit it?" << std::endl;
    else if (low == _data.begin()) {
        date = low->first;
        return ;
    }
    else {
        prev = std::prev(low);

    }
}

void execute_main_loop(std::string line) {
    if (line.compare(10, 3, " | ") != 0 || (!isdigit(line[13]) && line[13] != '-'))
        return (printError("invalid format of line => " + line));
    std::string date = line.substr(0, 10);
    if (!check_date_format(date))
        return (printError("invalid format of date => " + date));
    float fvalue;
    std::string value = line.substr(13);
    if (!check_value_format(value, fvalue, true))
        return (printError("the value is out of bound => " + value));

    std::map<std::string, float>::iterator it = _data.find(date);
    if (it == _data.end())
        find_t_closest_date(date);
    printGoodOutput(date, fvalue);
}

// check input file and do multiplication
void BitcoinExchange::exchange(char* file) {
    std::fstream ReadFile(file, std::ios::in);
    if (!ReadFile.is_open())
        throw(NotOpen());
    std::string line;
    if (!std::getline(ReadFile, line) || line.compare("date | value"))
        throw(std::runtime_error("Input file is emty or of invalid format"));
    while (std::getline(ReadFile, line)) {
        execute_main_loop(line);
    }
    ReadFile.close();
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