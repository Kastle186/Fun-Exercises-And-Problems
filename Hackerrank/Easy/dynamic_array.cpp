#include <iostream>
#include <vector>
#include <hackerrank.hpp>

std::vector<int> dynamic_array(int, std::vector<std::vector<int>> &);

int main(void)
{
    std::string first_multiple_input_temp;
    std::getline(std::cin, first_multiple_input_temp);

    std::vector<std::string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));

    int n = std::stoi(first_multiple_input[0]);
    int q = std::stoi(first_multiple_input[1]);

    std::vector<std::vector<int>> queries(q);

    for (int i = 0; i < q; i++)
    {
        queries[i].resize(3);

        std::string queries_row_temp_temp;
        std::getline(std::cin, queries_row_temp_temp);

        std::vector<std::string> queries_row_temp =
            split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++)
        {
            int queries_row_item = std::stoi(queries_row_temp[j]);
            queries[i][j] = queries_row_item;
        }
    }

    std::vector<int> result = dynamic_array(n, queries);

    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

std::vector<int> dynamic_array(int n, std::vector<std::vector<int>> &queries)
{
    std::vector<std::vector<int>> dyn_arr (n, std::vector<int>());
    std::vector<int> answers;

    int last_answer = 0;

    for (std::vector<int> &query : queries)
    {
        // Extract our query so we can process it.
        // - The first element will be the type of query (1, 2).
        // - The next two elements are the operands.

        int q = query[0];
        int x = query[1];
        int y = query[2];
        int index = (x ^ last_answer) % n;

        // The exercise guarantees that we won't get an invalid query number.

        switch(q)
        {
        case 1:
            dyn_arr[index].push_back(y);
            break;

        case 2:
            last_answer = dyn_arr[index][y % dyn_arr[index].size()];
            answers.push_back(last_answer);
            break;
        }
    }

    return answers;
}
