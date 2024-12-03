#include <fstream>
#include <vector>

int main()
{
    std::ifstream infile("INPUT.TXT");
    std::ofstream outfile("OUTPUT.TXT");

    int N, M;
    infile >> N >> M;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));

    int count{0};

    for (int i{0}; i < M; i++)
    {
        int x, y;
        infile >> x >> y;
        --x;
        --y;
        if (matrix[x][y] == 0)
        {
            count += 1;
            matrix[x][y] = 1;
            matrix[y][x] = 1;
        }
    }

    outfile << (count >= N ? "YES" : "NO") << std::endl;
}