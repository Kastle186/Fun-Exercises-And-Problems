// Name: 2226. Maximum Candies Allocated to K Children
// Topics: Array, Binary Search

package main

import "fmt"

func theMax(array []int) int {
	maxElem := array[0]

	for _, value := range array {
		if value > maxElem {
			maxElem = value
		}
	}

	return maxElem
}

func theSum(array []int) int64 {
	var sum int64 = 0

	for i := range array {
		sum += int64(array[i])
	}

	return sum
}

func main() {
	maxCandies1 := maximumCandies([]int {5, 8, 6}, 3)
	maxCandies2 := maximumCandies([]int {2, 5}, 11)

	fmt.Println(maxCandies1)
	fmt.Println(maxCandies2)
}

func maximumCandies(candies []int, k int64) int {
	var totalCandies int64 = theSum(candies)

	// If we have less candies than children, then at least one would go without,
	// so we don't give to any.

	if totalCandies < k {
		return 0
	}

	// To solve this efficiently, we can use a binary search on the potential
	// numbers of candies. Important to emphasize this, as it can easily get
	// confused with binary search on the piles array. Then, we'll go testing
	// each potential number of candies. The final result of the binary search
	// will be the maximum number of candies we can give each child while also
	// following the constraints of the problem.

	// The biggest pile is a good high boundary for the binary search.
	biggestPile := theMax(candies)
	left := 1
	right := biggestPile

	for left < right {
		mid := int((left + right + 1) / 2)

		if areEnoughCandies(candies, mid, k) {
			left = mid
		} else {
			right = mid - 1
		}
	}

	return left
}

func areEnoughCandies(candiesPiles []int, candiesPerChild int, k int64) bool {
	var childrenWithCandies int64 = 0

	// Check whether we can split the piles of candies using groups of candiesPerChild,
	// making sure everyone gets their own.

	for i := range candiesPiles {
		childrenWithCandies += int64(candiesPiles[i] / candiesPerChild)
	}

	return childrenWithCandies >= k
}
