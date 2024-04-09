#include "Serializer.hpp"
#include "Data.hpp"
#include <cstdint>

Serializer::Serializer(void)
{

};

Serializer::Serializer(const Serializer& source)
{

};

Serializer& Serializer::operator=(const Serializer& source)
{
	return (*this);
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t returnValue;
	returnValue = reinterpret_cast<uintptr_t>(ptr);
	return (returnValue);
}

Data* deserialize(uintptr_t raw)
{
	Data* returnPtr;
	returnPtr = reinterpret_cast<Data *>(raw);
	return (returnPtr);
}
