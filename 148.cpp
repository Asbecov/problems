#include <iostream>

int solution(int a, int b)
{
    while (b != 0)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main()
{
    int a, b;

    std::cin >> a >> b;

    std::cout << solution(a, b) << std::endl;
}