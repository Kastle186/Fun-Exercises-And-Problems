#!/usr/bin/env node

'use strict';

function readLine()
{
    return inputString[currentLine++];
}

function extraLongFactorial(num)
{
    // We know the factorials of both, 0 and 1, equal 1. It is not necessary
    // to do dynamic programming for this exercise, as we are only getting asked
    // to calculate one factorial, but we'll do it just for some extra practice.

    const fact_dp = [BigInt(1), BigInt(1)];
    var result = BigInt(1);

    for (let i = 2; i <= num; i++)
    {
        let prev_fact = fact_dp[i - 1];
        result = BigInt(i) * prev_fact
        fact_dp.push(result);
    }

    console.log(result.toString());
}

function main()
{
    const number = parseInt(readLine().trim(), 10);
    extraLongFactorial(number);
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
