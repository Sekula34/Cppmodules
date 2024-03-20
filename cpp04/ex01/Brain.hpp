#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>

class Brain 
{
	private :
		std::string ideas[100];
	public:
		Brain(void);
		Brain(const Brain& source);
		Brain& operator=(const Brain &source);
		~Brain();

		void listIdeas(void);
};

#endif
