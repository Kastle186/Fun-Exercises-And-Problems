using System;
using System.Collections.Generic;
using System.Linq;

class QueueUsingStacks<T>
{
    private Stack<T> _inStack;
    private Stack<T> _outStack;

    public QueueUsingStacks()
    {
        _inStack = new Stack<T>();
        _outStack = new Stack<T>();
    }

    public void Enqueue(T item)
    {
        _inStack.Push(item);
    }

    public T Dequeue()
    {
        if (_outStack.Count == 0)
            MoveStacks(_inStack, _outStack);

        return _outStack.Pop();
    }

    public void Front()
    {
        if (_outStack.Count == 0)
            MoveStacks(_inStack, _outStack);

        Console.WriteLine(_outStack.Peek());
    }

    private void MoveStacks(Stack<T> from, Stack<T> to)
    {
        while (from.Count > 0)
            to.Push(from.Pop());
    }
}

class Solution
{
    static int Main(string[] args)
    {
        int queries = Convert.ToInt32(Console.ReadLine().Trim());
        QueueUsingStacks<int> theQueue = new QueueUsingStacks<int>();

        for (int i = 0; i < queries; i++)
        {
            List<int> query = Console.ReadLine()
                                     .Trim()
                                     .Split(' ')
                                     .Select(val => Convert.ToInt32(val))
                                     .ToList();

            // The problem's description guarantees we won't get a bad query index,
            // and that all operations are valid.

            switch (query[0])
            {
                case 1:
                    theQueue.Enqueue(query[1]);
                    break;

                case 2:
                    theQueue.Dequeue();
                    break;

                case 3:
                    theQueue.Front();
                    break;
            }
        }
        return 0;
    }
}
