#include "Iter.hpp"

int main()
{
    char char_array[] = {'A', 'B', 'C', 'D', 'E', 'a', 'b', 'c', 'd', 'e'};
    int int_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Array chars:\n";
    for (unsigned int i = 0; i < sizeof(char_array) / sizeof(char_array[0]); i++)
        std::cout << char_array[i] << " ";
    std::cout << "\n";

    std::cout << "Array index:\n";
    iter(int_array, sizeof(int_array) / sizeof(int_array[0]), intConverter);
    
    std::cout << "Array int values:\n";
    iter(char_array, sizeof(char_array) / sizeof(char_array[0]), intConverter);
    
    return 0;
}
