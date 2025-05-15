// Name: 55. Jump Game I
// Topics: Array, Dynamic Programming, Greedy
// Companies:
// - Verily
// - MakeMyTrip
// - ZScaler
// - Amazon
// - Oracle
// - Infosys
// - Tencent
// - Media.net
// - Microsoft
// - Bloomberg
// - Morgan Stanley
// - Salesforce
// - Wipro
// - Meesho
// - tcs
// - Yahoo
// - Adobe
// - Google
// - DoorDash
// - TikTok
// - Flipkart
// - Apple
// - Snowflake
// - Uber
// - Goldman Sachs
// - Meta
// - PayPal
// - Zoho
// - Cisco

package main

import "fmt"

func main() {
	nums1 := []int { 2, 3, 1, 1, 4 }
	nums2 := []int { 3, 2, 1, 0, 4 }

	fmt.Println("55. Jump Game I")
	fmt.Println(canJump(nums1))
	fmt.Println(canJump(nums2))
}

func canJump(leaps []int) bool {
	farthest := 0
	numLeaps := len(leaps)

	// To solve this problem, we will be applying a greedy approach. We have two
	// options at each step: To jump or not to jump. So, we will go iterating each
	// leap, and keeping track of the farthest we can reach so far, so we are able
	// to decide whether to use that jump or not and move to the next.

	for i := 0; i < numLeaps; i++ {
		// If we can't jump at least to this step, then by definition it is not
		// possible to reach the end.
		if farthest < i {
			return false
		}

		// We got to the end, so we're done!
		if farthest == numLeaps - 1 {
			break
		}

		farthest = intMax(farthest, i + leaps[i])
	}

	return true
}

func intMax(a int, b int) int {
	if a >= b {
		return a
	}
	return b
}
