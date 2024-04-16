#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<class T> void swap(T& valueA, T& valueB)
{
	T tempValue;
	tempValue = valueA;
	valueA = valueB;
	valueB = tempValue;
}

template<class T> T min(T valueA, T valueB)
{
	if(valueA < valueB)
		return valueA;
	return valueB;
}

template<class T> T max(T valueA, T valueB)
{
	if(valueA > valueB)
		return valueA;
	return valueB;
}

#endif
