#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Constructor Brain has been called!" 
        << std::endl;
}

Brain::Brain(const Brain& src)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = src.get_ith_idea(i);
    std::cout << "Copy Constructor of Brain has been called!"
        << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain has been destructed!" << std::endl;
}

Brain&  Brain::operator=(const Brain& rhs)
{
    if (this != &rhs)
        for (int i = 0; i < 100; i++)
            ideas[i] = rhs.get_ith_idea(i);
    return *this ;
}

std::string Brain::get_ith_idea(int i) const
{
    if (0 <= i && i < 100)
        return ideas[i];
    return "";
}

void    Brain::put_ith_idea(int i, std::string ith_idea)
{
    if (0 <= i && i < 100)
        this->ideas[i] = ith_idea;
}

void Brain::enounce_ideas(void)
{
    for (int i = 0; i < 100; i++)
        std::cout << "[" << i << "]" << ideas[i] << std::endl;
}