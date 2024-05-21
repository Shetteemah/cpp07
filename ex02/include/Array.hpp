#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <exception>

template <typename T>
class Array
{
private:
    T *_data;
    unsigned int _length;

public:
    Array();
    Array(unsigned int size);
    Array(const Array &copy);
    ~Array();
    Array &operator=(const Array &src);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int size() const;

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

template <typename T>
Array<T>::Array() : _data(nullptr), _length(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int size) : _data(new T[size]), _length(size)
{
    std::cout << "Array of size " << size << " created" << std::endl;
    for (unsigned int i = 0; i < size; ++i)
        _data[i] = T();
}

template <typename T>
Array<T>::Array(const Array &copy) : _data(new T[copy._length]), _length(copy._length)
{
    std::cout << "Array copy constructor called" << std::endl;
    for (unsigned int i = 0; i < _length; ++i)
        _data[i] = copy._data[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] _data;
    std::cout << "Array destructor called" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
    std::cout << "Array assignment operator called" << std::endl;
    if (this == &src)
        return (*this);

    delete[] _data;
    _length = src._length;
    _data = new T[_length];
    for (unsigned int i = 0; i < _length; ++i)
        _data[i] = src._data[i];

    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _length)
        throw OutOfBoundsException();
    return (_data[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _length)
        throw OutOfBoundsException();
    return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_length);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Array index out of bounds");
}

#endif