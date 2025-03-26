// Name: Balanced Brackets
// Topics: Data Structures, Stacks

#include <iostream>
#include <stack>
#include <hackerrank.hpp>

std::string is_balanced(std::string);

int main(void)
{
    std::string t_temp;
    std::getline(std::cin, t_temp);

    int t = std::stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        std::string s;
        std::getline(std::cin, s);

        std::string result = is_balanced(s);
        std::cout << result << std::endl;
    }
    return 0;
}

std::string is_balanced(std::string str)
{
    // NOTE: The problem's description says it's guaranteed we will not get
    // non-bracket characters in the input.

    std::stack<char> brackets_stack;

    for (int i = 0; i < str.length(); i++)
    {
        char next_bracket = str[i];

        // If it's an opening bracket, we add it to the stack.

        if (next_bracket == '(' || next_bracket == '{' || next_bracket == '[')
        {
            brackets_stack.push(next_bracket);
            continue;
        }

        // If we got a closing match without having a previous opening one, then
        // we know this is not balanced.

        if (brackets_stack.empty())
            return "NO";

        // Otherwise, we bumped across a closing bracket. So, we check the top
        // of our stack. If this closing bracket doesn't match the next opening
        // one in the stack, then we know this string is not bracket-balanced,
        // and thus can finish early.

        char expected_match = brackets_stack.top();

        switch (next_bracket)
        {
        case ')':
            if (expected_match != '(')
                return "NO";
            break;

        case '}':
            if (expected_match != '{')
                return "NO";
            break;

        case ']':
            if (expected_match != '[')
                return "NO";
            break;
        }

        brackets_stack.pop();
    }

    // It may be the case that all last n pairs of brackets were balanced, but
    // we also have to check for unclosed ones, as those should not appear in
    // a balanced string either.

    return brackets_stack.empty() ? "YES" : "NO";
}
