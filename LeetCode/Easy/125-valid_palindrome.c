// Name: 125. Valid Palindrome
// Topics:
// Companies:
// - Zenefits
// - EPAM Systems
// - Yandex
// - Spotify
// - Wipro
// - SAP
// - American Express
// - Capgemini
// - Accenture
// - Wayfair
// - ServiceNow
// - Infosys
// - Turing
// - PayPal
// - TikTok
// - Cisco

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_palindrome(const char *);

int main(void)
{
    const char *str1 = (const char *) "A man, a plan, a canal: Panama";
    const char *str2 = (const char *) "race a car";
    const char *str3 = (const char *) " ";

    puts("125. Valid Palindrome");
    printf("%s\n", is_palindrome(str1) ? "true" : "false");
    printf("%s\n", is_palindrome(str2) ? "true" : "false");
    printf("%s\n", is_palindrome(str3) ? "true" : "false");

    return 0;
}

bool is_palindrome(const char *str)
{
    const char *left = str;
    const char *right = str + strlen(str) - 1;

    // The classic palindrome problem. We'll apply the usual approach of using
    // two pointers and check the characters until either the pointers overlap,
    // or their respective characters differ.

    while (left < right)
    {
        // Skip non-alphanumeric characters.
        while (left < right && !isalnum(*left)) left++;
        while (left < right && !isalnum(*right)) right--;

        // The core comparison.
        if (tolower(*left) != tolower(*right))
            return false;

        // Move pointers to their respective next elements.
        left++;
        right--;
    }

    return true;
}
