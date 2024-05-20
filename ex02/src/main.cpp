#include "Array.hpp"

int main()
{
    try
    {
        Array<int> a;
        Array<int> b(10);
        Array<int> c(b);

        std::cout << "Size of a: " << a.size() << std::endl;
        std::cout << "Size of b: " << b.size() << std::endl;
        std::cout << "Size of c: " << c.size() << std::endl;

        for (unsigned int i = 0; i < b.size(); i++)
        {
            b[i] = i * 2;
            std::cout << "b[" << i << "] = " << b[i] << std::endl;
        }

        c = b;
        for (unsigned int i = 0; i < c.size(); i++)
        {
            std::cout << "c[" << i << "] = " << c[i] << std::endl;
        }

        try
        {
            std::cout << b[10] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        Array<std::string> d(3);
        d[0] = "Hello";
        d[1] = "World";
        d[2] = "!";
        for (unsigned int i = 0; i < d.size(); i++)
        {
            std::cout << "d[" << i << "] = " << d[i] << std::endl;
        }

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
