#include <fstream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int dijkstra(const std::vector<std::vector<int>> &matrix, int start, int end)
{
    std::vector<int> dist(matrix.size(), INF);
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == end)
        {
            return current_dist;
        }

        if (current_dist > dist[u])
        {
            continue;
        }

        for (int v = 0; v < matrix.size(); v++)
        {
            if (matrix[u][v] != -1)
            {
                int next_dist = current_dist + matrix[u][v];
                if (next_dist < dist[v])
                {
                    dist[v] = next_dist;
                    pq.push({next_dist, v});
                }
            }
        }
    }

    return -1;
}

int main()
{
    std::ifstream inFile("INPUT.TXT");
    std::ofstream outFile("OUTPUT.TXT");

    int n, s, f;
    inFile >> n >> s >> f;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inFile >> matrix[i][j];
        }
    }

    s -= 1;
    f -= 1;

    int result = dijkstra(matrix, s, f);
    if (result == INF)
    {
        result = -1;
    }

    outFile << result << std::endl;
}
