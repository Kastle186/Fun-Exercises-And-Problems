// Name: 98. Validate Binary Search Tree
// Topics: Tree, Depth-First Search, Binary Search Tree, Binary Tree
// Companies:
// - Wix
// - Bloomberg
// - ServiceNow
// - Yandex
// - eBay
// - Nvidia
// - VMware
// - Arista Networks
// - Citadel
// - Paytm
// - Oracle
// - Microsoft
// - Amazon
// - TikTok
// - IBM
// - Salesforce
// - Apple
// - DE Shaw
// - Meta
// - Uber
// - Adobe
// - Yahoo
// - LinkedIn

import Foundation

public class TreeNode
{
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?

    public init() { self.val = 0; self.left = nil; self.right = nil; }
    public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?)
    {
        self.val = val
        self.left = left
        self.right = right
    }
}

func Main()
{
    let bst1 = TreeNode(2)
    bst1.left = TreeNode(1)
    bst1.right = TreeNode(3)

    let bst2 = TreeNode(5)
    bst2.left = TreeNode(1)
    bst2.right = TreeNode(4)
    bst2.right!.left = TreeNode(3)
    bst2.right!.right = TreeNode(6)

    let bst3 = TreeNode(0)
    bst3.left = TreeNode(-1)

    print("98. Validate Binary Search Tree")
    print(isValidBST(root: bst1))
    print(isValidBST(root: bst2))
    print(isValidBST(root: bst3))
}

func isValidBST(root: TreeNode?) -> Bool
{
    var curr: TreeNode? = root
    var prevValue: Int64 = Int64.min

    // For this problem, we have to validate if the given tree is actually a
    // Binary Search Tree (BST). BST's have the unique property that the inorder
    // traversal yields a sorted list. So, we'll go checking the nodes, and return
    // false if at some point the previous value is greater than or equal to the
    // current one. Since it is hard to break suddenly in recursive formats, we
    // will be using the Morris Traversal Algorithm for iterative in-order traversal.

    while let currentNode = curr
    {
        if var prev = currentNode.left
        {
            // First, we must find the immediate predecessor of the current node. So,
            // we have to find the rightmost leaf of its left subtree.

            while let prevRight = prev.right, prevRight !== currentNode
            {
                prev = prevRight
            }

            if prev.right == nil
            {
                // If we haven't passed by here, then set a temporary link from the
                // immediate predecessor to the current node. This will be the guide
                // for the inorder traversal.

                prev.right = currentNode
                curr = currentNode.left
            }
            else
            {
                // If we had passed by here before, then it's time to process the
                // node. If the inorder sorted property is kept, then we reset the
                // link we added previously for the sake of leaving the original
                // tree untouched.

                prev.right = nil
                if currentNode.val <= prevValue { return false }
                prevValue = Int64(currentNode.val)
                curr = currentNode.right
            }
        }
        else
        {
            // If the node has no left subtree, then it's time to process it.
            // Then, use the added link to move to its immediate successor.
            // The links will be reset later when we pass by here again.

            if currentNode.val <= prevValue { return false }
            prevValue = Int64(currentNode.val)
            curr = currentNode.right
        }
    }

    return true
}

Main()
