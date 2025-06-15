#!/usr/bin/env node

function count()
{
    let sum = 0;

    return function()
    {
        sum += 1;
        return sum;
    }
}

let first = count();
let second = count();

console.log(first());
console.log(first());
console.log(second());