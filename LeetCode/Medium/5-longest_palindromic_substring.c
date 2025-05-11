// Name: 5. Longest Palindromic Substring
// Topics: Two Pointers, String, Dynamic Programming
// Companies:
// - Cisco
// - Zoho
// - Wix
// - Oracle
// - Amazon
// - Bloomberg
// - Microsoft
// - EPAM Systems
// - TikTok
// - Wayfair
// - Tinkoff
// - Accenture
// - Walmart Labs
// - Zepto
// - Huawei
// - Visa
// - Yahoo
// - Apple
// - Adobe
// - ByteDance
// - Nutanix
// - Yandex
// - J.P. Morgan
// - Accolite
// - Grab
// - PhonePe
// - Commvault
// - Uber
// - ServiceNow
// - Morgan Stanley
// - Meta
// - VMware
// - Infosys
// - Paytm
// - IBM
// - SAP
// - Media.net
// - eBay
// - Goldman Sachs
// - Agoda
// - tcs
// - Salesforce
// - PayPal
// - Samsung
// - Turing
// - LinkedIn

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longest_palindrome(char *);
void find_palindrome(char *, size_t, int *, size_t *, int, int);

int main(void)
{
    char *s1 = (char *) "babad";
    char *s2 = (char *) "cbbd";

    char *pal_1 = longest_palindrome(s1);
    char *pal_2 = longest_palindrome(s2);

    puts("5. Longest Palindromic Substring");
    printf("%s\n", pal_1);
    printf("%s\n", pal_2);

    free(pal_1);
    free(pal_2);

    return 0;
}

char *longest_palindrome(char *s)
{
    size_t s_len = strlen(s);

    // A single character is a palindrome for itself by definition.
    if (s_len == 1)
        return s;

    int longest_start = 0;
    size_t longest_len = 1;

    for (int i = 0; i < s_len; i++)
    {
        // Find biggest odd-lengthed palindrome so far.
        find_palindrome(s, s_len, &longest_start, &longest_len, i, i);

        // Find biggest even-lengthed palindrome so far.
        find_palindrome(s, s_len, &longest_start, &longest_len, i, i + 1);
    }

    char *result = (char *) calloc(longest_len + 1, sizeof(char));

    for (int i = 0; i < longest_len; i++)
        *(result + i) = *(s + longest_start + i);

    *(result + longest_len) = '\0';
    return result;
}

void find_palindrome(char *s,
                     size_t s_len,
                     int *longest_start,
                     size_t *longest_len,
                     int start,
                     int end)
{
    while (start >= 0 && end < s_len && *(s + start) == *(s + end))
    {
        size_t substr_len = end - start + 1;

        if (substr_len > *longest_len)
        {
            *longest_len = substr_len;
            *longest_start = start;
        }

        start--;
        end++;
    }
}
