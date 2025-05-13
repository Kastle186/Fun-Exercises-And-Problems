#!/usr/bin/env python3

# Name: 399. Evaluate Division
#
# Topics:
# - Array
# - String
# - Depth-First Search
# - Breadth-First Search
# - Union Find
# - Graph
# - Shortest Path
#
# Companies:
# - BlackRock
# - Rippling
# - Zeta
# - Citadel
# - Coinbase
# - MakeMyTrip
# - Snowflake
# - Snap
# - Goldman Sachs

from collections import defaultdict, deque
from typing import Union

def find_eq_path(adj: defaultdict[str, list[list[Union[str, float]]]],
                 source: str,
                 target: str) -> float:

    # If we get a value not defined in the given equations, then by definition the
    # result is nonexistent, so we return -1.
    if source not in adj or target not in adj:
        return -1.0

    # To find the path and the multiplication of weights, we will be using a new
    # algorithm: Iterative Deepening Depth-First Search. Why? Because I thought
    # this was a good opportunity to learn it :)

    visited = set([source])
    dfs_stack = [(source, 1.0)]

    # As we can see, IDDFS is quite similar to BFS in how the code looks :)

    while dfs_stack:
        vertex, weight = dfs_stack.pop()

        if vertex == target:
            return weight

        visited.add(vertex)

        for v_neighbor, n_weight in adj[vertex]:
            if not v_neighbor in visited:
                dfs_stack.append((v_neighbor, weight * n_weight))

    return -1.0


def calc_equation(equations: list[list[str]],
                  values: list[float],
                  queries: list[list[str]]) -> list[float]:

    # To solve this problem, we can actually look at the equations as a weighted
    # graph. Each vertex will be an equation component, and each edge's weight
    # will be the result of dividing the vertices said edge connects.

    # First, build our adjacency list.
    adj_lists = defaultdict(list)

    for i, eq in enumerate(equations):
        num, den = eq
        adj_lists[num].append([den, values[i]])
        adj_lists[den].append([num, 1 / values[i]])

    result = []

    # Then "run" the queries. If there is a path from source to target, then the
    # result will be the multiplication of the edge weights needed to be traversed.
    # Otherwise -1.
    #
    # The reasoning for multiplying comes from this mathematical principle:
    #
    # (a / b) * (b / c) -> b's cancel each other out -> a / c

    for q in queries:
        q_res = find_eq_path(adj_lists, q[0], q[1])
        result.append(q_res)

    return result


def main():
    equations_1 = [["a","b"], ["b","c"]]
    values_1 = [2.0, 3.0]
    queries_1 = [["a","c"], ["b","a"], ["a","e"], ["a","a"], ["x","x"]]

    equations_2 = [["a","b"], ["b","c"], ["bc","cd"]]
    values_2 = [1.5, 2.5, 5.0]
    queries_2 = [["a","c"], ["c","b"], ["bc","cd"], ["cd","bc"]]

    equations_3 = [["a","b"]]
    values_3 = [0.5]
    queries_3 = [["a","b"],["b","a"],["a","c"],["x","y"]]

    results_1 = calc_equation(equations_1, values_1, queries_1)
    results_2 = calc_equation(equations_2, values_2, queries_2)
    results_3 = calc_equation(equations_3, values_3, queries_3)

    print("399. Evaluate Division")
    print(results_1)
    print(results_2)
    print(results_3)


if __name__ == '__main__':
    main()
