// Name: 122. Best Time to Buy and Sell Stock II
// Topics: Array, Dynamic Programming, Greedy
// Companies
// - Intel
// - Citadel
// - eBay
// - Wells Fargo
// - DE Shaw
// - Deutsche Bank
// - Geico
// - Instacart
// - Qualcomm
// - TikTok
// - Paytm
// - Media.net
// - Zoho
// - Goldman Sachs
// - Morgan Stanley
// - Walmart Labs
// - Infosys
// - PhonePe
// - J.P. Morgan
// - Yahoo
// - tcs
// - Yandex
// - Salesforce

fn main()
{
    let stocks_1: Vec<i32> = vec![7, 1, 5, 3, 6, 4];
    let stocks_2: Vec<i32> = vec![1, 2, 3, 4, 5];
    let stocks_3: Vec<i32> = vec![7, 6, 4, 3, 1];

    let best_gain_1: i32 = max_profit(stocks_1);
    let best_gain_2: i32 = max_profit(stocks_2);
    let best_gain_3: i32 = max_profit(stocks_3);

    println!("121. Best Time to Buy and Sell Stock II");
    println!("{}", best_gain_1);
    println!("{}", best_gain_2);
    println!("{}", best_gain_3);
}

fn max_profit(prices: Vec<i32>) -> i32
{
    // We need at least two days: One for buying, and one for selling.
    if prices.len() < 2 { return 0; }

    let mut i: usize = 0;
    let mut j: usize = 1;
    let mut profit: i32 = 0;

    // To find the best profit, we'll be iterating the list of prices, using
    // a two-pointer approach. Basically, we need to find every time we can sell
    // for a profit, so the result will be the sum of all differences, where
    // prices[i] < prices[j] for every i < j.

    while j < prices.len()
    {
        if prices[i] < prices[j]
        {
            profit += (prices[j] - prices[i]);
        }

        i = j;
        j += 1;
    }

    profit
}
