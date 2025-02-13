#ifndef Brain_hpp
#define Brain_hpp

# include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& src);
    ~Brain();
    Brain&  operator=(const Brain& rhs);

    std::string get_ith_idea(int i) const;
    void        put_ith_idea(int i, std::string ith_idea);
    void        enounce_ideas(void);
};



#endif