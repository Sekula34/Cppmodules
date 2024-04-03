#include <iostream>

//implicit converison
void ex00 (void)
{
	//implicit conversion
	short a = 200;
	int b;
	b = a;
	std::cout << b << std::endl;
}

//explicit conversion
void ex01(void)
{
	short a = 200;
	int b;
	b = (int) a; //c like cast notation
	b = int (a); //functional notation
}

void ex02(void)
{
	class CBase{};
	class CDerived: public CBase{};

	CBase b; 
	CBase * pb;

	CDerived d;
	CDerived *pd;

	pb = dynamic_cast<CBase*>(&d);
	//pd = dynamic_cast<CDerived*>(&b);
}

int main()
{
	ex00();
	//ex01();
	return 0;
}
