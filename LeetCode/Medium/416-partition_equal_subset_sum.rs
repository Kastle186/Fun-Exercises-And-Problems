// Name: 416. Partition Equal Subset Sum
// Topics: Array, Dynamic Programming
// Companies:
// - eBay
// - Zoho
// - EPAM Systems
// - Flipkart
// - ServiceNow
// - Walmart Labs
// - IBM

use std::collections::HashSet;

fn main()
{
    let nums1: Vec<i32> = vec![1, 5, 11, 5];
    let nums2: Vec<i32> = vec![1, 2, 3, 5];
    let nums3: Vec<i32> = vec![2, 2, 1, 1];

    println!("{}", can_partition(nums1));
    println!("{}", can_partition(nums2));
    println!("{}", can_partition(nums3));
}

fn can_partition(nums: Vec<i32>) -> bool
{
    let nums_sum: i32 = nums.iter().sum();

    // If the total sum of the numbers array is not even, then by definition it
    // is not possible to split it into to subarrays.
    if nums_sum % 2 != 0
    {
        return false
    }

    // We'll be keeping track of all the possible sum additions we encounter.
    // These partial sums will be formed by testing adding elements to already
    // existing subsets we've found. Since the function only requires to know
    // whether it's possible or not, we don't have to keep track of which elements
    // would form that subset.

    let target: i32 = nums_sum / 2;
    let mut dp_set: HashSet<i32> = HashSet::new();
    dp_set.insert(0);

    // We iterate backwards to ensure we don't repeat numbers. When we find the
    // target, we can stop and return true. If we don't find it, then we'll just
    // reach the end of the function and return false.

    for num in nums.into_iter().rev()
    {
        // Need to do this to avoid mutable/immutable Rust errors.
        let next_dp_set: HashSet<i32> = dp_set.clone();

        for partial in next_dp_set
        {
            let next_partial: i32 = partial + num;

            if next_partial == target
            {
                return true;
            }

            dp_set.insert(next_partial);
        }
    }

    false
}
