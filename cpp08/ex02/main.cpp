#include<stack>
#include "MutantStack.hpp"
#include <iostream>
#include <list>


void testSubject1()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

// If you run it a first time with your MutantStack, and a second time replacing the
// MutantStack with, for example, a std::list, the two outputs should be the same. Of
// course, when testing another container, update the code below with the corresponding
// member functions (push() can become push_back()).
void testSubject2()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
}


void myTest()
{
	std::stack<int> OgStack;
	MutantStack<int> MyStack;

	if(OgStack.empty())
	{
		std::cout <<"Original stack is empty" << std::endl;
	}
	if(MyStack.empty())
	{
		std::cout <<"My Stack is empty" << std::endl;
	}
	std::cout << "OgStack size is " << OgStack.size() << std::endl;
	std::cout << "MyStack size is " << MyStack.size() << std::endl;
	OgStack.push(18);
	MyStack.push(18);
	std::cout << "OgStack size is " << OgStack.size() << std::endl;
	std::cout << "MyStack size is " << MyStack.size() << std::endl;
	OgStack.pop(); //removefirst
	MyStack.pop();
	std::cout << "OgStack size is " << OgStack.size() << std::endl;
	std::cout << "MyStack size is " << MyStack.size() << std::endl;
	OgStack.push(1);
	MyStack.push(1);
	OgStack.push(2);
	MyStack.push(2);
	std::cout <<"Original stack on top is " << OgStack.top() << std::endl;
	std::cout <<"My stack on top is " << MyStack.top() << std::endl;
	MutantStack<int>::iterator myIt;
	MyStack.push(3);
	MyStack.push(4);
	for(myIt = MyStack.begin(); myIt<MyStack.end(); myIt++)
	{
		std::cout << *myIt << std::endl;
	}
}
int main()
{
	testSubject1();
	std::cout << std::endl;
	testSubject2();
	std::cout <<std::endl;
	//myTest();
	return 0;
}
