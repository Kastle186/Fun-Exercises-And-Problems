#!/usr/bin/env node

'use strict';

function readLine()
{
    return inputString[currentLine++];
}

function superDigitHelper(num)
{
    // If we only have one digit left, then that's the super digit.

    if (num < 10)
        return num;

    // Otherwise, we add up all the digits of our number and then recurse until
    // we find our super digit. To do this, we add the % 10 and then divide the
    // number / 10 to "shift" to the next digit.

    let nextSuper = 0;

    while (num > 0)
    {
        nextSuper += num % 10;
        num = Math.trunc(num / 10);
    }

    return superDigitHelper(nextSuper);
}

function superDigit(n, k)
{
    // We only need to calculate the sum of digits of the first repetition of
    // the number, since then we can simply multiply it by k, rather than
    // constructing the potentially miles long number string.

    let start = 0

    for (let ch of n)
    {
        start += parseInt(ch, 10);
    }

    return superDigitHelper(start * k);
}

function main()
{
    const firstMultipleInput = readLine().replace(/\s+$/g, '').split(' ');
    const n = firstMultipleInput[0];
    const k = parseInt(firstMultipleInput[1], 10);
    const result = superDigit(n, k);
    console.log(result);
}

// Hackerrank setup to read from STDIN and run the app.

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});
