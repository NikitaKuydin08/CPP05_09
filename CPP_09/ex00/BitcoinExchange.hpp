#pragma once

#include <exception>
#include <map>
#include <string>

# define RED "\033[0;31m"
# define RESET "\033[0m"

class BitcoinExchange {
    private:
        static std::map<std::string, float> _data;

        BitcoinExchange(void) {};
        BitcoinExchange(const BitcoinExchange& copy) { (void)copy; };
        BitcoinExchange& operator=(const BitcoinExchange& copy) { (void)copy; return (*this); };
        ~BitcoinExchange(void) {};
    public:
        static void fill_map(void);
        static void exchange(char* file);
};
