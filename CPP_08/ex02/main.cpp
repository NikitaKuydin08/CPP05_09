// #include "MutantStack.hpp"
// #include <iostream>

// int main(void)
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << "Top element of stack: " << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << "Size of stack: " << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     std::cout << *it << std::endl;
//     --it;
//     std::cout << *it << std::endl;
//     std::cout << "Container: ";
//     while (it != ite)
//     {
//         std::cout << *it << " ";
//         ++it;
//     }
//     std::cout << std::endl;
//     std::stack<int> s(mstack);
    
//     return 0;
// }

#include "MutantStack.hpp"
#include <list>
#include <vector>

template <typename T>
void printElements(const T& container) {
	typename T::const_iterator it = container.begin();
	typename T::const_iterator ite = container.end();

	std::cout << "Container : ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int main() {
	MutantStack<int> stack;

	std::cout << PURPLE << "### Testing Stack" << RESET << std::endl;
	std::cout << YELLOW << "stack.empty() : " << stack.empty() << RESET << std::endl;
	stack.push(42);
	std::cout << YELLOW << "stack.empty() : " << stack.size() << RESET << std::endl;

	stack.push(50);
	stack.push(99);
	stack.push(17);
	stack.push(13);
	printElements(stack);
	stack.pop();
	printElements(stack);
	stack.push(50);
	printElements(stack);

	std::cout << YELLOW << "stack.size() : " << stack.size() << RESET << std::endl;
	std::cout << YELLOW << "stack.top() : " << stack.top() << RESET << std::endl;

	// ##############################################################################
	MutantStack<int>::iterator it = stack.begin();
	MutantStack<int>::iterator ite = stack.end();

	std::cout << "Forward iterator : ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	// ##############################################################################
	MutantStack<int>::reverse_iterator rit = stack.rbegin();
	MutantStack<int>::reverse_iterator rite = stack.rend();
	std::cout << "Reverse iterator : ";
	while (rit != rite) {
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;

	// ##############################################################################
	const MutantStack<int> constStack = stack;

	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();
	std::cout << "Const iterator : ";
	while (cit != cite) {
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;

	// ##############################################################################
	MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = constStack.rend();
	std::cout << "Const iterator : ";
	while (crit != crite) {
		std::cout << *crit << " ";
		++crit;
	}
	std::cout << std::endl;

	// ##############################################################################
	// ##############################################################################

	std::list<int> list;

	std::cout << PURPLE << "\n### Testing List" << RESET << std::endl;
	std::cout << YELLOW << "List.empty() : " << list.empty() << RESET << std::endl;
	list.push_back(42);
	std::cout << YELLOW << "list.empty() : " << list.empty() << RESET << std::endl;

	list.push_back(0);
	list.push_back(99);
	list.push_back(17);
	list.push_back(13);
	printElements(list);
	list.pop_back();
	printElements(list);
	list.push_back(50);
	printElements(list);

	std::cout << YELLOW << "List.size() : " << list.size() << RESET << std::endl;
	std::cout << YELLOW << "List.back() : " << list.back() << RESET << std::endl;

	// ##############################################################################

	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();

	std::cout << "Forward iterator : ";
	while (lit != lite) {
		std::cout << *lit << " ";
		++lit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::list<int>::reverse_iterator lrit = list.rbegin();
	std::list<int>::reverse_iterator lrite = list.rend();

	std::cout << "Reverse iterator : ";
	while (lrit != lrite) {
		std::cout << *lrit << " ";
		++lrit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::list<int> constList = list;

	std::list<int>::const_iterator lcit = constList.begin();
	std::list<int>::const_iterator lcite = constList.end();

	std::cout << "Const Forward iterator : ";
	while (lcit != lcite) {
		std::cout << *lcit << " ";
		++lcit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::list<int>::const_reverse_iterator lcrit = list.rbegin();
	std::list<int>::const_reverse_iterator lcrite = list.rend();

	std::cout << "Const Reverse iterator : ";
	while (lcrit != lcrite) {
		std::cout << *lcrit << " ";
		++lcrit;
	}
	std::cout << std::endl;

	// ##############################################################################
	// ##############################################################################

	std::vector<int> vector;

	std::cout << PURPLE << "\n### Testing Vector" << RESET << std::endl;
	std::cout << YELLOW << "vector.empty() : " << vector.empty() << RESET << std::endl;
	vector.push_back(0);
	std::cout << YELLOW << "vector.empty() : " << vector.empty() << RESET << std::endl;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	printElements(vector);
	vector.push_back(5);
	printElements(vector);

	std::cout << YELLOW << "vector.size() : " << vector.size() << RESET << std::endl;
	std::cout << YELLOW << "vector.front() : " << vector.front() << RESET << std::endl;
	std::cout << YELLOW << "vector.back() : " << vector.back() << RESET << std::endl;

	// ##############################################################################

	std::vector<int>::iterator vit = vector.begin();
	std::vector<int>::iterator vite = vector.end();

	std::cout << "Forward iterator : ";
	while (vit != vite) {
		std::cout << *vit << " ";
		++vit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::vector<int>::reverse_iterator vrit = vector.rbegin();
	std::vector<int>::reverse_iterator vrite = vector.rend();

	std::cout << "Reverse iterator : ";
	while (vrit != vrite) {
		std::cout << *vrit << " ";
		++vrit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::vector<int>::const_iterator vcit = vector.begin();
	std::vector<int>::const_iterator vcite = vector.end();

	std::cout << "Const Forward iterator : ";
	while (vcit != vcite) {
		std::cout << *vcit << " ";
		++vcit;
	}
	std::cout << std::endl;

	// ##############################################################################

	std::vector<int>::const_reverse_iterator vcrit = vector.rbegin();
	std::vector<int>::const_reverse_iterator vcrite = vector.rend();

	std::cout << "Const Reverse iterator : ";
	while (vcrit != vcrite) {
		std::cout << *vcrit << " ";
		++vcrit;
	}
	std::cout << std::endl;

	return (0);
}
