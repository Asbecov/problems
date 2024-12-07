#include <iostream>
#include <vector>

int gcd(int a, int b)
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
    int N, M;

    std::cin >> N;

    std::vector<int> cut(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> cut[i];
    }

    std::cin >> M;

    std::vector<std::pair<int, int>> pairs(M);

    for (int i = 0; i < M; i++)
    {
        std::cin >> pairs[i].first >> pairs[i].second;
        --pairs[i].first;
        --pairs[i].second;
    }

    std::vector<int> results;
    for (const auto &[L, R] : pairs)
    {
        int currentGCD = cut[L];
        for (int i = L + 1; i <= R; ++i)
        {
            currentGCD = gcd(currentGCD, cut[i]);
            if (currentGCD == 1)
                break;
        }
        results.push_back(currentGCD);
    }

    for (int result : results)
    {
        std::cout << result << " ";
    }
    std::cout << std::endl;
}
