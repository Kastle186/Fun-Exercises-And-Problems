// Name: 45. Jump Game II
// Topics: Array, Dynamic Programming, Greedy
// Companies:
// - ConsultAdd
// - Zepto
// - MakeMyTrip
// - Expedia
// - PhonePe
// - Oracle
// - Mitsogo
// - Siemens
// - Uber
// - Amazon
// - Nutanix
// - DE Shaw
// - Bloomberg
// - Agoda
// - Google
// - Microsoft
// - Walmart Labs
// - Apple
// - Adobe
// - TikTok
// - Samsung
// - DoorDash
// - Flipkart
// - PayPal
// - Atlassian
// - Meta
// - Goldman Sachs

package main

import "fmt"

func main() {
	fmt.Println("45. Jump Game II")
}

func jump(leaps []int) int {
	jumpCount := 0
	left := 0
	right := 0

	// To solve this problem, we will be using a greedy approach, similarly to
	// how we did in Jump Game I. However, instead of just keeping track of the
	// farthest we can reach, we will go exploring the "segments" (i.e. the range
	// of values we can jump to from each index). This is because we are looking
	// to minimize the amount of jumps, and the longest jump A might not necessarily
	// lead to the longest jump B. So, we need to account for that by using the
	// two pointer approach.

	for right < len(leaps) - 1 {
		segmentFarthest := 0

		// Find the farthest we can reach from the current segment.
		// NOTE: The first segment is composed of only the first element.

		for i := left; i <= right; i++ {
			segmentFarthest := intMax(segmentFarthest, i + leaps[i])
		}

		// Update the pointers to analyze the next segment and add a new jump.

		left = right + 1
		right = segmentFarthest
		jumpCount++
	}

	return jumpCount
}

func intMax(a int, b int) int {
	if a >= b {
		return a
	}
	return b
}
