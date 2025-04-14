// Name: 112. Path Sum
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Companies:
// - TikTok
// - Uber
// - Yahoo

package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func main() {
	tree1 := &TreeNode{ Val: 5 }
	tree1.Left = &TreeNode{ Val: 4 }
	tree1.Right = &TreeNode{ Val: 8 }
	tree1.Left.Left = &TreeNode{ Val: 11 }
	tree1.Right.Left = &TreeNode{ Val: 13 }
	tree1.Right.Right = &TreeNode{ Val: 4 }
	tree1.Left.Left.Left = &TreeNode{ Val: 7 }
	tree1.Left.Left.Right = &TreeNode{ Val: 2 }
	tree1.Right.Right.Right = &TreeNode{ Val: 1 }

	tree2 := &TreeNode{ Val: 1 }
	tree2.Left = &TreeNode{ Val: 2 }
	tree2.Right = &TreeNode{ Val: 3 }

	var tree3 *TreeNode = nil

	fmt.Println(hasPathSum(tree1, 22))
	fmt.Println(hasPathSum(tree2, 5))
	fmt.Println(hasPathSum(tree3, 0))
}

func hasPathSum(root *TreeNode, targetSum int) bool {
	// If there's no remaining tree, then there can't be a path to a sum.
	if root == nil {
		return false
	}

	// Pre-order traversal value update.
	targetSum -= root.Val

	// If this is a leaf node, then check whether the exercise's constraint
	// is satisfied.
	if root.Left == nil && root.Right == nil {
		return targetSum == 0
	}

	// Otherwise, recurse to continue traversing down the branches.
	return hasPathSum(root.Left, targetSum) || hasPathSum(root.Right, targetSum)
}
