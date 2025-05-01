// Name: 137. Single Number II
// Topics: Array, Bit Manipulation
// Companies: Accenture

fn main()
{
    let nums_1: Vec<i32> = vec![2, 2, 3, 2];
    let nums_2: Vec<i32> = vec![0, 1, 0, 1, 0, 1, 99];
    let nums_3: Vec<i32> = vec![7, 7, 7, 9, 9, 4, 5, 9, 4, 4];

    let single_three_1: i32 = single_number(nums_1);
    let single_three_2: i32 = single_number(nums_2);
    let single_three_3: i32 = single_number(nums_3);

    println!("137. Single Number II");
    println!("{}", single_three_1);
    println!("{}", single_three_2);
    println!("{}", single_three_3);
}

fn single_number(nums: Vec<i32>) -> i32
{
    // This thing is basically magic. We need to count how many times each bit
    // in a 32-bit integer appears in the vector modulo 3. At the end, the number
    // only appearing once will appear in the variable keeping track of the bits
    // we've found once modulo three. These two, ones and twos, basically pass
    // each other the numbers. It's hard to explain. Here's the crazy magic with
    // a partial example.
    //
    // arr = [2, 2, 2, 3, 3, 4, 5, 3, 4, 4]
    // a = 0 // Records first encounter of the number
    // b = 0 // Records second encounter of the number
    // // Third encounter of the number clears it.
    //
    // a = (a ^ arr[i]) & ~b
    // b = (b ^ arr[i]) & ~a
    //
    // i = 0
    // arr[i] = 2
    // a = (0 ^ 2) & ~0 = (000 ^ 010) & ~000 = 010 & 111 = 010 = 2
    // b = (0 ^ 2) & ~2 = (000 ^ 010) & ~010 = 010 & 101 = 000 = 0
    //
    // i = 1
    // arr[i] = 2
    // a = (2 ^ 2) & ~0 = (010 ^ 010) & ~000 = 000 & 111 = 000 = 0
    // b = (0 ^ 2) & ~0 = (000 ^ 010) & ~000 = 010 & 111 = 010 = 2
    //
    // i = 2
    // arr[i] = 2
    // a = (0 ^ 2) & ~2 = (000 ^ 010) & ~010 = 010 & 101 = 000 = 0
    // b = (2 ^ 2) & ~0 = (000 ^ 000) & ~000 = 000 & 111 = 000 = 0


    let mut ones: i32 = 0;
    let mut twos: i32 = 0;

    for num in nums.iter()
    {
        ones = (ones ^ num) & !twos;
        twos = (twos ^ num) & !ones;
    }

    ones
}
