// Name: Greatest Common Divisor of Strings
// Topics: Math, String
// Companies:
// - Infosys
// - Flipkart
// - tcs

#include <iostream>
#include <numeric>
#include <string>

std::string gcd_of_strings(std::string, std::string);

int main(void)
{
    std::string str_gcd1 = gcd_of_strings("ABCABC", "ABC");
    std::string str_gcd2 = gcd_of_strings("ABABAB", "ABAB");
    std::string str_gcd3 = gcd_of_strings("LEET", "CODE");
    std::string str_gcd4 = gcd_of_strings("ABCDEF", "ABC");

    std::cout << "\"" << str_gcd1 << "\"" << std::endl;
    std::cout << "\"" << str_gcd2 << "\"" << std::endl;
    std::cout << "\"" << str_gcd3 << "\"" << std::endl;
    std::cout << "\"" << str_gcd4 << "\"" << std::endl;

    return 0;
}

std::string gcd_of_strings(std::string str1, std::string str2)
{
    // By definition, for two strings to have a gcd, one must be a substring of
    // the other. If they aren't, then they don't have a gcd.

    if ((str1 + str2) != (str2 + str1))
        return "";

    // If we get to this point, we now know the strings have a gcd. To calculate
    // it, we need to know the gcd of the length of the strings. Then, the
    // substring of said length is the gcd of the given strings.

    size_t str1_len = str1.length();
    size_t str2_len = str2.length();
    size_t gcd_len = std::gcd(str1_len, str2_len);

    return str1.substr(0, gcd_len);
}
