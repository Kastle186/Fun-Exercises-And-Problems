// Name: 14. LongestCommonPrefix
// Topics: String, Trie
// Companies:
// - Yelp
// - SAP
// - Visa
// - Adobe
// - EPAM Systems
// - Accenture
// - Zoho
// - Apple
// - Uber
// - Bloomberg
// - Amazon
// - Cognizant
// - IBM
// - Google
// - Deutsche Bank
// - Meta
// - Capgemini
// - Turing
// - Infosys
// - Microsoft
// - Yahoo
// - Accolite
// - tcs
// - VMware
// - ZScaler
// - Walmart Labs
// - Nutanix
// - American Express
// - Oracle
// - TikTok
// - PhonePe
// - Samsung
// - Salesforce
// - Roblox
// - Nvidia

public class LongestCommonPrefix
{
    public static void main(String[] args)
    {
        String[] strs1 = { "flower", "flow", "flight" };
        String[] strs2 = { "dog", "racecar", "car" };

        String prefix1 = longestCommonPrefix(strs1);
        String prefix2 = longestCommonPrefix(strs2);

        System.out.println(prefix1.isEmpty() ? "<empty>" : prefix1);
        System.out.println(prefix2.isEmpty() ? "<empty>" : prefix2);
    }

    public static String longestCommonPrefix(String[] strs)
    {
        // To find the longest common prefix in the array of strings, a Trie would
        // be the ideal data structure. However, because of the simplicity of only
        // having to deal with the beginning of each string, we can instead use a
        // nested loop and save us some memory.

        String baseStr = strs[0];

        for (int i = 0; i < baseStr.length(); i++)
        {
            for (String s : strs)
            {
                // Whenever we get to the end of any string before the base one,
                // or when we find a different character, then we have finished
                // finding the longest common subsequence. If any string is the
                // empty string, there is no such subsequence.

                if (i >= s.length() || s.charAt(i) != baseStr.charAt(i))
                    return i == 0 ? "" : baseStr.substring(0, i);
            }
        }

        return baseStr;
    }
}
