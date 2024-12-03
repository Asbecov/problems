#include <fstream>
#include <vector>
#include <algorithm>

int max_profit(int n, const std::vector<int> &prices)
{
    int total_profit = 0;
    int max_price_ahead = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        max_price_ahead = std::max(max_price_ahead, prices[i]);
        total_profit += max_price_ahead;
    }

    return total_profit;
}

int main()
{
    std::ifstream inFile("INPUT.TXT");
    std::ofstream outFile("OUTPUT.TXT");

    int n;
    inFile >> n;

    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i)
    {
        inFile >> prices[i];
    }

    outFile << max_profit(n, prices) << std::endl;
}
