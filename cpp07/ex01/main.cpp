#include <iostream>
#include "iter.hpp"


// template<class A> 
// void print(const A& element)
// {
// 	std::cout << element << std::endl;
// }

// int main()
// {
// 	int a[] = {1, 2, 3, 4 ,5};
// 	::iter(a, 5, print<int>);
// 	return 0;
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
