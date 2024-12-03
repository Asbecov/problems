#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

std::pair<int, std::vector<int>> maxSumPath(const std::vector<int> &steps)
{
    int n = steps.size();
    if (n == 0)
        return {0, {}};

    std::vector<int> dp(n, 0);
    std::vector<int> prev(n, -1);

    dp[0] = steps[0];
    if (n > 1)
    {
        dp[1] = std::max(steps[0] + steps[1], steps[1]);
        prev[1] = (dp[1] == steps[0] + steps[1]) ? 0 : -1;
    }

    for (int i = 2; i < n; ++i)
    {
        if (dp[i - 1] > dp[i - 2])
        {
            dp[i] = dp[i - 1] + steps[i];
            prev[i] = i - 1;
        }
        else
        {
            dp[i] = dp[i - 2] + steps[i];
            prev[i] = i - 2;
        }
    }

    int max_sum = dp[n - 1];

    std::vector<int> path;
    for (int i = n - 1; i >= 0; i = prev[i])
    {
        path.push_back(i + 1);
    }
    std::reverse(path.begin(), path.end());

    return std::make_pair(max_sum, path);
}

int main()
{
    std::ifstream inFile("INPUT.TXT");
    std::ofstream outFile("OUTPUT.TXT");

    int n;
    inFile >> n;

    std::vector<int> steps(n);
    for (int i = 0; i < n; ++i)
    {
        inFile >> steps[i];
    }

    std::pair<int, std::vector<int>> result = maxSumPath(steps);
    int max_sum = result.first;
    std::vector<int> path = result.second;

    outFile << max_sum << std::endl;
    for (int i = 0; i < path.size(); ++i)
    {
        outFile << path[i];
        if (i < path.size() - 1)
            outFile << " ";
    }
    outFile << std::endl;

    return 0;
}
