#include <fstream>
#include <vector>

int calculate(const int &N, const std::vector<std::vector<int>> &matrix)
{
    int min = 100000000;
    for (int i{0}; i < N; i++)
    {
        for (int j{i + 1}; j < N; j++)
        {
            for (int k{j + 1}; k < N; k++)
            {
                int route_length = matrix[i][j] + matrix[j][k] + matrix[k][i];
                if (route_length < min)
                {
                    min = route_length;
                }
            }
        }
    }
    return min;
}

int main()
{
    std::ifstream infile("INPUT.TXT");
    std::ofstream outfile("OUTPUT.TXT");

    int N;
    infile >> N;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (int i{0}; i < N; i++)
    {
        for (int j{0}; j < N; j++)
        {
            infile >> matrix[i][j];
        }
    }

    outfile << calculate(N, matrix) << std::endl;
}