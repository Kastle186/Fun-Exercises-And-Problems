#!/usr/bin/env python3

def climbing_leaderboard(ranked: list[int], player: list[int]) -> list[int]:
    # Since equal scores receive the exact same ranking, then we will remove the
    # duplicates for easier processing of the list.

    seen = set()
    ranked_uniq = [r for r in ranked if r not in seen and (seen.add(r) or True)]
    placements = []

    # Since we know the rankings are in natural or descending order, we can apply
    # a small variant of Binary Search to find the index where the next player
    # score would go in the rankings.

    for score in player:
        # If there are no rankings, then no matter what the score is, the next
        # player ranking will be 1st place.
        if not ranked_uniq:
            placements.append(1)
            continue

        score_rank = binary_search_index(ranked_uniq, score, 0, len(ranked_uniq) - 1)
        placements.append(score_rank)

    return placements


def binary_search_index(ranked_scores: list[int],
                        player_score: int,
                        chunk_start: int,
                        chunk_end: int) -> int:
    chunk_size = chunk_end - chunk_start + 1

    # If the chunk size is 1, then the answer is its index if the player score is
    # greater than or equal to the chunk's value, or the next position if it is
    # smaller than it. Well, we use +1 and +2 to compensate for the 0-based indexing
    # of lists in Python.

    if chunk_size == 1:
        return chunk_start + 1 if player_score >= ranked_scores[chunk_start] \
            else chunk_start + 2

    # This thing insists on behaving like an edge-case, so let's treat it
    # separately as such.

    if chunk_size == 2:
        first = ranked_scores[chunk_start]
        second = ranked_scores[chunk_end]

        if player_score >= first:
            return chunk_start + 1

        if first > player_score >= second:
            return chunk_start + 2

        return chunk_start + 3

    # Binary Search Recurse!

    chunk_mid = chunk_start + int(chunk_size / 2)
    test_score = ranked_scores[chunk_mid]

    if player_score == test_score:
        return chunk_mid + 1

    if player_score > test_score:
        return binary_search_index(ranked_scores, player_score, chunk_start, chunk_mid)

    return binary_search_index(ranked_scores, player_score, chunk_mid, chunk_end)


def main():
    ranked_count = int(input().strip())
    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())
    player = list(map(int, input().rstrip().split()))

    result = climbing_leaderboard(ranked, player)
    print('\n'.join(map(str, result)))


if __name__ == '__main__':
    main()
