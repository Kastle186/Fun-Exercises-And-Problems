// Name: Letter Tile Possibilities
// Topics: Hash Table, String, Backtracking, Counting

import Foundation

func countSequences(letterCount: inout [Character: Int]) -> Int
{
    var numSequences = 0

    for (ch, cnt) in letterCount
    {
        // If we have no more tiles of this letter, then move on to the next.
        if cnt <= 0
        {
            continue
        }

        // Add a new combination with this new letter.
        numSequences += 1
        letterCount[ch]! -= 1

        // Recurse to find the next combination.
        numSequences += countSequences(letterCount: &letterCount)

        // Reset the usage of this letter, as by combinations, we also need to
        // count inverted versions as different.
        letterCount[ch]! += 1
    }

    return numSequences
}

func numTilePossibilities(tiles: String) -> Int
{
    // First, we must know how many times each letter 
    var letterOccurrences: [Character: Int] = [:]

    for ch in tiles
    {
        if let _ = letterOccurrences[ch]
        {
            letterOccurrences[ch]! += 1
        }
        else
        {
            letterOccurrences[ch] = 1
        }
    }

    // Then, we use this information to count the possible combinations.
    return countSequences(letterCount: &letterOccurrences)
}

func Main()
{
    let tiles1: Int = numTilePossibilities(tiles: "AAB")
    let tiles2: Int = numTilePossibilities(tiles: "AAABBC")
    let tiles3: Int = numTilePossibilities(tiles: "V")

    print(tiles1)
    print(tiles2)
    print(tiles3)
}

Main()
