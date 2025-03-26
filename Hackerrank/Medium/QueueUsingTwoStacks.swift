import Foundation

class QueueUsingStacks<T>
{
    private var enter: [T] = []
    private var exit: [T] = []

    public func enqueue(item: T) -> Void
    {
        enter.append(item)
    }

    @discardableResult public func dequeue() -> T
    {
        if (exit.isEmpty)
        {
            moveStacks()
        }

        return exit.removeLast()
    }

    public func printFront() -> Void
    {
        if (exit.isEmpty)
        {
            moveStacks()
        }

        print(exit.last!)
    }

    private func moveStacks() -> Void
    {
        while (!enter.isEmpty)
        {
            exit.append(enter.removeLast())
        }
    }
}

func Main()
{
    guard let queries = Int((readLine()?.trimmingCharacters(
                               in: .whitespacesAndNewlines))!)
    else { fatalError("Bad input") }

    let theQueue = QueueUsingStacks<Int>()

    for _ in 1...queries
    {
        let query = readLine()?.trimmingCharacters(in: .whitespaces)
                               .split(separator: " ")
                               .compactMap { Int($0) }

        // The problem's description guarantees we won't get a bad query index,
        // and that all operations are valid.

        switch query![0]
        {
        case 1:
            theQueue.enqueue(item: query![1])

        case 2:
            theQueue.dequeue()

        case 3:
            theQueue.printFront()

        default:
            print("We should not run this clause.")
        }
    }
}

Main()
