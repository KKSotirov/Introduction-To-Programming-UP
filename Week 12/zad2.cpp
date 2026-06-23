#include <iostream>
size_t fib(size_t n)
{
    // n = n-1 + n-2
    if (n == 1 || n == 0)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    size_t n;
    std::cin >> n;
    std::cout << "The " << n << "-th num of Fibonacci is = " << fib(n);

    return 0;
}