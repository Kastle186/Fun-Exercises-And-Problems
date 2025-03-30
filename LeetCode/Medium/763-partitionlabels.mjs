#!/usr/bin/env node

// Name: 763. Partition Labels
// Topics: Hash Table, Two Pointers, String, Greedy
// Companies: Sprinklr

'use strict';

/**
 * @param {string} s
 * @return {number[]}
 */
function partitionLabels(s)
{
    const lastIndices = new Map();
    const partitionSizes = [];

    // First, we have to find the indices where each character appears for the
    // last time. This is to ensure that they won't appear in more than one
    // partition.

    for (let i = 0; i < s.length; i++)
    {
        lastIndices.set(s[i], i);
    }

    // With that done, we can pass again through the string, and using the indices
    // map we constructed, define the points where the partition(s) will be.

    let partitionStart = 0;
    let partitionEnd = 0;

    for (let j = 0; j < s.length; j++)
    {
        partitionEnd = Math.max(partitionEnd, lastIndices.get(s[j]));

        // Add this partition's size to the answer array, and update the starting
        // point for the new partition.

        if (j === partitionEnd)
        {
            partitionSizes.push(j - partitionStart + 1);
            partitionStart = j + 1;
        }
    }

    return partitionSizes;
}

function main()
{
}

main();

// // Creating a dictionary using Map
// let dictionaryMap = new Map();

// // Adding entries
// dictionaryMap.set("apple", "A fruit that is typically red or green.");
// dictionaryMap.set("banana", "A long yellow fruit.");
// dictionaryMap.set("carrot", "A root vegetable, usually orange.");

// // Accessing values
// console.log(dictionaryMap.get("apple")); // Output: A fruit that is typically red or green.

// // Checking for a key
// console.log(dictionaryMap.has("carrot")); // Output: true

// // Iterating through entries
// dictionaryMap.forEach((value, key) => {
//     console.log(`${key}: ${value}`);
// });
