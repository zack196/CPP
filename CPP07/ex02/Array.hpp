#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdlib.h>
#include <exception>

template<typename T>
class Array
{
    private:
        T   *arr ;
        int arr_size;
    public:
        Array() : arr(NULL), arr_size(0) {}
        Array(unsigned int u)
        {
            arr = new T [u];
            arr_size = u;
        }
        Array(const Array& copy)
        {
            this->arr_size = copy.size();
            this->arr = new T [copy.size()];
            for (int i = 0; i < copy.size(); i++)
                this->arr[i] = copy.arr[i];
        }
        ~Array()
        { 
            delete [] this->arr;
        }
        Array<T>&  operator=(const Array& rhs)
        {
            if (this != &rhs)
            {
                delete [] this->arr;
                this->arr = new T [rhs.size()];
                for (int i = 0; i < rhs.size(); i++)
                    this->arr[i] = rhs.arr[i];
                this->arr_size = rhs.size();
            }
            return *this;
        }
        T&  operator[](int i)
        {
            if (i < 0 || i >= arr_size)
                throw(std::runtime_error("error [] out of range"));
            return arr[i];
        }
        int size() const
        {
            return arr_size;
        }
};

#endif