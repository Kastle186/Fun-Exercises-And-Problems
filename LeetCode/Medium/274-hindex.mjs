#!/usr/bin/env node

// Name: 274. H-Index
// Topics: Array, Sorting, Counting Sort
// Companies:
// - Nvidia
// - ByteDance
// - Yandex

'use strict';

/**
 * @param {number[]} citations
 * @return {number}
 */
function hIndex(citations)
{
    citations.sort((a, b) => a - b);
    let hValue = 0;

    for (let i = citations.length - 1; i >= 0; i--)
    {
        if (citations[i] <= hValue)
            break;

        hValue += 1;
    }

    return hValue;
}

function main()
{
    let citations1 = [3, 0, 6, 1, 5];
    let citations2 = [1, 3, 1];

    let hNum1 = hIndex(citations1);
    let hNum2 = hIndex(citations2);

    console.log(hNum1);
    console.log(hNum2);
}

main();
