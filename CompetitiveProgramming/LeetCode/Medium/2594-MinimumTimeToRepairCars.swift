// Name: 2594. Minimum Time to Repair Cars
// Topics: Array, Binary Search

import Foundation

func Main()
{
    let cars1: Int = repairCars(ranks: [4, 2, 3, 1], cars: 10)
    let cars2: Int = repairCars(ranks: [5, 1, 8], cars: 6)

    print(cars1)
    print(cars2)
}

func repairCars(ranks: [Int], cars: Int) -> Int
{
    // To solve this problem, we will be checking how many cars can be repaired per
    // amount of time, and the smallest of these amounts that satisfies the target
    // number of cars, will be our answer.
    //
    // We know that:
    //
    //    time = rank * cars^2
    //
    // Therefore, we can define the following as our binary search function:
    //
    //    cars = sqrt(time / rank)
    //

    var minTime = 0
    var maxTime = ranks.max()! * (cars * cars)

    while minTime < maxTime
    {
        let nextTime = Int((minTime + maxTime) / 2)

        if canRepairTargetCars(time: nextTime, ranks: ranks, targetCars: cars)
        {
            maxTime = nextTime
        }
        else
        {
            minTime = nextTime + 1
        }
    }

    return minTime
}

func canRepairTargetCars(time: Int, ranks: [Int], targetCars: Int) -> Bool
{
    var repairedCars = 0

    // Check how many cars could each mechanic repair within the given time
    // constraint, and add them up. If we can repair at least the target number
    // of cars, then this is a time candidate for the final answer.

    for r in ranks
    {
        repairedCars += Int(Double(time / r).squareRoot())
    }

    return repairedCars >= targetCars
}

Main()
