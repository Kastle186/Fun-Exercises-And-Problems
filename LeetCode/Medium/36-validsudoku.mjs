#!/usr/bin/env node

// Name: 36. Valid Sudoku
// Topics: Array, Hash Table, Matrix
// Companies:
// - Snap
// - Geico
// - MongoDB
// - Uber
// - Apple
// - Walmart Labs
// - Instacart
// - Amazon
// - Autodesk
// - Karat
// - Media.net
// - Zoho
// - Microsoft
// - Adobe
// - Bloomberg
// - Nvidia
// - Meta
// - Oracle
// - Yahoo
// - Goldman Sachs
// - DoorDash
// - Yandex
// - TikTok

'use strict';

/**
 * @param {character[][]} board
 * @return {boolean}
 */
function isValidSudoku(board)
{
    const SUDOKU_DIMENSION = 9;

    // To check whether the board represents a valid Sudoku at that given point
    // in time (i.e. doesn't have to be fully solvable necessarily), we'll have
    // to keep track of all the numbers we encounter on each row, column, and block.
    // We'll need a total of 27 Sets. 9 rows, 9 columns, 9 blocks.

    let rowsChecks = Array.from({ length: SUDOKU_DIMENSION }, () => new Set());
    let colsChecks = Array.from({ length: SUDOKU_DIMENSION }, () => new Set());
    let blocksChecks = Array.from({ length: SUDOKU_DIMENSION }, () => new Set());

    for (let i = 0; i < SUDOKU_DIMENSION; i++)
    {
        for (let j = 0; j < SUDOKU_DIMENSION; j++)
        {
            const val = board[i][j];

            // Empty value is okay, so we just move on to the next one.
            if (val == '.')
                continue;

            // The formula int(i / 3) * 3 + int(j / 3) yields what block this
            // coordinate is located in.
            const block = (Math.floor(i / 3) * 3) + (Math.floor(j / 3));

            // If we've found this number before on either this row, this column,
            // or this block, then we can finish early as we can know it's not
            // valid. Otherwise, add this number and continue checking until we
            // either find an invalid value, or finish the board and return true.

            if (rowsChecks[i].has(val)
                || colsChecks[j].has(val)
                || blocksChecks[block].has(val))
                return false;

            rowsChecks[i].add(val);
            colsChecks[j].add(val);
            blocksChecks[block].add(val);
        }
    }

    return true;
}

function main()
{
    const board1 =
          [["5","3",".",".","7",".",".",".","."]
           ,["6",".",".","1","9","5",".",".","."]
           ,[".","9","8",".",".",".",".","6","."]
           ,["8",".",".",".","6",".",".",".","3"]
           ,["4",".",".","8",".","3",".",".","1"]
           ,["7",".",".",".","2",".",".",".","6"]
           ,[".","6",".",".",".",".","2","8","."]
           ,[".",".",".","4","1","9",".",".","5"]
           ,[".",".",".",".","8",".",".","7","9"]];

    const board2 =
          [["8","3",".",".","7",".",".",".","."]
           ,["6",".",".","1","9","5",".",".","."]
           ,[".","9","8",".",".",".",".","6","."]
           ,["8",".",".",".","6",".",".",".","3"]
           ,["4",".",".","8",".","3",".",".","1"]
           ,["7",".",".",".","2",".",".",".","6"]
           ,[".","6",".",".",".",".","2","8","."]
           ,[".",".",".","4","1","9",".",".","5"]
           ,[".",".",".",".","8",".",".","7","9"]];

    console.log("36. Valid Sudoku");
    console.log(isValidSudoku(board1));
    console.log(isValidSudoku(board2));
}

main();
