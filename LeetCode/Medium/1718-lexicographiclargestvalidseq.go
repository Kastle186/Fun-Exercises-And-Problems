// Name: 1718. Construct the Lexicographically Largest Valid Sequence
// Topics: Array, Backtracking

package main

import "fmt"

func main() {
	result1 := constructDistancedSequence(3)
	result2 := constructDistancedSequence(5)

	fmt.Println(result1)
	fmt.Println(result2)
}

func constructDistancedSequence(n int) []int {
	seqSize := (n * 2) - 1
	distancedSeq := make([]int, seqSize)

	// We are making the counts list one element larger than the resulting
	// sequence to compensate for the 0-based indexing.
	counts := make([]int, n + 1)

	for i := range counts {
		counts[i] = 2
	}

	// The problem description specifies that the number 1 only appears once.
	counts[1] = 1

	if findLargestLexSeq(distancedSeq, counts, 0, n) {
		return distancedSeq
	}

	return []int{}
}

func findLargestLexSeq(seq []int, counts []int, idx int, n int) bool {
	// If we've reached the end of the result sequence, then we're done.
	if idx >= len(seq) {
		return true
	}

	// If this spot has already been taken, then move to the next.
	if seq[idx] != 0 {
		return findLargestLexSeq(seq, counts, idx + 1, n)
	}

	// Attempt to place the numbers in descending order to maintain the property
	// of being lexicographically largest.

	for i := n; i >= 1; i-- {
		// If we don't have any more remains of this number, then move on to the
		// next one.
		if counts[i] == 0 {
			continue
		}

		seq[idx] = i
		counts[i]--

		// Number 1 special case. We are doing the nested if here because if the
		// number is 1, but findLargestLexSeq recur doesn't return true, we want
		// to move on, not test the if-elseif-else clauses.

		if i == 1 {
			if findLargestLexSeq(seq, counts, idx + 1, n) {
				return true
			}
		} else if idx + i < len(seq) && seq[idx + i] == 0 {
			// If we can, place the other number of this pair, so we can be done
			// with it.
			seq[idx + i] = i
			counts[i]--

			if findLargestLexSeq(seq, counts, idx + 1, n) {
				return true
			}

			// Here's where Backtracking comes into play. If this placement did
			// not lead to a valid sequence, then we have to undo this progress
			// so that we can try again with another combination.

			seq[idx + i] = 0
			counts[i]++
		}

		// Backtracking since we got here.
		seq[idx] = 0
		counts[i]++
	}

	return false
}
