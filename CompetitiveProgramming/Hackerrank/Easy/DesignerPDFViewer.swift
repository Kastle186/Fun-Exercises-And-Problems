import Foundation

func designerPdfViewer(heights: [Int], word: String) -> Int
{
    // First, we need to find the tallest letter in the given word. Then, since
    // the area is by definition a rectangle, we simply multiply that height by
    // the number of letters in the word.

    var tallest: Int = 0
    let asciiToIndexMapper: Int = Int(UnicodeScalar("a").value)

    for letter in word
    {
        let letterIndex: Int = Int(letter.asciiValue!) - asciiToIndexMapper
        if (heights[letterIndex] > tallest)
        {
            tallest = heights[letterIndex];
        }
    }

    return tallest * word.count
}

func Main()
{
    guard let hTemp = readLine()?.replacingOccurrences(
            of: "\\s+$",
            with: "",
            options: .regularExpression) else { fatalError("Bad input") }

    let h: [Int] = hTemp.split(separator: " ").map
    {
        if let hItem = Int($0)
        {
            return hItem
        }
        else { fatalError("Bad input") }
    }

    guard h.count == 26 else { fatalError("Bad input") }
    guard let word = readLine() else { fatalError("Bad input") }
    let result = designerPdfViewer(heights: h, word: word)

    print(result)
}

Main()
