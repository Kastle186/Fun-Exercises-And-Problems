#include "hackerrank.hpp"

std::string ltrim(const std::string &str)
{
    const size_t strBegin = str.find_first_not_of(" \t\n");
    return str.substr(strBegin, str.length());
}

std::string rtrim(const std::string &str)
{
    const size_t strEnd = str.find_last_not_of(" \t\n");
    return str.substr(0, strEnd + 1);
}

std::vector<std::string> split(const std::string &str)
{
    std::vector<std::string> tokens;
    std::string::size_type start = 0;
    std::string::size_type end = 0;

    while ((end = str.find(" ", start)) != std::string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}
