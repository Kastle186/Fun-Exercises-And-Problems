#include <iostream>

std::string strings_xor(std::string, std::string);

int main()
{
    std::string s, t;
    std::cin >> s >> t;
    std::cout << strings_xor(s, t) << std::endl;
    return 0;
}

std::string strings_xor(std::string s, std::string t)
{
    std::string res = "";

    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == t[i])
            res.append("0");
        else
            res.append("1");
    }
    
    return res;
}
