#ifndef ITER_HPP
# define ITER_HPP
#include <cstddef>

template<class T, class V>
void iter(T* address, const std::size_t length, V(*function)(T& element))
{
	for(std::size_t i = 0; i < length; i++)
	{
		function(address[i]);
	}
}


template<class T, class V>
void iter(T* address, const std::size_t length, V(*function)(const T& element))
{
	for(std::size_t i = 0; i < length; i++)
	{
		function(address[i]);
	}
}

#endif
