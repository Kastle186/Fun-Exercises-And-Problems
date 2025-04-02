// Name: 100. Same Tree
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Companies:
// - Bloomberg
// - Amazon
// - Flipkart
// - Google
// - Adobe
// - tcs
// - Microsoft
// - Yahoo
// - Meta
// - LinkedIn
// - Uber
// - Apple

class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;

    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class SameTree
{
    public static void main(String[] args)
    {
        // Exercise 1

        TreeNode p1 = new TreeNode(1);
        p1.left = new TreeNode(2);
        p1.right = new TreeNode(3);

        TreeNode q1 = new TreeNode(1);
        q1.left = new TreeNode(2);
        q1.right = new TreeNode(3);

        System.out.println(isSameTree(p1, q1) ? "true" : "false");

        // Exercise 2

        TreeNode p2 = new TreeNode(1);
        p2.left = new TreeNode(2);
        p2.right = null;

        TreeNode q2 = new TreeNode(1);
        q2.left = null;
        q2.right = new TreeNode(2);

        System.out.println(isSameTree(p2, q2) ? "true" : "false");

        // Exercise 2

        TreeNode p3 = new TreeNode(1);
        p3.left = new TreeNode(2);
        p3.right = new TreeNode(1);

        TreeNode q3 = new TreeNode(1);
        q3.left = new TreeNode(1);
        q3.right = new TreeNode(2);

        System.out.println(isSameTree(p3, q3) ? "true" : "false");
    }

    public static boolean isSameTree(TreeNode p, TreeNode q)
    {
        // To know whether p and q are the same tree, we simply need to check
        // each of their nodes. If at some point the strructure or value differs,
        // then we can define them as different.

        boolean pNull = p == null;
        boolean qNull = q == null;

        // If both are null, then so far the structure is the same, so they are
        // potentially the same tree.

        if (pNull && qNull)
            return true;

        // Likewise, if only one is null, or their values differ, then the structure
        // is already different, and therefore we can conclude they are different trees.

        if ((pNull ^ qNull) || (p.val != q.val))
            return false;

        // Else, continue going down the trees, comparing their values to find the
        // solution we are looking for.

        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
