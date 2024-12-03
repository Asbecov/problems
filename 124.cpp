#include <fstream>
#include <vector>

int main()
{
    std::ifstream infile("INPUT.TXT");
    std::ofstream outfile("OUTPUT.TXT");

    int N, M;
    infile >> N >> M;

    std::vector<int> traffic_lights(N, 0);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        infile >> u >> v;
        traffic_lights[u - 1]++;
        traffic_lights[v - 1]++;
    }

    for (int i : traffic_lights)
    {
        outfile << i << " ";
    }
    outfile << std::endl;
}