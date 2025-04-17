// Name: 230. Kth Smallest Element in a BST
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Companies:
// Expedia
// Agoda
// Oracle
// Google

#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kth_smallest(TreeNode *, int);

int main(void)
{
    TreeNode *tree_1 = new TreeNode(3);
    tree_1->left = new TreeNode(1);
    tree_1->right = new TreeNode(4);
    tree_1->left->right = new TreeNode(2);

    TreeNode *tree_2 = new TreeNode(5);
    tree_2->left = new TreeNode(3);
    tree_2->right = new TreeNode(6);
    tree_2->left->left = new TreeNode(2);
    tree_2->left->right = new TreeNode(4);
    tree_2->left->left->left = new TreeNode(1);

    int little_1 = kth_smallest(tree_1, 1);
    int little_2 = kth_smallest(tree_2, 3);

    std::cout << little_1 << std::endl;
    std::cout << little_2 << std::endl;

    delete tree_1->left->right;
    delete tree_1->right;
    delete tree_1->left;
    delete tree_1;

    delete tree_2->left->left->left;
    delete tree_2->left->left;
    delete tree_2->left->right;
    delete tree_2->left;
    delete tree_2->right;
    delete tree_2;

    return 0;
}

int kth_smallest(TreeNode *root, int k)
{
    TreeNode *tree_ptr = root;
    std::stack<TreeNode *> dfs_stack;

    // To find the kth-smallest element in a BST, we'll do an in-order traversal,
    // and finish when we find said element. So, since we need to be able to break
    // at will, we will do this iteratively with a stack, rather than recursively.

    while (tree_ptr != nullptr || !dfs_stack.empty())
    {
        // If we haven't got to the end of this branch, then add this node to the
        // stack and continue traversing the left subtree.

        if (tree_ptr)
        {
            dfs_stack.push(tree_ptr);
            tree_ptr = tree_ptr->left;
            continue;
        }

        // In-Order Traversal Processing: If we've reached a leaf, then it's time
        // to count. Pop this node from the stack and decrement the number of
        // remaining k-smallest elements. If we don't have any more remaining, then
        // return this result. Otherwise, now traverse the right subtree and continue
        // searching and counting.

        tree_ptr = dfs_stack.top();
        dfs_stack.pop();

        if (--k == 0)
            return tree_ptr->val;

        tree_ptr = tree_ptr->right;
    }

    // If we get here, then that means there were less nodes than k, so therefore,
    // we couldn't find a kth-smallest one.
    return -1;
}
