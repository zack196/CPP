#include <iostream>

int main(int ac, char **av)
{
    std::string str;
    int         i = 1;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBAC NOISE *";
    else
    {
        while (av[i])
        {
            str = av[i];
            for (int j = 0; str[j]; j++)
                str[j] = std::toupper(str[j]);
            std::cout << str;
            i++;
        }
    }
    std::cout << std::endl;
}