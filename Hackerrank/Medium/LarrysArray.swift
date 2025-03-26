import Foundation

func larrysArray(array: [Int]) -> String
{
    // To know if we can sort any given array by rotating slices of 3-elements,
    // we can use the number of inversions existing in the original one. If it
    // has an even number of inversions, then it's sortable by the triplets
    // rotations means. Otherwise, it isn't.
    //
    // This is because a triplet contains two pairs. If we have an odd number
    // of inversions, then we will always end up with at least an element out
    // of place.

    var inversions: Int = 0

    for i in 0..<array.count - 1
    {
        for j in i..<array.count
        {
            if (array[i] > array[j])
            {
                inversions += 1
            }
        }
    }

    return inversions % 2 == 0 ? "YES" : "NO"
}

func Main()
{
    guard let t = Int((readLine()?.trimmingCharacters(
                         in: .whitespacesAndNewlines))!)
    else { fatalError("Bad input") }

    for _ in 1...t
    {
        guard let n = Int((readLine()?.trimmingCharacters(
                             in: .whitespacesAndNewlines))!)
        else { fatalError("Bad input") }

        guard let ATemp = readLine()?.replacingOccurrences(
                of: "\\s+$",
                with: "",
                options: .regularExpression) else { fatalError("Bad input") }

        let A: [Int] = ATemp.split(separator: " ").map
        {
            if let AItem = Int($0)
            {
                return AItem
            }
            else { fatalError("Bad input") }
        }

        guard A.count == n else { fatalError("Bad input") }
        let result = larrysArray(array: A)
        print(result)
    }
}

Main()
