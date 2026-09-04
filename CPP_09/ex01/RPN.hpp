#pragma once

#include <stack>
#include <exception>

class RPN {
    private:
        std::stack<double> _stack;
    
        RPN(void) {};
        RPN(const RPN& copy) { (void)copy; };
        RPN& operator=(const RPN& copy) { (void)copy; return *this; };
    public:
        RPN(std::string math_exp);
        ~RPN(void) {};

        class Error : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Error");
                }
        };

        double getResult(void);
};