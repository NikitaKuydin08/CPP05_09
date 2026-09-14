#pragma once

#include <vector>
#include <deque>
#include <string>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

void print_vector_seq(const std::vector<int>& some_victor);

std::vector<int> check_input(int argc, char **argv);

bool already_exists(int num, std::vector<int> victor);

#ifdef DEBUG

#include <iostream>

#define GREEN "\033[0;32m"
#define PURPLE "\033[0;35m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

template <typename Container>
void debug_container(const std::string& name, const Container& cont) {
    std::cout << PURPLE << name << RESET << ": [ ";

    for (size_t i = 0; i < cont.size(); i++)
        std::cout << cont[i] << " ";

    std::cout << "]" << std::endl;
}

template <typename Container> \
void debug_pairs(const std::string& name, const Container& cont) {
    std::cout << BLUE << name << RESET << ": [";

    for (size_t i = 0; i < cont.size(); i++) {
        std::cout << "{ " << cont[i].first <<
            ", " << cont[i].second << "} ";
    }

    std::cout << "]" << std::endl;
}

#define DEBUG_MSG(x) \
    do { std::cout << x << std::endl; } while (0)

#else

    template <typename Container>
    void debug_container(const std::string& name, const Container& cont) { (void)name; (void)cont; };

    template <typename Container>
    void debug_pairs(const std::string& name, const Container& cont) { (void)name; (void)cont; };

#define DEBUG_MSG(x) do { } while (0)

#endif