#!/usr/bin/env node

// Name: 63. Unique Paths II
// Topics: Array, Dynamic Programming, Matrix
// Companies:
// - Cruise
// - Coupang
// - Zepto
// - Agoda
// - Tencent
// - Zomato
// - Pinterest
// - Samsung
// - Bloomberg
// - Atlassian
// - Meta
// - Microsoft
// - Amazon
// - Cisco
// - Adobe
// - Uber
// - Yahoo
// - Apple

'use strict'

function isWithinBoundaries(x, y, rows, cols)
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
function uniquePathsWithObstacles(obstacleGrid)
{
    // If there is an obstacle at the start point, then by definition it is not
    // possible to traverse the grid. Yes, they did add this trolling clown case :)

    if (obstacleGrid[0][0] == 1)
        return 0;

    let rows = obstacleGrid.length;
    let cols = obstacleGrid[0].length;
    let dp = Array.from({ length: rows }, () => Array(cols).fill(undefined));

    // By definition, there is 1 way to get to the starting point, except in
    // the clown case where it's 0.
    dp[0][0] = 1;

    // In this main double loop, we will go filling out our DP matrix as we go
    // calculating the pathways to each space by using the amounts of the previous
    // spaces. Since we can only go right and down, we only have to worry about
    // two previous spaces: i-1 & j-1.

    for (let i = 0; i < rows; i++)
    {
        for (let j = (i == 0 ? 1 : 0); j < cols; j++)
        {
            // If the next tile contains an obstacle, then set DP to 0, since it's
            // not possible to get to any other tile from it. Otherwise, get the
            // number of ways you can reach each of the two immediate previous tiles.
            // For this tile, the answer is the sum of those two predecessors by
            // logical definition.

            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                let prevX = isWithinBoundaries(i - 1, j, rows, cols) ? dp[i - 1][j] : 0;
                let prevY = isWithinBoundaries(i, j - 1, rows, cols) ? dp[i][j - 1] : 0;
                dp[i][j] = prevX + prevY;
            }
        }
    }

    // The last DP tile will contain the answer, as its the goal tile.
    return dp[rows - 1][cols - 1];
}

function main()
{
    const grid1 = [[0,0,0], [0,1,0], [0,0,0]];
    const grid2 = [[0,1], [0,0]];
    const grid3 = [[0,0]];

    let paths1 = uniquePathsWithObstacles(grid1);
    let paths2 = uniquePathsWithObstacles(grid2);
    let paths3 = uniquePathsWithObstacles(grid3);

    console.log("63. Unique Paths II");
    console.log(paths1);
    console.log(paths2);
    console.log(paths3);
}

main();
