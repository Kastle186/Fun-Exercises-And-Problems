// Name: 2390. Removing Stars From a String
// Topics: String, Stack, Simulation

import Foundation

func Main()
{
    let s1: String = "leet**cod*e"
    let s2: String = "erase*****"

    let noStars1: String = removeStars(s: s1)
    let noStars2: String = removeStars(s: s2)

    print(noStars1)
    print(noStars2)
}

func removeStars(s: String) -> String
{
    // In this problem, we have to delete the closest non-star character to the
    // left of each star. To do this, we would use a stack, as the topmost element
    // at any given time, would be the closest left element. But then, we also have
    // to return the remainder as a string, so we'll be taking advantage of Swift's
    // Array class that can behave as a stack at the same time.

    var remainingLetters = Array<Character>()

    for char in s
    {
        // Found a star, pop the closest-left element.
        if char == "*"
        {
            remainingLetters.removeLast()
        }

        // Otherwise, push it into our stacklist.
        else
        {
            remainingLetters.append(char)
        }
    }

    return remainingLetters.map{"\($0)"}.joined()
}
