// Name: 108. Convert Sorted Array to Binary Search Tree
// Topics: Array, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
// Companies:
// - Airbnb
// - Samsung
// - Cisco
// - Yahoo
// - Meta

#include <iostream>
#include <queue>
#include <vector>

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

TreeNode *sorted_array_to_bst(std::vector<int>&);
TreeNode *sorted_array_to_bst(std::vector<int>&, int, int);
void print_tree(TreeNode *);

int main(void)
{
    std::vector<int> nums_1 = { -10, -3, 0, 5, 9 };
    std::vector<int> nums_2 = { 1, 3 };

    TreeNode *tree_1 = sorted_array_to_bst(nums_1);
    TreeNode *tree_2 = sorted_array_to_bst(nums_2);

    print_tree(tree_1);
    print_tree(tree_2);

    delete tree_1;
    delete tree_2;

    return 0;
}

TreeNode *sorted_array_to_bst(std::vector<int>& sorted_nums)
{
    return sorted_array_to_bst(sorted_nums, 0, static_cast<int>(sorted_nums.size() - 1));
}

TreeNode *sorted_array_to_bst(std::vector<int>& sorted_nums, int start, int end)
{
    // To solve this problem, we will be applying a variant of Binary Search.
    // The difference being that instead of searching for an element, we will be
    // traversing the whole array in a binary search fashion to find the "middles"
    // of each segment, and therefore get a perfectly balanced Binary Search Tree
    // at the end as a result.

    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    TreeNode *bst_node = new TreeNode(sorted_nums[mid]);

    bst_node->left = sorted_array_to_bst(sorted_nums, start, mid - 1);
    bst_node->right = sorted_array_to_bst(sorted_nums, mid + 1, end);
    return bst_node;
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
