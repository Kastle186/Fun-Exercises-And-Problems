#!/usr/bin/env python3

# Name: 2336. Smallest Number in Infinite Set
# Topics: Hash Table, Design, Heap (Priority Queue), Ordered Set

class SmallestInfiniteSet:

    taken_elems: set[int]
    curr_smallest: int

    def __init__(self):
        self.taken_elems = set()
        self.curr_smallest = 1

    # To implement our infinite set, we will work on the inverse. If the set has
    # all natural numbers, then by definition, those missing are none. Therefore,
    # we can assume that the numbers taken away is a finite set.

    def pop_smallest(self) -> int:
        # To pop the smallest element, we add it instead to the taken elements
        # set. Then, we update the value of our current smallest number.

        elem_removed = self.curr_smallest
        self.taken_elems.add(elem_removed)
        self.curr_smallest += 1

        # This loop is for the cases where we end up with "gaps" in our set.
        # For example, assume numbers 1, 2, and 3 are popped. Then, 1 is added
        # back. The next time pop_smallest() is called, 1 will be returned, but
        # the next smallest one will be 4, instead of 2. This is because 2 was
        # taken and hasn't been returned.

        while self.curr_smallest in self.taken_elems:
            self.curr_smallest += 1

        return elem_removed


    def add_back(self, num: int) -> None:
        # To add back an element, we check whether it is in the taken elements set.
        # If it is, then we remove it from there, symbolizing that it is now part
        # of the infinite set again. Also, if it is smaller than our current
        # smallest one, we update said value for pop_smallest() to consume.

        if num not in self.taken_elems:
            return

        self.taken_elems.discard(num)

        if num < self.curr_smallest:
            self.curr_smallest = num


def main():
    inf_set = SmallestInfiniteSet()
    inf_set.add_back(2)

    print(inf_set.pop_smallest())
    print(inf_set.pop_smallest())
    print(inf_set.pop_smallest())

    inf_set.add_back(1)

    print(inf_set.pop_smallest())
    print(inf_set.pop_smallest())
    print(inf_set.pop_smallest())


if __name__ == '__main__':
    main()
