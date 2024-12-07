#include <iostream>

#include <vector>
#include <queue>

#include <string>

std::vector<std::string> solution(const std::vector<std::string> &input)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    std::vector<std::string> result;

    for (const std::string &operation : input)
    {
        if (operation[0] == 'i')
        {
            int x = stoi(operation.substr(7));
            pq.push(x);
            result.push_back(operation);
        }
        else if (operation[0] == 'g')
        {
            int x = stoi(operation.substr(7));
            while (!pq.empty() && pq.top() < x)
            {
                result.push_back("removeMin");
                pq.pop();
            }
            if (pq.empty() || pq.top() > x)
            {
                result.push_back("insert " + std::to_string(x));
                pq.push(x);
            }
            result.push_back(operation);
        }
        else if (operation == "removeMin")
        {
            if (pq.empty())
            {
                result.push_back("insert 0");
            }
            else
            {
                pq.pop();
            }
            result.push_back(operation);
        }
    }

    return result;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> operations(n);
    std::cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        std::getline(std::cin, operations[i]);
    }

    std::vector<std::string> result = solution(operations);

    std::cout << result.size() << std::endl;

    for (const std::string &operation : result)
    {
        std::cout << operation << std::endl;
    }
}