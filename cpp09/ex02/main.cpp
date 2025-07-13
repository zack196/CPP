#include "PmergeMe.hpp"

// int main(int ac, char **av)
// {
//     try
//     {
//         if (ac < 2)
//             throw(std::runtime_error("Error"));
        
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
    
// }

std::vector<int> getJacobSthal(int size)
{
    std::vector<int> jac;
    int J0 = 0;
    int J1 = 1;
    jac.push_back(J1);
    while (true)
    {
        int Jn = J1 + 2 * J0;
        if (Jn > size)
            break ;
        jac.push_back(Jn);
        J0 = J1;
        J1 = Jn;
    }
    return jac;
}

void insert(std::vector<int>& main, std::vector<int>& pend)
{
    std::vector<int> jacob = getJacobSthal(pend.size());
    std::vector<bool> inserted(pend.size(), false);
    for (int i = jacob.size(); i > 0; i--)
    {
        for (int j = jacob[i] - 1; j >= jacob[i - 1]; j--)
        {
            if (0 < j && j < pend.size())
            {
                std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[j]);
                main.insert(pos, pend[j]);
                inserted[j] = true;
            }
        }
    }
    for (int i = pend.size() - 1; i > 0; i--)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[i]);
            main.insert(pos, pend[i]);
        }
    }
}

std::vector<int> mergeSorting(std::vector<int> v)
{
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> JacobSthal;

    for (size_t i = 0; i < v.size(); i++)
    {
        if ((i + 1 < v.size()) && v[i] < v[i+1])
        {
            pend.push_back(v[i]);
            main.push_back(v[i + 1]);
        }
        else if ((i + 1 < v.size()) && v[i] > v[i+1])
        {
            pend.push_back(v[i + 1]);
            main.push_back(v[i]);
        }
        else
            pend.push_back(v[i]);
    }
    std::cout << "in\n";
    main = mergeSorting(main);
    insert(main, pend);
    
    return main;
}

int main()
{
    std::vector<int> input = {3,4,6,1,22,33,44};
    input = mergeSorting(input);
    // std::cout << "in\n";
    // for (size_t i = 0; i < input.size(); i++)
    // {
    //     std::cout << input[i] << ", ";
    // }
    // std::cout << std::endl;
    
}