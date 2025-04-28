// Name: 121. Best Time to Buy and Sell Stock I
// Topics: Array, Dynamic Programming, Sliding Window
// Companies:
// - Morgan Stanley
// - Zoho
// - IBM
// - Infosys
// - Accenture
// - josh technology
// - Walmart Labs
// - VMware
// - Visa
// - Agoda
// - Nvidia
// - Samsung
// - Media.net
// - EPAM Systems
// - J.P. Morgan
// - Uber
// - Tesla
// - PayPal
// - ServiceNow
// - Capgemini
// - Yahoo
// - DE Shaw
// - Siemens
// - Intel
// - Salesforce
// - Capital One
// - tcs
// - PhonePe
// - Deutsche Bank
// - Robinhood
// - Goldman Sachs
// - Yandex
// - TikTok
// - Two Sigma
// - Citadel
// - Oracle
// - Expedia
// - Tinkoff
// - BlackRock
// - Myntra
// - MakeMyTrip
// - Instacart
// - Netflix
// - Arista Networks
// - BNY Mellon
// - Intuit
// - Nutanix
// - SAP
// - Zopsmart
// - Cisco
// - eBay
// - Snap
// - ByteDance
// - Palantir Technologies
// - Sprinklr
// - Atlassian
// - Turing
// - Flipkart
// - Roblox
// - LinkedIn

use std::cmp;

fn main()
{
    let stocks_1: Vec<i32> = vec![7, 1, 5, 3, 6, 4];
    let stocks_2: Vec<i32> = vec![7, 6, 4, 3, 1];

    let best_gain_1: i32 = max_profit(stocks_1);
    let best_gain_2: i32 = max_profit(stocks_2);

    println!("121. Best Time to Buy and Sell Stock I");
    println!("{}", best_gain_1);
    println!("{}", best_gain_2);
}

fn max_profit(prices: Vec<i32>) -> i32
{
    // We need at least two days: One for buying, and one for selling.
    if prices.len() < 2 { return 0; }

    let mut i: usize = 0;
    let mut j: usize = 1;
    let mut profit: i32 = 0;

    // To find the best profit, we'll be iterating the list of prices, using
    // a sliding window-esque approach. What we want is to find those two days
    // where the difference is highest, and prices[i] < prices[j].

    while j < prices.len()
    {
        if prices[i] >= prices[j]
        {
            // If the buying day is equal to or more expensive than the selling day,
            // then there's no profit, so we just move on. We can skip that whole
            // range because by definition, there won't be a possible answer before j.
            i = j;
        }
        else
        {
            // Keep checking the differences/profits, and look to maximize it.
            profit = cmp::max(profit, prices[j] - prices[i]);
        }
        j += 1;
    }

    profit
}
