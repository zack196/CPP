#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR;
    std::string& stringREF = str;

    stringPTR = &str;

    std::cout << "***********************************" << std::endl;
    std::cout << "memory address of str : " << &str << std::endl; 
    std::cout << "memory address of stringPTR : " << stringPTR << std::endl; 
    std::cout << "memory address of stringREF : " << &stringREF << std::endl; 

    std::cout << "***********************************" << std::endl;

    std::cout << "value of string : " << str << std::endl;
    std::cout << "value pointed by stringPTR : " << *stringPTR << std::endl;
    std::cout << "value pointed by stringREF : " << stringREF << std::endl;
    

    return 0;
}