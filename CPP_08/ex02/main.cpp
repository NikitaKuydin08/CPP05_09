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
	std::cout << PURPLE << "MutantStack implementation of a std::stack" << RESET << std::endl;
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


    return 0;
}

// #include "MutantStack.hpp"
// #include <list>
// #include <vector>

// template <typename T>
// void printElements(const T& container) {
// 	typename T::const_iterator it = container.begin();
// 	typename T::const_iterator ite = container.end();

// 	std::cout << "Container : ";
// 	while (it != ite) {
// 		std::cout << *it << " ";
// 		++it;
// 	}
// 	std::cout << std::endl;
// }

// int main() {
// 	MutantStack<int> stack;

// 	std::cout << PURPLE << "### Testing Stack" << RESET << std::endl;
// 	std::cout << YELLOW << "stack.empty() : " << stack.empty() << RESET << std::endl;
// 	stack.push(42);
// 	std::cout << YELLOW << "stack.empty() : " << stack.empty() << RESET << std::endl;

// 	stack.push(0);
// 	stack.push(99);
// 	stack.push(17);
// 	stack.push(13);
// 	printElements(stack);
// 	stack.pop();
// 	printElements(stack);
// 	stack.push(50);
// 	printElements(stack);

// 	std::cout << YELLOW << "stack.size() : " << stack.size() << RESET << std::endl;
// 	std::cout << YELLOW << "stack.top() : " << stack.top() << RESET << std::endl;

// 	// ##############################################################################
// 	MutantStack<int>::iterator it = stack.begin();
// 	MutantStack<int>::iterator ite = stack.end();

// 	std::cout << "Forward iterator : ";
// 	while (it != ite) {
// 		std::cout << *it << " ";
// 		++it;
// 	}
// 	std::cout << std::endl;

// 	// ##############################################################################
// 	MutantStack<int>::reverse_iterator rit = stack.rbegin();
// 	MutantStack<int>::reverse_iterator rite = stack.rend();
// 	std::cout << "Reverse iterator : ";
// 	while (rit != rite) {
// 		std::cout << *rit << " ";
// 		++rit;
// 	}
// 	std::cout << std::endl;

// 	// ##############################################################################
// 	const MutantStack<int> constStack = stack;

// 	MutantStack<int>::const_iterator cit = constStack.begin();
// 	MutantStack<int>::const_iterator cite = constStack.end();
// 	std::cout << "Const iterator : ";
// 	while (cit != cite) {
// 		std::cout << *cit << " ";
// 		++cit;
// 	}
// 	std::cout << std::endl;

// 	// ##############################################################################
// 	MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
// 	MutantStack<int>::const_reverse_iterator crite = constStack.rend();
// 	std::cout << "Const iterator : ";
// 	while (crit != crite) {
// 		std::cout << *crit << " ";
// 		++crit;
// 	}
// 	std::cout << std::endl;

// 	// ##############################################################################
// 	// ##############################################################################

// 	std::list<int> list;

// 	std::cout << PURPLE << "\n### Testing List" << RESET << std::endl;
// 	std::cout << YELLOW << "List.empty() : " << list.empty() << RESET << std::endl;
// 	list.push_back(42);
// 	std::cout << YELLOW << "list.empty() : " << list.empty() << RESET << std::endl;

// 	list.push_back(0);
// 	list.push_back(99);
// 	list.push_back(17);
// 	list.push_back(13);
// 	printElements(list);
// 	list.pop_back();
// 	printElements(list);
// 	list.push_back(50);
// 	printElements(list);

// 	std::cout << YELLOW << "List.size() : " << list.size() << RESET << std::endl;
// 	std::cout << YELLOW << "List.back() : " << list.back() << RESET << std::endl;

// 	// ##############################################################################

// 	std::list<int>::iterator lit = list.begin();
// 	std::list<int>::iterator lite = list.end();

// 	std::cout << "Forward iterator : ";
// 	while (lit != lite) {
// 		std::cout << *lit << " ";
// 		++lit;
// 	}
// 	std::cout << std::endl;

// 	// ##############################################################################

// 	std::list<int>::reverse_iterator lrit = list.rbegin();
// 	std::list<int>::reverse_iterator lrite = list.rend();

// 	std::cout << "Reverse iterator : ";
// 	while (lrit != lrite) {
// 		std::cout << *lrit << " ";
// 		++lrit;
// 	}
// 	std::cout << std::endl;


