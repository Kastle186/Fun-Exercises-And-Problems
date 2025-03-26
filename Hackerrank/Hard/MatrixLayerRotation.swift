import Foundation

func printMatrix(matrix: [[Int]]) -> Void
{
    for row in matrix
    {
        print(row.map{ String($0) }.joined(separator: " "))
    }
}

func reverseSegment(array: inout [Int], start: Int, end: Int) -> Void
{
    var startPtr = start
    var endPtr = end

    while startPtr < endPtr
    {
        array.swapAt(startPtr, endPtr)
        startPtr += 1
        endPtr -= 1
    }
}

func getSpirals(matrix: [[Int]]) -> [[Int]]
{
    var spirals1D = [[Int]]()
    var topIndex = 0
    var bottomIndex = matrix.count - 1
    var leftIndex = 0
    var rightIndex = matrix[0].count - 1

    while topIndex < bottomIndex && leftIndex < rightIndex
    {
        var spiral = [Int]()

        for i in topIndex...bottomIndex
        {
            spiral.append(matrix[i][leftIndex])
        }

        // We already added the element in the corner, hence we start at
        // leftIndex + 1 instead.
        for j in leftIndex+1...rightIndex
        {
            spiral.append(matrix[bottomIndex][j])
        }

        for i in stride(from: bottomIndex-1, to: topIndex, by: -1)
        {
            spiral.append(matrix[i][rightIndex])
        }

        // Stride's to limit is not inclusive, hence the previous loop did not
        // process the corner element. Hence, we need to start at rightIndex
        // here, rather than rightIndex - 1.
        for j in stride(from: rightIndex, to: leftIndex, by: -1)
        {
            spiral.append(matrix[topIndex][j])
        }

        spirals1D.append(spiral)

        topIndex += 1
        bottomIndex -= 1
        leftIndex += 1
        rightIndex -= 1
    }

    return spirals1D
}

func refillSpirals(matrix: inout [[Int]], spirals: [[Int]]) -> Void
{
    var offset = 0

    for spiral in spirals
    {
        var spIter = 0
        let topIndex = offset
        let bottomIndex = matrix.count - offset - 1
        let leftIndex = offset
        let rightIndex = matrix[0].count - offset - 1

        for i in topIndex...bottomIndex
        {
            matrix[i][leftIndex] = spiral[spIter]
            spIter += 1
        }

        for j in leftIndex+1...rightIndex
        {
            matrix[bottomIndex][j] = spiral[spIter]
            spIter += 1
        }

        for i in stride(from: bottomIndex-1, to: topIndex, by: -1)
        {
            matrix[i][rightIndex] = spiral[spIter]
            spIter += 1
        }

        for j in stride(from: rightIndex, to: leftIndex, by: -1)
        {
            matrix[topIndex][j] = spiral[spIter]
            spIter += 1
        }

        offset += 1
    }
}

func matrixRotation(matrix: [[Int]], rotations: Int) -> Void
{
    var spirals = getSpirals(matrix: matrix)

    // To solve this problem, we will be implementing a variant of the spiral
    // algorithm for matrixes to extract each layer. This is to make it simpler,
    // as rotating it in 1D is easier than in 2D. Then, we'll refill the matrix
    // with the rotated layers.

    for i in 0..<spirals.count
    {
        // Every count rotations we return to the starting point, so we only
        // need to process the "last" loop of rotations.

        var layer = spirals[i]
        let trueRotations = rotations % layer.count

        // To perform the rotations on each layer spiral, we will be applying
        // the Reversal Algorithm. This consists in, first reversing the entire
        // array. Then, reverse the first trueRotations elements, and then
        // reverse the rest.

        layer.reverse()
        reverseSegment(array: &layer, start: 0, end: trueRotations - 1)
        reverseSegment(array: &layer, start: trueRotations, end: layer.count - 1)

        // In Swift, need to reassign as it always creates copies.
        spirals[i] = layer
    }

    var result = matrix
    refillSpirals(matrix: &result, spirals: spirals)

    // Print the matrix here.
    printMatrix(matrix: result)
}

func Main()
{
    guard let firstMultipleInputTemp = readLine()?.replacingOccurrences(
            of: "\\s+$",
            with: "",
            options: .regularExpression) else { fatalError("Bad input") }

    let firstMultipleInput = firstMultipleInputTemp
                             .split(separator: " ")
                             .map { String($0) }

    guard let m = Int(firstMultipleInput[0])
    else { fatalError("Bad input") }

    guard let n = Int(firstMultipleInput[1])
    else { fatalError("Bad input") }

    guard let r = Int(firstMultipleInput[2])
    else { fatalError("Bad input") }

    var matrix = [[Int]]()

    for _ in 1...m
    {
        guard let matrixRowTemp = readLine()?.replacingOccurrences(
                of: "\\s+$",
                with: "",
                options: .regularExpression) else { fatalError("Bad input") }

        let matrixRow: [Int] = matrixRowTemp.split(separator: " ").map
        {
            if let matrixItem = Int($0)
            {
                return matrixItem
            }
            else { fatalError("Bad input") }
        }

        guard matrixRow.count == n else { fatalError("Bad input") }
        matrix.append(matrixRow)
    }

    guard matrix.count == m else { fatalError("Bad input") }
    matrixRotation(matrix: matrix, rotations: r)
}

Main()
