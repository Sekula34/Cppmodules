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
			templateArray = new T[0]();
			_arrSize = 0;
		}

		Array(unsigned int n)
		{
			templateArray = new T[n]();
			_arrSize = n;
		}

		Array(const Array<T>&source)
		{
			unsigned int sourceSize;
			sourceSize = source.size();
			this->templateArray = new T[sourceSize];
			for(unsigned int i = 0; i < sourceSize; i ++)
			{
				this->templateArray[i] = source.templateArray[i];
			}
		}

		Array& operator=(const Array<T>&source)
		{
			unsigned int sourceSize;
			sourceSize = source.size();
			this->templateArray = new T[sourceSize];
			for(unsigned int i = 0; i < sourceSize; i ++)
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
