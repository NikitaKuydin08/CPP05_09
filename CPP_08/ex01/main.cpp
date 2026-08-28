#include "Span.hpp"
#include <iostream>

int main(void) {
    try {
        std::cout << "// Test main provided by the subject //" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // sp.addNumber(50); // Extra number, fail
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << "// Test Filling Span with the range of integers //" << std::endl;
        std::vector<int> vector;
        for (int i = 0; i < 10000; ++i)
            vector.push_back(i * 10);
        Span bigas = Span(10000);
        bigas.addNumber(vector.begin(), vector.end());
        std::cout << bigas.shortestSpan() << std::endl;
        std::cout << bigas.longestSpan() << std::endl;

        std::cout << "// Test Insufficient amount of numbers stored //" << std::endl;
        Span vector1 = Span(5);
        vector1.addNumber(7);
        std::cout << vector1.shortestSpan() << std::endl;
        std::cout << vector1.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}