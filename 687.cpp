#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>

std::pair<std::vector<int>, int> min_weight_path(const std::vector<std::vector<int>> &matrix, int m, int n)
{
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, std::numeric_limits<int>::max()));
    std::vector<std::vector<std::vector<int>>> path(m, std::vector<std::vector<int>>(n));

    for (int i = 0; i < m; ++i)
    {
        dp[i][0] = matrix[i][0];
        path[i][0] = {i + 1};
    }

    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int ni : {i - 1, i, i + 1})
            {
                if (ni >= 0 && ni < m)
                {
                    int new_weight = dp[ni][j - 1] + matrix[i][j];
                    if (new_weight < dp[i][j])
                    {
                        dp[i][j] = new_weight;
                        path[i][j] = path[ni][j - 1];
                        path[i][j].push_back(i + 1);
                    }
                    else if (new_weight == dp[i][j] && path[ni][j - 1] < path[i][j])
                    {
                        path[i][j] = path[ni][j - 1];
                        path[i][j].push_back(i + 1);
                    }
                }
            }
        }
    }

    int min_weight = std::numeric_limits<int>::max();
    std::vector<int> min_path;
    for (int i = 0; i < m; ++i)
    {
        if (dp[i][n - 1] < min_weight)
        {
            min_weight = dp[i][n - 1];
            min_path = path[i][n - 1];
        }
    }

    return {min_path, min_weight};
}

int main()
{
    std::ifstream inFile("INPUT.TXT");
    std::ofstream outFile("OUTPUT.TXT");

    int m, n;
    inFile >> m >> n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inFile >> matrix[i][j];
        }
    }

    std::pair<std::vector<int>, int> result = min_weight_path(matrix, m, n);
    std::vector<int> min_path = result.first;
    int min_weight = result.second;

    for (int i = 0; i < min_path.size(); ++i)
    {
        outFile << min_path[i];
        if (i < min_path.size() - 1)
            outFile << " ";
    }
    outFile << std::endl;
    outFile << min_weight << std::endl;
}
