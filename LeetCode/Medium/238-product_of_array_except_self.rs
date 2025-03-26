// Name: 238. Product of Array Except Self
// Topics: Array, Prefix Sum/Product
// Companies:
// - Docusign
// - Intuit
// - Flipkart
// - Accenture
// - Wells Fargo
// - MakeMyTrip
// - Autodesk
// - PayPal
// - LinkedIn
// - Infosys
// - Paytm
// - Nutanix
// - Visa
// - IBM
// - Turing
// - ServiceNow
// - Yandex
// - Zoho
// - Salesforce
// - Goldman Sachs
// - Cisco
// - Walmart Labs
// - tcs

fn main()
{
    let nums1: Vec<i32> = vec![1, 2, 3, 4];
    let nums2: Vec<i32> = vec![-1, 1, 0, -3, 3];

    let products1: Vec<i32> = product_except_self(nums1);
    let products2: Vec<i32> = product_except_self(nums2);

    println!("{:?}", products1);
    println!("{:?}", products2);
}

fn product_except_self(nums: Vec<i32>) -> Vec<i32>
{
    // This is a straightforward problem with a few restrictions that make it
    // less trivial. First, we have to make sure the algorithm runs in O(n) time.
    // And second, we are not allowed to use the division operator. Additionally,
    // we can optionally try running it also in O(1) space, excluding the returning
    // result array. We'll try to fulfill all the constraints in our solution.

    // First, we initialize our results array/vector with 1's, as we'll go multiplying
    // "in place".
    let mut result: Vec<i32> = vec![1; nums.len()];

    // We'll do two passes. One to calculate the prefix products, and one backwards
    // to calculate the postfix products.
    let mut prefix: i32 = 1;
    let mut postfix: i32 = 1;

    // Calculate the product of all numbers before any given one.
    for (i, val) in nums.iter().enumerate()
    {
        result[i] *= prefix;
        prefix *= val;
    }

    // Multiply the prefixes by the product of all numbers after the given one.
    for (j, val) in nums.iter().enumerate().rev()
    {
        result[j] *= postfix;
        postfix *= val;
    }

    result
}
