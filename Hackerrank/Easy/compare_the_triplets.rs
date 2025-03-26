// Name: Compare the Triplets
// Topics: Algorithms, Warmup

use std::io;
use std::io::BufRead;

fn compare_triplets(alice: &[i32], bob: &[i32]) -> Vec<i32>
{
    let mut scores = vec![0, 0];

    // To solve this exercise, we have to iterate both lists, Alice's and Bob's,
    // at once. We will compare each of the values and update their scores
    // accordingly.

    for (a_score, b_score) in alice.iter().zip(bob.iter())
    {
        if a_score > b_score { scores[0] += 1; }
        else if a_score < b_score { scores[1] += 1; }
    }

    scores
}

fn main()
{
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let a: Vec<i32> = stdin_iterator
                      .next()
                      .unwrap()
                      .unwrap()
                      .trim_end()
                      .split(' ')
                      .map(|s| s.to_string().parse::<i32>().unwrap())
                      .collect();

    let b: Vec<i32> = stdin_iterator
                      .next()
                      .unwrap()
                      .unwrap()
                      .trim_end()
                      .split(' ')
                      .map(|s| s.to_string().parse::<i32>().unwrap())
                      .collect();

    let result = compare_triplets(&a, &b);
    println!("{} {}", result[0], result[1]);
}
