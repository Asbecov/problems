#include <fstream>
#include <vector>
#include <stack>

int calculate(const int &N, const int &S, const std::vector<std::vector<int>> &matrix)
{
    std::stack<int> st;
    std::vector<bool> checked(N, false);
    int result{0};
    st.push(S - 1);
    checked[S - 1] = true;

    while (!st.empty())
    {
        int curI = st.top();
        st.pop();

        for (int i{0}; i < N; i++)
        {
            if (matrix[curI][i] == 1 && !checked[i])
            {
                st.push(i);
                checked[i] = true;
                ++result;
            }
        }
    }

    return result;
}

int main()
{
    std::ifstream infile("INPUT.TXT");
    std::ofstream outfile("OUTPUT.TXT");

    int N, S;
    infile >> N >> S;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));

    for (int i{0}; i < N; i++)
    {
        for (int j{0}; j < N; j++)
        {
            infile >> matrix[i][j];
        }
    }

    outfile << calculate(N, S, matrix) << std::endl;
}