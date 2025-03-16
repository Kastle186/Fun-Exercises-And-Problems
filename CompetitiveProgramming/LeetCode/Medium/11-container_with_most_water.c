// Name: 11. Container With Most Water
// Topics: Array, Two Pointers, Greedy
// Companies:
// - Wix
// - SAP
// - Flipkart
// - Tesla
// - Amazon
// - Oracle
// - Bloomberg
// - Yahoo
// - Microsoft
// - Adobe
// - Zoho
// - Goldman Sachs
// - Apple
// - Uber
// - Accenture
// - ByteDance
// - Snowflake
// - Paytm
// - Nutanix
// - Zopsmart
// - eBay
// - Visa
// - TikTok
// - Meta
// - ServiceNow
// - Salesforce
// - Yandex
// - Walmart Labs
// - Sprinklr
// - Infosys
// - tcs
// - PayPal
// - Citadel
// - Atlassian

#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int max_area(int *, int);

int main(void)
{
    int container1[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int container2[] = { 1, 1 };

    int water1 = max_area(&container1[0], 9);
    int water2 = max_area(&container2[0], 2);

    printf("%d\n", water1);
    printf("%d\n", water2);
    return 0;
}

int max_area(int *heights, int num_heights)
{
    int largest_area = 0;
    int container_len = num_heights - 1;

    // First, we'll start with two pointers, one on each side of the container
    // of water, and calculate the volume. The volume is the multiplication of
    // the length of the container by the shortest bar.

    int *left = heights;
    int *right = heights + container_len;

    while (left < right)
    {
        int this_area = MIN(*left, *right) * container_len;

        // Update if we've found a larger volume.

        if (this_area > largest_area)
            largest_area = this_area;

        // Then, shorten the container by removing the shortest bar. Going this
        // way allows us to implicitly discard volumes that will have no chance
        // of yielding a larger volume, and thus we won't have to check all
        // possible combinations. With this, we can stick to an O(N) runtime.

        if (*left < *right)
            left++;
        else if (*right < *left)
            right--;
        else
        {
            // If both bars are equal, then we move the one whose next bar
            // is largest to maximize the gain.

            if (*(left + 1) > *(right - 1))
                left++;
            else
                right--;
        }

        container_len--;
    }

    return largest_area;
}
