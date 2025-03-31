// Name: 56. Merge Intervals
// Topics: Array, Sorting
// Companies:
// - Netflix
// - Grammarly
// - Yelp
// - Docusign
// - X
// - Wix
// - Zepto
// - Disney
// - TikTok
// - Oracle
// - Meta
// - Bloomberg
// - Salesforce
// - ServiceNow
// - ConsultAdd
// - IXL
// - Roblox
// - Morgan Stanley
// - Zoho
// - Yandex
// - Ozon
// - Microsoft
// - Cruise
// - J.P. Morgan
// - Amazon
// - LinkedIn
// - Siemens
// - Apple
// - Walmart Labs
// - Yahoo
// - Nvidia
// - Tencent
// - Atlassian
// - Expedia
// - eBay
// - Cisco
// - MakeMyTrip
// - Instacart
// - Uber
// - ByteDance
// - Palantir Technologies
// - Two Sigma
// - PhonePe
// - Samsung
// - Dropbox
// - Adobe
// - PayPal
// - Snap
// - Agoda
// - Turing
// - Accenture
// - Snowflake
// - Infosys
// - Media.net
// - Goldman Sachs
// - IBM
// - DE Shaw
// - Databricks
// - Airbnb
// - Citadel
// - Pinterest

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	ranges1 := [][]int { {1, 3}, {2, 6}, {8, 10}, {15, 18} }
	ranges2 := [][]int { {1, 4}, {4, 5} }

	collapsed1 := merge(ranges1)
	collapsed2 := merge(ranges2)

	fmt.Println(collapsed1)
	fmt.Println(collapsed2)
}

func merge(intervals [][]int) [][]int {
	// First, we sort our array of intervals by the starting point.
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	// The next step is to iterate through each of the intervals. The core logic
	// is that if the starting point of the next interval is less than or equal
	// to the ending point of the current interval, then those ought to be merged.

	var merged [][]int
	var nextMergeStart int = intervals[0][0]
	var nextMergeEnd int = intervals[0][1]
	var numIntervals = len(intervals)

	for i := 1; i < numIntervals; i++ {
		current := intervals[i]

		if current[0] <= nextMergeEnd {
			// If the next interval starts before the previous one ends, then we have
			// a merge to do here. So, we set nextMergeEnd to the highest of the
			// interval ends.
			nextMergeEnd = mathMaxInt(nextMergeEnd, current[1])
		} else {
			// Otherwise, append the last formed interval, and begin the process
			// once again starting at the next element.
			merged = append(merged, []int { nextMergeStart, nextMergeEnd })

			if i < numIntervals {
				nextMergeStart = intervals[i][0]
				nextMergeEnd = intervals[i][1]
			}
		}
	}

	// Add the final interval.
	merged = append(merged, []int { nextMergeStart, nextMergeEnd })

	return merged
}

func mathMaxInt(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func mergedebug(intervals [][]int) [][]int {
	// First, we sort our array of intervals by the starting point.
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	// The next step is to iterate through each of the intervals. The core logic
	// is that if the starting point of the next interval is less than or equal
	// to the ending point of the current interval, then those ought to be merged.

	var merged [][]int
	var nextMergeStart int = intervals[0][0]
	var nextMergeEnd int = intervals[0][1]
	var numIntervals = len(intervals)

	for i := 1; i < numIntervals; i++ {
		fmt.Printf("\nNext Merge Start: %d\n", nextMergeStart)
		fmt.Printf("Next Merge End: %d\n", nextMergeEnd)
		fmt.Printf("Num Intervals: %d\n", numIntervals)

		current := intervals[i]
		fmt.Printf("\ni = %d; current = [%d, %d]\n", i, current[0], current[1])

		if current[0] <= nextMergeEnd {
			fmt.Println("Next range starts before the current max.")
			nextMergeEnd = mathMaxInt(nextMergeEnd, current[1])
			fmt.Printf("New Next Merge End: %d\n", nextMergeEnd)
		} else {
			fmt.Println("Next range starts after the current max.")
			merged = append(merged, []int { nextMergeStart, nextMergeEnd })
			fmt.Println(merged)

			if i < numIntervals {
				fmt.Println("Updating index and next merge...")
				nextMergeStart = intervals[i][0]
				nextMergeEnd = intervals[i][1]
				fmt.Printf("New Next Merge Start: %d\n", nextMergeStart)
				fmt.Printf("New Next Merge End: %d\n", nextMergeEnd)
				fmt.Printf("i = %d\n", i)
			}
		}
	}

	if len(merged) == 0 || merged[len(merged) - 1][1] != nextMergeEnd {
		merged = append(merged, []int { nextMergeStart, nextMergeEnd })
	}

	return merged
}
