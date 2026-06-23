#include <iostream>

int main()
{
    int x = 5;
    const int *y = &x;
    x++;
    std::cout << *y << std::endl;

    return 0;
}