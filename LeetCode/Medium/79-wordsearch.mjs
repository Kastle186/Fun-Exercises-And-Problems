#!/usr/bin/env node

// Name: 79. Word Search
// Topics: Array, String, Backtracking, Depth-First Search, Matrix
// Companies:
// - Karat
// - TikTok
// - Bloomberg
// - Zepto
// - Snap
// - Uber
// - Capital One
// - Epic Systems
// - Visa
// - Oracle
// - Grammarly
// - Microsoft
// - Amazon
// - Paytm
// - Walmart Labs
// - Zoho
// - PayPal
// - Meta
// - Cisco
// - Wix
// - Samsung
// - Apple
// - Roblox
// - Citadel
// - Adobe
// - Atlassian
// - Goldman Sachs
// - tcs

'use strict'

// Possible directions to move our DFS for cleaner code.
const x_mov = [1, 0, -1, 0];
const y_mov = [0, 1, 0, -1];

function isWithinBoundaries(x, y, rows, cols)
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

function searchDFS(board, word, rows, cols, xIndex, yIndex, count)
{
    // We've found the word!
    if (count == word.length)
        return true;

    // Out of bounds or a wrong letter means this path won't take us to the solution.
    if (!isWithinBoundaries(xIndex, yIndex, rows, cols)
        || word[count] != board[xIndex][yIndex])
    {
        return false;
    }

    for (let i = 0; i < 4; i++)
    {
        // Mark this board slot as visited.
        board[xIndex][yIndex] = '#';

        // Recurse to the next slot.
        if (searchDFS(
            board,
            word,
            rows,
            cols,
            xIndex + x_mov[i],
            yIndex + y_mov[i],
            count + 1))
        {
            return true;
        }

        // If we made it here, then that means this path did not lead us to the
        // solution. So, we backtrack by reverting the visited flag to the original
        // unvisited letter.
        board[xIndex][yIndex] = word[count];
    }

    return false;
}

/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
function exist(board, word)
{
    const rows = board.length;
    const cols = board[0].length;

    // If the word is longer than there are characters in the board, then by
    // logical definition it can't be there.

    if (word.length > rows * cols)
        return false;

    // Another thing that can help us define whether the word is in there or not
    // is the occurrences of each letter. If any of them appears more times than
    // there are in the board, then by default it can't be found there.

    let boardMap = new Map();
    let wordMap = new Map();

    for (let i = 0; i < rows; i++)
    {
        for (let j = 0; j < cols; j++)
        {
            const letter = board[i][j];

            if (boardMap.has(letter))
                boardMap[letter]++;
            else
                boardMap.set(letter, 1);
        }
    }

    for (const letter of word)
    {
        if (wordMap.has(letter))
            wordMap[letter]++;
        else
            wordMap.set(letter, 1);
    }

    for (const [letter, count] of wordMap)
    {
        if (!boardMap.has(letter) || boardMap[letter] < wordMap[letter])
            return false;
    }

    // We can also minimize the number of searches if we use the border letter
    // with the least occurrences as our starting point. In other words, if the
    // first letter appears more times in the board than the last letter, then
    // we would need less DFS's to find the answer.

    if (wordMap[word[0]] > boardMap[word[0]])
        word = [...word].reverse().join('');

    // Now that we've simplified the problem as much as we can, we begin our DFS
    // algorithm to find whether the given word appears in the board.

    for (let i = 0; i < rows; i++)
    {
        for (let j = 0; j < cols; j++)
        {
            if (word[0] == board[i][j] && searchDFS(board, word, rows, cols, i, j, 0))
                return true;
        }
    }

    return false;
}

function main()
{
    const board1 = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]];
    const board2 = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]];
    const board3 = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]];

    let found1 = exist(board1, "ABCCED");
    let found2 = exist(board2, "SEE");
    let found3 = exist(board3, "ABCB");

    console.log(found1);
    console.log(found2);
    console.log(found3);
}

main()
