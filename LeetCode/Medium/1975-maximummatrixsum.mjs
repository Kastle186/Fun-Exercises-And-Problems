#!/usr/bin/env node

// Name: 1975. Maximum Matrix Sum
// Topics: Array, Greedy, Matrix

'use strict';

/**
 * @param {number[][]} matrix
 * @return {number}
 */
function maxMatrixSum(matrix) {
    // According to the problem's description, we always have to flip the elements
    // in pairs. Therefore, we can "bubble" the negative signs away. So, after doing
    // all this, we'll always end up with one or zero minuses, depending on whether
    // there was an even or odd number of them initially. There is one more caveat.
    // If there is at least one zero, we can get rid of the remaining minus sign,
    // if any remained.

    // For our solution, we only need the elements, not the matrix arrangement.
    const flattened = matrix.flat();

    let foundZero = false;
    let totalSum = 0;
    let minuses = 0;

    for (const [index, value] of flattened.entries()) {
        if (value === 0) {
            foundZero = true;
        }

        // If it's negative, record it as such and then make it positive. We're going
        // to need this later.

        if (value < 0) {
            minuses++;
            flattened[index] = Math.abs(value);
        }

        totalSum += flattened[index];
    }

    // If there is at least a zero, we can bubble the negatives to it so we can
    // nullify them. Also, if there was an even number of negatives, we can cancel
    // them out. Therefore, no more processing is needed.

    if (foundZero || minuses % 2 === 0) {
        return totalSum;
    }

    // Otherwise, we have one lingering negative. To maximize our sum, we would
    // bubble it to the smallest absolute value and calculate the sum from there.

    const smallestAbs = Math.min(...flattened);

    // We have to subtract the smallest number twice. One to cancel it, and it would
    // be like it wasn't there in the first place, and two, to restore its original
    // minus form.

    return totalSum - (smallestAbs * 2);
}

function main() {
    const matrix1 = [[1,-1], [-1,1]];
    const matrix2 = [[1,2,3], [-1,-2,-3], [1,2,3]];

    const maxSum1 = maxMatrixSum(matrix1);
    const maxSum2 = maxMatrixSum(matrix2);

    console.log('1975. Maximum Matrix Sum');
    console.log(maxSum1);
    console.log(maxSum2);
}

main();
