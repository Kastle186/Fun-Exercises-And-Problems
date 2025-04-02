// Name: 2873. Maximum Value of an Ordered Triplet I
// Topics: Array
// Companies: Media.net

use std::cmp::max;

fn main()
{
    let nums_1: Vec<i32> = vec![12, 6, 1, 2, 7];
    let nums_2: Vec<i32> = vec![1, 10, 3, 4, 19];
    let nums_3: Vec<i32> = vec![1, 2, 3];

    let ordered_trpl_1 = maximum_triplet_value(nums_1);
    let ordered_trpl_2 = maximum_triplet_value(nums_2);
    let ordered_trpl_3 = maximum_triplet_value(nums_3);

    println!("{}", ordered_trpl_1);
    println!("{}", ordered_trpl_2);
    println!("{}", ordered_trpl_3);
}

fn maximum_triplet_value(nums: Vec<i32>) -> i64
{
    // To solve this problem in linear time rather than cubic time, we will be
    // keeping track of the biggest element, biggest difference, and biggest
    // triplet results so far, in a greedy-algorithm-esque fashion. However,
    // it is important to note that the order matters.
    //
    // First, update the biggest triplet, then the element, and lastly the
    // difference. This is because since we are updating the three values with
    // each number, we can potentially end up using the same number twice or
    // thrice in our triplets operations, violating the i < j < k constraints
    // in the last element. If we follow this order, we can make sure that the
    // last element is only used to update the max triplet if fitting, and that
    // the max diff uses always the latest max element throughout the algorithm.

    let mut max_elem: i64 = 0;
    let mut max_diff: i64 = 0;
    let mut max_triplet: i64 = 0;

    for &elem in nums.iter()
    {
        let elem_unwrap = elem as i64;
        max_triplet = max(max_triplet, max_diff * elem_unwrap);
        max_elem = max(max_elem, elem_unwrap);
        max_diff = max(max_diff, max_elem - elem_unwrap);
    }

    max_triplet
}
