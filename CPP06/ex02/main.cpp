#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
    else
        std::cout << "some unknown type!!" << std::endl;
}


void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "class A" << std::endl;
    }
    catch(const std::exception & ea)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "class B" << std::endl;
        }
        catch(const std::exception& eb)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "class C" << std::endl;
            }
            catch(const std::exception& ec)
            {
                std::cout << "some unknown type!!" << std::endl;
            }
        }
    }
    
}

Base* generate(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
    int i = std::rand();
    if (i % 3 == 0)
        return new A;
    else if (i % 3 == 1)
        return new B;
    else
        return new C;
}

int main()
{
    Base *rand_base;
    
    for (int i = 0; i < 20; i++)
    {
        rand_base = generate();
        std::cout << i << ": \n";
        identify(rand_base);
        identify(*rand_base);
        delete rand_base;
    }
 
}