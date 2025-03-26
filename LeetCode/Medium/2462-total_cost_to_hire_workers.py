#!/usr/bin/env python3

# Name: 2462. Total Cost to Hire K Workers
# Topics: Array, Two Pointers, Heap (Priority Queue), Simulation
# Companies:
# - MathWorks
# - Zomato

import heapq

def total_cost(costs: list[int], to_hire: int, candidates_per_group: int) -> int:
    # Since we want to hire the cheapest ones of each group, we will be using
    # min heaps to "sort" them as they arrive.

    group1_heap = []
    group2_heap = []
    left_index = 0

    for left_index in range(left_index, candidates_per_group):
        heapq.heappush(group1_heap, costs[left_index])

    # We can't hire a candidate more than once, so we build the second heap this
    # way to also handle the cases where there would be overlaps, e.g. we have a
    # total of 4 candidates and each group is composed of 3.

    right_index = len(costs) - 1

    for right_index in range(right_index, right_index - candidates_per_group, -1):
        if right_index <= left_index:
            break

        heapq.heappush(group2_heap, costs[right_index])
        right_index -= 1

    # Adding one here because we subtracted one at the end of the while loop, and
    # the end of the for loop didn't.
    right_index += 1

    # Pick the cheapest candidates as they arrive (i.e. we will go adding the
    # remaining ones to their respective heaps as we progress.)

    hire_cost = 0
    total_hires = 0

    # While we have candidates in both groups, we can follow the normal procedure.

    while len(group1_heap) > 0 and len(group2_heap) > 0:
        if total_hires == to_hire:
            break

        cand1 = group1_heap[0]
        cand2 = group2_heap[0]

        # Compare the candidates respective costs here. For each one hired, add
        # a new arrival while there are still remaining in the pool.

        if cand1 <= cand2:
            hire_cost += cand1
            heapq.heappop(group1_heap)

            if (left_index + 1) < right_index:
                left_index += 1
                heapq.heappush(group1_heap, costs[left_index])

        else:
            hire_cost += cand2
            heapq.heappop(group2_heap)

            if (right_index - 1) > left_index:
                right_index -= 1
                heapq.heappush(group2_heap, costs[right_index])

        total_hires += 1

    # If we exhausted one of the groups, and we still don't have enough hires,
    # then just hire from the remaining group until we have the needed hires.
    # The problem's description guarantees there will always be enough candidates.

    while total_hires < to_hire and len(group1_heap) > 0:
        hire_cost += heapq.heappop(group1_heap)
        total_hires += 1

    while total_hires < to_hire and len(group2_heap) > 0:
        hire_cost += heapq.heappop(group2_heap)
        total_hires += 1

    return hire_cost


def main():
    candidates_1 = [17, 12, 10, 2, 7, 2, 11, 20, 8]
    candidates_2 = [1, 2, 4, 1]
    candidates_3 = [3, 2, 7, 7, 1, 2]

    result_1 = total_cost(candidates_1, 3, 4)
    result_2 = total_cost(candidates_2, 3, 3)
    result_3 = total_cost(candidates_3, 2, 2)

    print(result_1)
    print(result_2)
    print(result_3)


if __name__ == '__main__':
    main()
