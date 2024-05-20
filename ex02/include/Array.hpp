#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <exception>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        ~Array();
        Array &operator=(const Array &src);
        T &operator[](unsigned int i);
        unsigned int size() const;

        class OutOfLimits : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
};

template <typename T>
Array<T>::Array() : _array(nullptr), _size(0)
{
    std::cout << "Array default constructor" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    std::cout << "Array: " << n << " with size (" << this->_size << ") constructor" << std::endl;
    for (unsigned int i = 0; i < n; i++)
        this->_array[i] = T();
}

template <typename T>
Array<T>::Array(const Array &copy) : _array(new T[copy._size]), _size(copy._size)
{
    std::cout << "Array: copy constructor initiated!" << std::endl;
    for (unsigned int i = 0; i < copy._size; i++)
        this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_array;
    std::cout << "Array destroyed!" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    std::cout << "Array: operator= initiated!" << std::endl;
    if (this == &src)
        return (*this);
    delete[] this->_array;
    this->_array = new T[src._size];
    for (unsigned int i = 0; i < src._size; i++)
        this->_array[i] = src._array[i];
    this->_size = src._size;
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->_size)
        throw Array<T>::OutOfLimits();
    return (this->_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfLimits::what() const throw()
{
    return ("Error: Index is out of limits!");
}
#endif