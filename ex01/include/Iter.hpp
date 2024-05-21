#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int size, void function(const T &))
{
    if (!array || !function)
        return;
    for (int i = 0; i < size; i++)
        function(array[i]);
}

template <typename T>
void intConverter(const T &arg)
{
    std::cout << static_cast<int>(arg) << std::endl;
}

#endif
