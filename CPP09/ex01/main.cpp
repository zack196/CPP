#include <iostream>
#include <stack>


int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string line = av[1];
        std::stack<int> st;
        int rside;
        int lside;

        std::string::iterator it = line.begin();
        while (it != line.end())
        {
            if (*it == ' ')
            {
                it++;
                continue ;
            }
            else if ('0' <= *it && *it <= '9')
            {
                st.push( static_cast<int>(*it - '0'));
            }
            else if (*it == '+' && st.size() >= 2)
            {
                rside = st.top();
                st.pop();
                lside = st.top();
                st.pop();
                st.push(lside + rside);
            }
            
            else if (*it == '*' && st.size() >= 2)
            {
                rside = st.top();
                st.pop();
                lside = st.top();
                st.pop();
                st.push(lside * rside);
            }
            else if (*it == '-' && st.size() >= 2)
            {
                rside = st.top();
                st.pop();
                lside = st.top();
                st.pop();
                st.push(lside - rside);
            }
            else if (*it == '/' && st.size())
            {
                rside = st.top();
                st.pop();
                lside = st.top();
                if (rside == 0)
                    std::cerr << "divide by 0!!" << std::endl;
                st.pop();
                st.push(lside / rside);
            }
            else
            {
                std::cerr << "error input " << std::endl;
                return 1;
            }
            it++;
        }
        if (st.size() == 1)
        {
            std::cout << st.top()  << std::endl;
            return 0;
        }
         
    }

    std::cerr << "error argument" << std::endl;
    return 1 ;
}