// Name: 3. Longest Substring Without Repeating Characters
// Topics: Hash Table, String, Sliding Window
// Companies:
// - Tinkoff
// - Tesla
// - Spotify
// - Walmart Labs
// - Yelp
// - EPAM Systems
// - Zoho
// - Agoda
// - TikTok
// - Oracle
// - Bloomberg
// - Infosys
// - Turing
// - eBay
// - Amazon
// - ByteDance
// - Microsoft
// - Apple
// - Palo Alto Networks
// - Yandex
// - ServiceNow
// - Adobe
// - Nvidia
// - Flipkart
// - josh technology
// - Grab
// - Yahoo
// - Accenture
// - Visa
// - IBM
// - Intel
// - Docusign
// - Wipro
// - Intuit
// - Google
// - Morgan Stanley
// - Salesforce
// - Expedia
// - Accolite
// - Zeta
// - Meta
// - Lyft
// - MakeMyTrip
// - VMware
// - Qualcomm
// - ZScaler
// - BNY Mellon
// - PayPal
// - Arcesium
// - Capgemini
// - Uber
// - J.P. Morgan
// - Nutanix
// - American Express
// - Epic Systems
// - Goldman Sachs
// - Netflix
// - PhonePe
// - tcs
// - Atlassian
// - Roblox
// - LinkedIn
// - Cisco

import java.util.HashSet;
import java.util.Set;

class Solution
{
    public static void main(String[] args)
    {
        String str1 = "abcabcbb";
        String str2 = "bbbbb";
        String str3 = "pwwkew";

        int longestUnique1 = lengthOfLongestSubstring(str1);
        int longestUnique2 = lengthOfLongestSubstring(str2);
        int longestUnique3 = lengthOfLongestSubstring(str3);

        System.out.println("3. Longest Substring Without Repeating Characters");
        System.out.println(longestUnique1);
        System.out.println(longestUnique2);
        System.out.println(longestUnique3);
    }

    private static int lengthOfLongestSubstring(String s)
    {
        // The longest substring of an empty string is also an empty string, and
        // a single character is its own longest substring :)
        if (s.length() < 2)
            return s.length();

        // To solve this problem, we will be storing the characters we find in a
        // hash set, in order to know when we find duplicates to adapt the sliding
        // window accordingly.

        Set<Character> charsInSubstr = new HashSet<>();
        int maxSubstrLen = 0;
        int left = 0;
        int right = 0;

        while (left <= right && right < s.length())
        {
            if (charsInSubstr.contains(s.charAt(right)))
            {
                // If we've found this character already, then shrink the substring
                // until we get rid of the duplicate. Also, remove the characters
                // from the set as they are no longer part of the substring.

                while (s.charAt(left) != s.charAt(right) && left < right)
                    charsInSubstr.remove(s.charAt(left++));
                charsInSubstr.remove(s.charAt(left++));
            }
            else
            {
                // Otherwise, add this new character to the set and grow the
                // substring, while updating accordingly to keep track of the
                // largest we've found so far.

                charsInSubstr.add(s.charAt(right++));
                maxSubstrLen = Math.max(maxSubstrLen, right - left);
            }
        }

        return maxSubstrLen;
    }
}
