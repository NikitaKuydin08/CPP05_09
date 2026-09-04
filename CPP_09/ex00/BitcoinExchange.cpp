/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 08:08:40 by nkuydin           #+#    #+#             */
/*   Updated: 2026/09/04 02:38:29 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <iterator>
// int compare (size_t pos, size_t len, const string& str)

std::map<std::string, float> _data;

//---------------------------------- PRINTING FUNCTIONS ---------------------------------//
void printError(std::string message) {
    std::cout << "Error: " << message << std::endl;
}

void printGoodOutput(std::string& date, float& fvalue) {
    std::cout << date << " => " << fvalue << " = ";
    
    float result;
    std::map<std::string, float>::iterator some = _data.find(date);
    result = some->second * fvalue;
    std::cout << result << std::endl;
}
//----------------------------------------------------------------------------------------//

//---------------------------------- CHECK FORMAT FUNCTIONS ------------------------------//
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
//-----------------------------------------------------------------------------------------//

//------------------------------------- HELPER FUNCTIONS ----------------------------------//
time_t parseDate(std::string DateStr) {
    char dash;
    std::stringstream ss(DateStr);

    struct tm Date;
    std::memset(&Date, 0, sizeof(Date));
    ss >> Date.tm_year >> dash >> Date.tm_mon >> dash >> Date.tm_mday;
    Date.tm_year -= 1900; Date.tm_mon -= 1;
    Date.tm_hour = 1;
    Date.tm_min = 0;
    Date.tm_sec = 0;
    
    return (mktime(&Date));
}

bool make_pairs(std::string line, std::string& exception) {
    if (line.compare(10, 1, ",") != 0 || !isdigit(line[11])) {
        exception = "Database's line format is invalid => " + line;
        return (false);
    }
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

void find_t_closest_date(std::string& date) {
    std::map<std::string, float>::iterator low, prev, safe_low;
    low = _data.lower_bound(date);
    safe_low = low;
    if (low == _data.end())
        std::cout << "When do we hit it?" << std::endl;
    else if (low == _data.begin()) {
        date = low->first;
        return ;
    }
    else {
        prev = --safe_low;
        if (parseDate(date) - parseDate(prev->first) <
            parseDate(low->first) - parseDate(date))
            date = prev->first;
        else
            date = low->first;
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
//-----------------------------------------------------------------------------------------//

//---------------------------------- MAIN FUNCTIONS ---------------------------------------//
// check database, and exctract data key-value into map container
void BitcoinExchange::fill_map(void) {
    std::string exception;
    std::fstream ReadDB("data.csv", std::ios::in);
    if (!ReadDB.is_open())
        throw(std::runtime_error("could not open file."));
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
        throw(std::runtime_error("could not open file."));
    std::string line;
    if (!std::getline(ReadFile, line) || line.compare("date | value"))
        throw(std::runtime_error("Input file is emty or of invalid format"));
    while (std::getline(ReadFile, line)) {
        execute_main_loop(line);
    }
    ReadFile.close();
}
//-----------------------------------------------------------------------------------------//