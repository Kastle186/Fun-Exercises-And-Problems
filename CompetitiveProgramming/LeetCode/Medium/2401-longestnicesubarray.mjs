#!/usr/bin/env node

// Name: 2401. Longest Nice Subarray
// Topics: Array, Bit Manipulation, Sliding Window
// Companies:
// - Paytm

'use strict';

/**
 * @param {number[]} nums
 * @return {number}
 */
function longestNiceSubarray(nums)
{
    // To find the longest subarray whose elements' AND bitwise operation is zero,
    // we will be using a mask as a dynamic programming-ish approach, based on the
    // sliding window principle.

    // By default, we treat each minimum subarray as nice. Also, the problem's
    // description guarantees every given input will have at least one element.
    let longestLen = 1;

    let subArrStart = 0;
    let subArrEnd = 0;
    let dpishMask = 0;

    while (subArrEnd < nums.length)
    {
        let nextElem = nums[subArrEnd];

        // If the next element's AND bitwise with our current subarray would break
        // the rules, then we remove the current firstmost with an XOR, as we added
        // it originally with an OR, and move the start pointer forward. Repeat
        // until we have a working nice subarray.

        while ((dpishMask & nextElem) !== 0)
        {
            dpishMask ^= nums[subArrStart];
            subArrStart += 1;
        }

        // Update the indices and mask keeping track of all the numbers in our
        // current subarray candidate.

        longestLen = Math.max(longestLen, subArrEnd - subArrStart + 1);
        dpishMask |= nextElem;
        subArrEnd += 1;
    }

    return longestLen;
}

function main()
{
    let nice1 = longestNiceSubarray([1, 3, 8, 48, 10]);
    let nice2 = longestNiceSubarray([3, 1, 5, 11, 13]);
    let nice3 = longestNiceSubarray([3, 6, 1, 2]);

    console.log(nice1);
    console.log(nice2);
    console.log(nice3);
}

main()
