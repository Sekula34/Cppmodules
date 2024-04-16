#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <class T>
class Array 
{
	private:
		unsigned int _arrSize;
	public:
		T *templateArray;

		Array()
		{
			_arrSize = 0; 
			templateArray = new T[0]();
		}

		Array(unsigned int n)
		{
			_arrSize = n; 
			templateArray = new T[n]();
		}

		Array(const Array<T>&source)
		{
			templateArray = NULL;
			*this = source;
		}

		Array& operator=(const Array<T>&source)
		{

			if (templateArray)
				delete [] templateArray;

			this->templateArray = new T[source.size()]();
			this->_arrSize = source._arrSize;
			for(unsigned int i = 0; i < source.size(); i ++)
			{
				this->templateArray[i] = source.templateArray[i];
			}
			return (*this);
		}

		~Array()
		{
			delete [] templateArray;
		}

		T& operator[](unsigned int index)
		{
			if(index >= this->size())
			{
				throw TooBigIndexException();
			}
			return (templateArray[index]);
		}


		unsigned int size(void) const
		{
			return (_arrSize);
		}

		class TooBigIndexException : public std::exception
		{
			public :
				virtual const char * what() const throw()
				{
					return ("Index is out of range of array");
				}
		};
};


#endif
