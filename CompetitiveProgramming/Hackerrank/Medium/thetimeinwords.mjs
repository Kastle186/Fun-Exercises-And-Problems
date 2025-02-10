#!/usr/bin/env node

'use strict';

function readLine()
{
    return inputString[currentLine++];
}

function timeInWords(hour, minute)
{
    const writtenNumbers = [
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine",
    ];

    // Sharp hours are the only ones where the hour goes before the minutes in
    // their written expression.

    if (minute === 0)
        return writtenNumbers[hour] + " o' clock";

    var timeWords = '';

    switch (minute)
    {
        case 15:
        case 45:
            timeWords += 'quarter';
            break;

        case 30:
            timeWords += 'half';
            break;

        case 1:
        case 59:
            timeWords += 'one minute';
            break;

        default:
            // Here is a less than obvious case. If minutes are less than 30, then
            // we simply take its word representation. But otherwise, since we are
            // saying how many minutes until the current hour ends, which is less
            // then 30, we have to subtract the difference from 30.

            timeWords += (minute < 30)
                ? writtenNumbers[minute]
                : writtenNumbers[30 - (minute % 30)];

            timeWords += ' minutes';
            break;
    }

    // Similarly to the default clause of the previous switch case, here we have
    // to make the distinction between 'past' and 'to'. Additionally, for the hour,
    // we do 'hour % 13' to handle the cases of 12:31-12:59. We don't say x minutes
    // to thirteen. We say x minutes to one, considering we are working with 12-hour
    // time settings.

    timeWords += (minute <= 30)
        ? (' past ' + writtenNumbers[hour])
        : (' to ' + writtenNumbers[(hour % 13) + 1]);

    return timeWords;
}

function main()
{
    const h = parseInt(readLine().trim(), 10);
    const m = parseInt(readLine().trim(), 10);
    const result = timeInWords(h, m);
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
