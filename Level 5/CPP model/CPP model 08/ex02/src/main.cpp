# include "../include/MutantStack.hpp"

int main() {
    	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

    MutantStack<int> test;
    for (int i = 0; i < 5; i++) {
        test.push(i);
    }
    for (std::deque<int>::const_iterator it = test.begin(); it != test.end(); it++) {
        std::cout << "value of stack " << *it << std::endl;
    }
    for (int i = 0; i < 3; i++) {
        test.pop();
    }
    for (std::deque<int>::const_iterator it = test.begin(); it != test.end(); it++) {
        std::cout << "value of stack " << *it << std::endl;
    }
}