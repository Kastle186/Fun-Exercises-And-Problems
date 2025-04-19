// Name: 38. Count and Say
// Topics: String
// Companies:
// - Pinterest
// - Akuna Capital
// - ConsultAdd
// - Wells Fargo
// - Meta
// - Zoho
// - Yahoo
// - Apple
// - Amazon
// - PayPal
// - Microsoft
// - Adobe
// - Bloomberg

#include <iostream>
#include <string>

std::string count_and_say(int);

int main(void)
{
    std::string cas_for_4 = count_and_say(4);
    std::string cas_for_1 = count_and_say(1);

    std::cout << cas_for_4 << std::endl;
    std::cout << cas_for_1 << std::endl;
    return 0;
}

std::string count_and_say(int n)
{
    // Base Case: For n = 1, the result is "1".
    if (n == 1)
        return "1";

    // Start with the n = 1 base case.
    std::string resultRLE = "1";

    for (int i = 2; i <= n; i++)
    {
        std::string nextRLE = "";
        char currNum = resultRLE[0];
        int currCount = 1;

        // Iterate through the elements of the current RLE string. Our goal here
        // is to check how many characters in a row there are, and transform those
        // into "count" + "num".

        for (int j = 1; j < resultRLE.length(); j++)
        {
            // If it's the same character, then add one to the count. Otherwise,
            // append its count+num result to the intermediate string, and reset
            // the counters.

            if (resultRLE[j] == currNum)
            {
                currCount++;
            }
            else
            {
                nextRLE += std::to_string(currCount) + currNum;
                currNum = resultRLE[j];
                currCount = 1;
            }
        }

        // Append the last character and then save this intermediate RLE string
        // in the final result variable.

        nextRLE += std::to_string(currCount) + currNum;
        resultRLE = nextRLE;
    }

    return resultRLE;
}
