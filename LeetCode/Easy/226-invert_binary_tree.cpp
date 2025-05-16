// Name: 226. Invert Binary Tree
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Companies: Oracle

#include <iostream>
#include <algorithm>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    ~TreeNode()
    {
        if (left != nullptr)
            delete left;

        if (right != nullptr)
            delete right;
    }
};

TreeNode *invert_tree(TreeNode *);
void print_tree(TreeNode *);

int main(void)
{
    TreeNode *tree_1 = new TreeNode(4);
    tree_1->left = new TreeNode(2);
    tree_1->right = new TreeNode(7);
    tree_1->left->left = new TreeNode(1);
    tree_1->left->right = new TreeNode(3);
    tree_1->right->left = new TreeNode(6);
    tree_1->right->right = new TreeNode(9);

    TreeNode *tree_2 = new TreeNode(2);
    tree_2->left = new TreeNode(1);
    tree_2->right = new TreeNode(3);

    std::cout << "226. Invert Binary Tree\n" << std::endl;

    print_tree(tree_1);
    TreeNode *i_tree_1 = invert_tree(tree_1);
    print_tree(i_tree_1);

    std::cout << std::endl;

    print_tree(tree_2);
    TreeNode *i_tree_2 = invert_tree(tree_2);
    print_tree(i_tree_2);

    delete tree_1;
    delete tree_2;

    return 0;
}

TreeNode *invert_tree(TreeNode *root)
{
    // If there are no nodes, or only one node, then the inversion is the same :)
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return root;

    // We'll be using breadth-first search to solve this problem. Most solutions
    // online are recursive depth-first search, so I thought I'd practice something
    // different, just for my knowledge :)

    std::queue<TreeNode*> bfs_queue;
    bfs_queue.emplace(root);

    while (!bfs_queue.empty())
    {
        TreeNode *next_node = bfs_queue.front();
        bfs_queue.pop();

        // Swap the subtrees. Note we are swapping the pointers. Which include
        // everything, not just these nodes. Emphasizing this because this omission
        // kept me wondering for a while.

        std::swap(next_node->left, next_node->right);

        // Enqueue the children nodes if any.

        if (next_node->left != nullptr)
            bfs_queue.emplace(next_node->left);

        if (next_node->right != nullptr)
            bfs_queue.emplace(next_node->right);
    }

    return root;
}

void print_tree(TreeNode *root)
{
    std::queue<TreeNode*> print_q;
    print_q.emplace(root);

    while (!print_q.empty())
    {
        TreeNode *curr = print_q.front();
        print_q.pop();
        std::cout << "(" << curr->val << ")";

        if (curr->left != nullptr)
            print_q.emplace(curr->left);

        if (curr->right != nullptr)
            print_q.emplace(curr->right);
    }

    std::cout << std::endl;
}
