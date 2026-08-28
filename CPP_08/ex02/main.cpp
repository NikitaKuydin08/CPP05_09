#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

template <typename Container>
void print(const Container& c) {
	typename Container::const_iterator it = c.begin();
	typename Container::const_iterator ite = c.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(void)
{
	std::cout << PURPLE << "MutantStack inheritance of std::stack" << RESET << std::endl;
    MutantStack<int> mstack;
	std::cout << YELLOW << "Stack.empty() : " << mstack.empty() << RESET << std::endl;
    mstack.push(42);
	std::cout << YELLOW << "Stack.empty() : " << mstack.empty() << RESET << std::endl;
	mstack.push(0);
	mstack.push(99);
	mstack.push(17);
	mstack.push(13);
	print(mstack);
	mstack.pop();
	print(mstack);
	mstack.push(50);
	print(mstack);
	std::cout << YELLOW << "Stack.size() : " << mstack.size() << RESET << std::endl;
	std::cout << YELLOW << "List.back() : " << mstack.top() << RESET << std::endl;
    std::stack<int> s(mstack);

	std::cout << PURPLE << "### Testing STL container std::list" << RESET << std::endl;
    std::list<int> mlist;
	std::cout << YELLOW << "List.empty() : " << mlist.empty() << RESET << std::endl;
	mlist.push_back(42);
	std::cout << YELLOW << "list.empty() : " << mlist.empty() << RESET << std::endl;
	mlist.push_back(0);
	mlist.push_back(99);
	mlist.push_back(17);
	mlist.push_back(13);
	print(mlist);
	mlist.pop_back();
	print(mlist);
	mlist.push_back(50);
	print(mlist);
	std::cout << YELLOW << "List.size() : " << mlist.size() << RESET << std::endl;
	std::cout << YELLOW << "List.back() : " << mlist.back() << RESET << std::endl;

    std::cout << PURPLE << "MutantStack(CompositionStack) composition \"has a\" relationship. \
    Direct implementation of std::stack" << RESET << std::endl;
    CompositionStack<int> cstack;
	std::cout << YELLOW << "Stack.empty() : " << cstack.empty() << RESET << std::endl;
    cstack.push(42);
	std::cout << YELLOW << "Stack.empty() : " << cstack.empty() << RESET << std::endl;
	cstack.push(0);
	cstack.push(99);
	cstack.push(17);
	cstack.push(13);
	print(cstack);
	cstack.pop();
	print(cstack);
	cstack.push(50);
	print(cstack);
	std::cout << YELLOW << "Stack.size() : " << cstack.size() << RESET << std::endl;
	std::cout << YELLOW << "List.back() : " << cstack.top() << RESET << std::endl;
    std::stack<int> sc(cstack);

    return 0;
}
