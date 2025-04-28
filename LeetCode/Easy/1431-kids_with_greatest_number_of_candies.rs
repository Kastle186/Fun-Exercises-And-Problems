// Name: 1431. Kids with the Greatest Number of Candies
// Topics: Array
// Companies: Infosys

fn main()
{
    let candies1: Vec<i32> = vec![2, 3, 5, 1, 3];
    let candies2: Vec<i32> = vec![4, 2, 1, 1, 2];
    let candies3: Vec<i32> = vec![12, 1, 12];

    let most_candies1: Vec<bool> = kids_with_candies(candies1, 3);
    let most_candies2: Vec<bool> = kids_with_candies(candies2, 1);
    let most_candies3: Vec<bool> = kids_with_candies(candies3, 10);

    println!("1431. Kids with the Greatest Number of Candies");
    println!("{:?}", most_candies1);
    println!("{:?}", most_candies2);
    println!("{:?}", most_candies3);
}

fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool>
{
    let mut will_have_most: Vec<bool> = Vec::new();
    let most: i32 = *candies.iter().max().unwrap();

    // The premise of this exercise is simple enough. We have to know whether each
    // kid will have the most candies if we give them the extra ones we have. So,
    // we just have to compare the sum of each kid's candies with the extra, with
    // the largest one untouched. The recorded veredicts will be our answer.

    for this in candies.iter()
    {
        if (this + extra_candies) >= most
        {
            will_have_most.push(true);
        }
        else
        {
            will_have_most.push(false);
        }
    }

    will_have_most
}
