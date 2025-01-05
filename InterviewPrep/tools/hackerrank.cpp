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
