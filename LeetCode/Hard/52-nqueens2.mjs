#!/usr/bin/env node

// Name: 52. N-Queens II
// Topics: Backtracking
// Companies:
// - Zenefits
// - ServiceNow
// - Bloomberg
// - Microsoft
// - Google
// - Amazon

'use strict';

function nQueensHelperDbg(row, n, cols, ascDiagDp, descDiagDp, result)
{
    console.log(`Entering row ${row}, current result: ${result}`);

    // Base case: We've reached a new solution to count.
    if (row == n)
    {
        console.log("Found a valid solution!");
        return result + 1;
    }

    for (let col = 0; col < n; col++)
    {
        let ascDiagIndex = row + col;
        let descDiagIndex = row - col + n;

        // If any either this column, or any of the diagonals are already attacked
        // on this position, then ignore it and move to the next.

        console.log(`Trying position row ${row}, col ${col}`);

        if (cols[col] == 1 || ascDiagDp[ascDiagIndex] == 1 || descDiagDp[descDiagIndex] == 1)
        {
            console.log(`Position row ${row}, col ${col} is under attack, skipping`);
            continue;
        }

        // Set a queen in the current position.

        cols[col] = 1;
        ascDiagDp[ascDiagIndex] = 1;
        descDiagDp[descDiagIndex] = 1;

        console.log(`Placed queen at row ${row}, col ${col}`);
        console.log(`Board state: cols=${cols}, ascDiagDp=${ascDiagDp}, descDiagDp=${descDiagDp}`);

        // Recurse for the next row.
        result = nQueensHelper(row + 1, n, cols, ascDiagDp, descDiagDp, result);

        // Remove the last placed queen to try out another combination.
        cols[col] = 0;
        ascDiagDp[ascDiagIndex] = 0;
        descDiagDp[descDiagIndex] = 0;

        console.log(`Backtracking from row ${row}, col ${col}`);
        console.log(`Board state after backtracking: cols=${cols}, ascDiagDp=${ascDiagDp}, descDiagDp=${descDiagDp}`);
    }

    console.log(`Exiting row ${row}, current result: ${result}`);
    return result;
}

function nQueensHelper(row, n, cols, ascDiagDp, descDiagDp, result)
{
    // Base case: We've reached a new solution to count.
    if (row == n)
        return result + 1;

    for (let col = 0; col < n; col++)
    {
        let ascDiagIndex = row + col;
        let descDiagIndex = row - col + n;

        // If any either this column, or any of the diagonals are already attacked
        // on this position, then ignore it and move to the next.

        if (cols[col] == 1 || ascDiagDp[ascDiagIndex] == 1 || descDiagDp[descDiagIndex] == 1)
            continue;

        // Set a queen in the current position.

        cols[col] = 1;
        ascDiagDp[ascDiagIndex] = 1;
        descDiagDp[descDiagIndex] = 1;

        // Recurse for the next row.
        result = nQueensHelper(row + 1, n, cols, ascDiagDp, descDiagDp, result);

        // Remove the last placed queen to try out another combination.

        cols[col] = 0;
        ascDiagDp[ascDiagIndex] = 0;
        descDiagDp[descDiagIndex] = 0;
    }

    return result;
}

/**
 * @param {number} n
 * @return {number}
 */
function totalNQueens(n)
{
    if (n == 1)
        return 1;

    let cols = new Array(n).fill(0);
    let ascDiagDp = new Array(n * 2).fill(0);
    let descDiagDp = new Array(n * 2).fill(0);

    return nQueensHelper(0, n, cols, ascDiagDp, descDiagDp, 0);
}

function main()
{
    const fourQueens = totalNQueens(4);
    const oneQueen = totalNQueens(1);

    console.log(fourQueens);
    console.log(oneQueen);
}

main();
