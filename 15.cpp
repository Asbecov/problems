#include <fstream>
#include <vector>

int calculate(const int &N, const std::vector<std::vector<int>> matrix)
{
    int result{0};
    for (int i{0}; i < N; i++)
    {
        for (int j{i}; j < N; j++)
        {
            result += matrix[i][j];
        }
    }
    return result;
}

int main()
{
    std::ifstream infile("INPUT.TXT");
    std::ofstream ofile("OUTPUT.TXT");

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

    ofile << calculate(N, matrix) << std::endl;
}