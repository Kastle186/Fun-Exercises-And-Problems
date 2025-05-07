// Name: 15. 3Sum
// Topics:
// Companies:
// - Wix
// - Agoda
// - Meta
// - Docusign
// - Bloomberg
// - Adobe
// - Amazon
// - Tesla
// - Microsoft
// - Barclays
// - Accenture
// - Visa
// - Apple
// - Zomato
// - TikTok
// - Samsung
// - Paytm
// - Walmart Labs
// - Yahoo
// - Infosys
// - American Express
// - Oracle
// - Uber
// - Intuit
// - Grab
// - Myntra
// - Siemens
// - Cognizant
// - ServiceNow
// - Salesforce
// - BNY Mellon
// - EPAM Systems
// - Nutanix
// - tcs
// - Zoho
// - Zopsmart
// - eBay
// - Flipkart
// - Sprinklr
// - DE Shaw
// - Cisco
// - Nvidia
// - PayPal
// - Citadel
// - Goldman Sachs
// - DoorDash
// - Atlassian
// - Yandex

fn main()
{
    let numbers_1: Vec<i32> = vec![-1, 0, 1, 2, -1, -4];
    let numbers_2: Vec<i32> = vec![0, 1, 1];
    let numbers_3: Vec<i32> = vec![0, 0, 0];

    let triplets_1: Vec<i32> = three_sum(numbers_1);
    let triplets_2: Vec<i32> = three_sum(numbers_2);
    let triplets_3: Vec<i32> = three_sum(numbers_3);

    println!("15. 3Sum");
    println!("{:?}", triplets_1);
    println!("{:?}", triplets_2);
    println!("{:?}", triplets_3);
}

fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>>
{
    // Can't have triplets if there are less than 3 elements in the array :)
    if nums.len() < 3 { return Vec::new(); }

    // Sort the array for deterministic expectations of the elements for the two,
    // or in this case, three-pointer approach.
    nums.sort_unstable();

    let mut i: usize = 0;
    let mut result: Vec<Vec<i32>> = Vec::new();

    // Iterate through the potential triplets while discarding those that have
    // no chance of being answers by definition. E.g., the first element is more
    // than zero. Can't find smaller ones afterward since the array is sorted.

    while i < nums.len() - 2 && nums[i] <= 0
    {
        // Don't process duplicate starts, i.e. duplicates in the left pointer,
        // as that would yield duplicate triplets.
        if i > 0 && nums[i] == nums[i - 1]
        {
            i += 1;
            continue;
        }

        let mut j: usize = i + 1;
        let mut k: usize = nums.len() - 1;

        // Check the triplet and adjust the pointers accordingly until either we
        // find a valid triplet, or we run out of elements to test in this iteration.

        while j < k
        {
            let triplet_sum = nums[i] + nums[j] + nums[k];

            // - If the current triplet yields less than zero, then move the middle
            //   pointer forward for a bigger element.
            //
            // - If the current triplet yields more than zero, then move the right
            //   pointer backward for a smaller element.
            //
            // - If the current triplet yields zero, then add it to the result, and
            //   move both non-start pointers to test the next combination.

            if triplet_sum < 0 { j += 1; }
            else if triplet_sum > 0 { k -= 1; }
            else
            {
                result.push(vec![nums[i], nums[j], nums[k]]);

                j += 1;
                k -= 1;

                // Skip duplicates in the middle pointer.
                while j < k && nums[j] == nums[j - 1] { j += 1; }
                // Skip duplicates in the right pointer.
                while j < k && nums[k] == nums[k + 1] { k -= 1; }
            }
        }

        i += 1;
    }

    result
}
