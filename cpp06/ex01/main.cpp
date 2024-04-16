#include "Data.hpp"
#include "Serializer.hpp"

#include <stdint.h>
#include <iostream>


void printData(Data *ptr)
{
	std::cout << "Float value is " << ptr->fValue << std::endl;
	std::cout << "Integer value is " << ptr->iValue << std::endl;
	std::cout << "Name is " << ptr->name << std::endl;
}



// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
void subjectTest()
{
	Data objectData;
	objectData.fValue = 1.2f;
	objectData.iValue = -12;
	objectData.name = "SUBJECT NAME";

	Data *originalPtr = &objectData;
	Data *deserializePtr;

	uintptr_t serialValue = Serializer::serialize(&objectData);
	std::cout << "Seraial value is " << serialValue << std::endl;
	deserializePtr = Serializer::deserialize(serialValue);
	printData(deserializePtr);
	if(originalPtr == deserializePtr)
	{
		std::cout << "Return values of deserialize is equal to original ptr" << std::endl;
	}



}
int main()
{
	subjectTest();
	// Data my_data;
	// my_data.fValue = 56.7f;
	// my_data.iValue = 12;
	// my_data.name = "ftstring";

	// Data *myPtr = &my_data;
	// uintptr_t serialValue = Serializer::serialize(myPtr);
	// std::cout << serialValue << std::endl;
	// Data *secondPtr; 
	// secondPtr = Serializer::deserialize(serialValue);
	// printData(secondPtr);
	return 0;
}
