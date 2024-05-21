#include "Array.hpp"

int main()
{
    try
    {
        Array<int> num1;
        Array<int> num2(10);
        Array<int> copiedNum(num2);

        std::cout << "Size of num1: " << num1.size() << std::endl;
        std::cout << "Size of num2: " << num2.size() << std::endl;
        std::cout << "Size of copiedNum: " << copiedNum.size() << std::endl;

        for (unsigned int i = 0; i < num2.size(); ++i)
        {
            num2[i] = i * 3;
            std::cout << "num2[" << i << "] = " << num2[i] << std::endl;
        }

        copiedNum = num2;
        for (unsigned int i = 0; i < copiedNum.size(); ++i)
        {
            std::cout << "copiedNum[" << i << "] = " << copiedNum[i] << std::endl;
        }

        try
        {
            std::cout << num2[10] << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cerr << ex.what() << std::endl;
        }

        Array<std::string> word(3);
        word[0] = "Hi";
        word[1] = "My";
        word[2] = "Name";
        for (unsigned int i = 0; i < word.size(); ++i)
        {
            std::cout << "word[" << i << "] = " << word[i] << std::endl;
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return (0);
}
