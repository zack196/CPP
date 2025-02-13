#include "Span.hpp"


int main()
{
    const unsigned int N = 100; 
    Span sp = Span(10000);
    try
    {
        std::srand(time(NULL));
        for (int i = 0; i < 0.9 * N ; i++)
        {
            const int rnd = std::rand();
            sp.addNumber(rnd);
        }
        sp.addNumber(6);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::vector<int> d;
        for ( int i = 0; i < 0.1 * N; i++)
        {
            const int rnd = std::rand();
            d.push_back(rnd);
        }
        d.push_back(32);
        d.push_back(31);
        d.push_back(3);
        d.push_back(34);
        d.push_back(44);


        sp.addRange(d.begin(), d.end());
        
        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        std::cout << "longest span : " << sp.longestSpan() << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    sp.printSpan();
    
    return 0;
}