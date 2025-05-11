// Name: 149. Max Points on a Line
// Topics:
// Companies:
// - Twitter/X
// - Akuna Capital
// - LinkedIn
// - Sprinklr
// - Cisco
// - Nvidia
// - Oracle

package main

import (
	"fmt"
	"math"
)

func main() {
	plane1 := [][]int { {1,1}, {2,2}, {3,3} }
	plane2 := [][]int { {1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4} }

	maxLine1 := maxPoints(plane1)
	maxLine2 := maxPoints(plane2)

	fmt.Println("149. Max Points on a Line")
	fmt.Println(maxLine1)
	fmt.Println(maxLine2)
}

func maxPoints(points [][]int) int {
	numPoints := len(points)

	// If we only have one point, then the line is that point :)
	if numPoints == 1 {
		return 1
	}

	biggestSlope := 1

	// We'll iterate each pair of points and calculate the slope between them.
	// Our goal is to find the slope with the most points in it.

	for i := range numPoints {
		p1 := points[i]
		ptCounts := make(map[float64]int)

		for j := i + 1; j < numPoints; j++ {
			// The slope is calculated by subtracting the ys and dividing that
			// result by the subtraction of the xs.
			p2 := points[j]
			dx := float64(p2[0] - p1[0])
			dy := float64(p2[1] - p1[1])

			// For vertical lines (i.e. dx = 0 and therefore can't divide dy),
			// we set the slope as the max value. Just as a representation of this
			// specific case.

			var slope float64
			if dx == 0 {
				slope = math.MaxFloat64
			} else {
				slope = dy / dx
			}

			// Update and keep track of the slope with the most points.
			ptCounts[slope] += 1
			biggestSlope = maxInt(biggestSlope, ptCounts[slope] + 1)
		}
	}

	return biggestSlope
}

func maxInt(a int, b int) int {
	if a >= b {
		return a
	} else {
		return b
	}
}
