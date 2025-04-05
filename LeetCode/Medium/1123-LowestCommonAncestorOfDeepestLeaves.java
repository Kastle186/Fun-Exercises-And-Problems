// Name: 1123. Lowest Common Ancestor of Deepest Leaves
// Topics: Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree

import java.util.AbstractMap.SimpleEntry;

class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;

    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution
{
    public static void main(String[] args)
    {
        TreeNode tree1 = new TreeNode(3);
        tree1.left = new TreeNode(5);
        tree1.right = new TreeNode(1);
        tree1.left.left = new TreeNode(6);
        tree1.left.right = new TreeNode(2);
        tree1.left.right.left = new TreeNode(7);
        tree1.left.right.right = new TreeNode(4);
        tree1.right.left = new TreeNode(0);
        tree1.right.right = new TreeNode(8);

        TreeNode tree2 = new TreeNode(1);

        TreeNode tree3 = new TreeNode(0);
        tree3.left = new TreeNode(1);
        tree3.right = new TreeNode(3);
        tree3.left.right = new TreeNode(2);

        TreeNode lca1 = lcaDeepestLeaves(tree1);
        TreeNode lca2 = lcaDeepestLeaves(tree2);
        TreeNode lca3 = lcaDeepestLeaves(tree3);

        System.out.println(lca1.val);
        System.out.println(lca2.val);
        System.out.println(lca3.val);
    }

    private static TreeNode lcaDeepestLeaves(TreeNode root)
    {
        if (root.left == null && root.right == null)
            return root;

        return dfs(root).getKey();
    }

    private static SimpleEntry<TreeNode, Integer> dfs(TreeNode node)
    {
        // The definition of the common ancestor of two leaf nodes is that one node
        // whose subtrees containing said leaf nodes are the same depth. So, to find
        // that, we use post-order traversal, and count the depth of each node we
        // encounter from the bottom up.

        if (node == null)
            return new SimpleEntry<TreeNode, Integer>(null, 0);

        // Recurse on each subtree to find its own subtrees and the common ancestors.

        SimpleEntry<TreeNode, Integer> leftSubtree = dfs(node.left);
        SimpleEntry<TreeNode, Integer> rightSubtree = dfs(node.right);

        int leftDepth = leftSubtree.getValue();
        int rightDepth = rightSubtree.getValue();

        // - Whichever subtree is deeper will have the lowest common ancestor of
        //   the deepest leaf nodes.
        // - If both are the same depth, then this node is the lowest common
        //   ancestor of said leaves.

        return leftDepth > rightDepth
            ? new SimpleEntry<TreeNode, Integer>(leftSubtree.getKey(), leftDepth + 1)
            : rightDepth > leftDepth
            ? new SimpleEntry<TreeNode, Integer>(rightSubtree.getKey(), rightDepth + 1)
            : new SimpleEntry<TreeNode, Integer>(node, leftDepth + 1);
    }
}
