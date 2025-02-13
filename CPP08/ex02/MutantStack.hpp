#ifndef MUTANTSTACK_HPP

#define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>
# include <algorithm>
# include <bits/stdc++.h> 

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type          container_type;

        typedef typename    container_type::iterator               iterator;
        typedef typename    container_type::reverse_iterator       reverse_iterator;
        typedef typename    container_type::const_iterator         const_iterator;
        typedef typename    container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack(){}
        MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
        ~MutantStack() {}
        MutantStack& operator=(const MutantStack& rhs)
        {
            this->c = rhs.c;
            return *this;
        }
        iterator        begin() { return this->c.begin() ; }
        iterator        end() { return this->c.end() ; }
        const_iterator  begin() const { return this->c.begin() ;}
        const_iterator  end() const { return this->c.end(); }

        reverse_iterator        rbegin() { return this->c.rbegin() ; }
        reverse_iterator        rend() { return this->c.rend() ; }
        const_reverse_iterator  rbegin() const { return this->c.rbegin() ;}
        const_reverse_iterator  rend() const { return this->c.rend(); }
};










#endif