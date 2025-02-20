#!/usr/bin/env node

// Name: Two Sum
// Topics: Array, Hash Table
// Companies:
// - Yahoo
// - Wipro
// - SAP
// - Microsoft
// - Infosys
// - Google
// - Capgemini
// - Bloomberg
// - Apple
// - Amazon
// - Adobe
// - Spotify
// - Visa
// - Uber
// - Yelp
// - Accenture
// - Dropbox
// - SoFi
// - Oracle
// - EPAM Systems
// - Expedia
// - Tinkoff
// - IBM
// - Grab
// - Barclays
// - Huawei
// - Meta
// - VMware
// - tcs
// - Samsung
// - Zoho
// - Accolite
// - Yandex
// - ServiceNow
// - Cognizant
// - Airbnb
// - ZScaler
// - Walmart Labs
// - Morgan Stanley
// - Nvidia
// - MongoDB
// - Ozon
// - PayPal
// - Siemens
// - Intel
// - Docusign
// - Intuit
// - BNY Mellon
// - Meesho
// - Nutanix
// - American Express
// - Cruise
// - TikTok
// - Palo Alto Networks
// - Capital One
// - Goldman Sachs
// - LinkedIn
// - ByteDance
// - Flipkart
// - DoorDash
// - Turing
// - Paytm
// - Cisco
// - Karat
// - J.P. Morgan
// - Epic Systems
// - eBay
// - MathWorks
// - Deutsche Bank
// - BlackRock
// - Atlassian
// - Roblox
// - Pinterest

'use strict';

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function twoSum(nums, target)
{
    // To find the two numbers from the array whose sum is target, we could
    // test all the possible combinations. However, that would be an O(n^2)
    // algorithm. We can simplify it to O(n) by using a hash map, where we can
    // store each number we encounter with its index(es). Then, as we iterate,
    // we check our map. If the number needed to reach target is there, then
    // we've found our solution.

    let numsIndices = new Map();

    for (const [index, value] of nums.entries())
    {
        let summandNeeded = target - value;

        if (numsIndices.has(summandNeeded))
            return [numsIndices.get(summandNeeded), index];

        numsIndices.set(value, index);
    }

    return [];
}

function main()
{
    let summands_1 = twoSum([2, 7, 11, 15], 9);
    let summands_2 = twoSum([3, 2, 4], 6);
    let summands_3 = twoSum([3, 3], 6);

    console.log(summands_1);
    console.log(summands_2);
    console.log(summands_3);
}

main()
