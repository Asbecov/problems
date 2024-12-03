#include <fstream>
#include <vector>
#include <string>

int calculate(const int &N, const std::vector<std::vector<int>> &matrix, std::vector<int> colors)
{
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (matrix[i][j] == 1 && colors[i] != colors[j])
            {
                result += 1;
            }
        }
    }
    return result;
}

int main()
{
    std::ifstream infile("INPUT.TXT");
    std::ofstream outfile("OUTPUT.TXT");

    int N;
    infile >> N;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            infile >> matrix[i][j];
        }
    }

    std::string dummy;
    getline(infile, dummy);

    std::vector<int> colors(N);
    for (int i = 0; i < N; i++)
    {
        infile >> colors[i];
    }

    outfile << calculate(N, matrix, colors) << std::endl;
}
