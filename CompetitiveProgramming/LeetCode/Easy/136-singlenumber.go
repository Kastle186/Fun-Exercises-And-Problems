// Name: 136. Single Number
// Topics: Array, Bit Manipulation
// Companies:
// - Palantir Technologies
// - Airbnb
// - Qualcomm
// - Zoho
// - Google
// - Nvidia
// - Yandex
// - tcs
// - Cisco

package main

import "fmt"

func main() {
	theNum1 := singleNumber([]int {2, 2, 1})
	theNum2 := singleNumber([]int {4, 1, 2, 1, 2})
	theNum3 := singleNumber([]int {1})

	fmt.Println(theNum1)
	fmt.Println(theNum2)
	fmt.Println(theNum3)
}

func singleNumber(nums []int) int {
	// For this problem, we have to find the only number that appears only one time
	// in an array of pairs. However, we have the constraint of having to do it in
	// linear time, and constant extra space (if any). To do this, we will enlist
	// the help of the good ol' trustworthy XOR operator. Any number XOR'd with
	// itself yields 0. If we XOR the entire array, all the pairs will cancel each
	// other out, and leaving the single number in our result variable.

	result := 0

	for i := range nums {
		result ^= nums[i]
	}

	return result
}
