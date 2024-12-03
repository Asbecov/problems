#include <fstream>
#include <vector>

const int INF = 100000;

bool has_negative_cycle(int n, const std::vector<std::vector<int>> &matrix)
{
    for (int start = 0; start < n; ++start)
    {
        std::vector<int> dist(n, INF);
        dist[start] = 0;

        for (int k = 0; k < n - 1; ++k)
        {
            for (int u = 0; u < n; ++u)
            {
                for (int v = 0; v < n; ++v)
                {
                    if (matrix[u][v] != INF && dist[u] != INF)
                    {
                        if (dist[v] > dist[u] + matrix[u][v])
                        {
                            dist[v] = dist[u] + matrix[u][v];
                        }
                    }
                }
            }
        }

        for (int u = 0; u < n; ++u)
        {
            for (int v = 0; v < n; ++v)
            {
                if (matrix[u][v] != INF && dist[u] != INF)
                {
                    if (dist[v] > dist[u] + matrix[u][v])
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    std::ifstream inFile("INPUT.TXT");
    std::ofstream outFile("OUTPUT.TXT");

    int n;
    inFile >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inFile >> matrix[i][j];
        }
    }

    if (has_negative_cycle(n, matrix))
    {
        outFile << "YES" << std::endl;
    }
    else
    {
        outFile << "NO" << std::endl;
    }
}
