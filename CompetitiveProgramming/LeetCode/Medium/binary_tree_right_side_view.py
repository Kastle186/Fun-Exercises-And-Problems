#!/usr/bin/env python3

# Name: 199. Binary Tree Right Side View
# Topics: Array, Hash Table, Sorting, Heap/Priority Queue
# Companies:
# - Wix
# - Oracle
# - Akuna Capital
# - Walmart Labs
# - Accolite
# - Flipkart
# - Yandex
# - J.P. Morgan
# - Google


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def get_nodes_by_level(node: TreeNode,
                       views: dict[int, int],
                       level: int) -> None:
    if node is None:
        return

    # Since we are always checking for the right child first, we can by definition
    # assume that if we haven't passed by this level, then this node is the one
    # that will be visible from the right side.

    if not level in views:
        views[level] = node.val

    # Recurse on each child of the node. Always start from the right one, since
    # those are the ones that will be visible if they exist. Then, recurse on
    # the left. The reason we can't exclude the left, is that the left can also
    # potentially have deeper subtrees, which will end up being the visible ones.

    if node.right is not None:
        get_nodes_by_level(node.right, views, level + 1)

    if node.left is not None:
        get_nodes_by_level(node.left, views, level + 1)


def right_side_view(root: TreeNode) -> list[int]:
    nodes = {}
    get_nodes_by_level(root, nodes, 1)
    result = [val for key, val in nodes.items()]
    return result


def main():
    start = TreeNode(1)
    start.left = TreeNode(2)
    start.right = TreeNode(3)
    start.left.right = TreeNode(5)
    start.right.right = TreeNode(4)

    result = right_side_view(start)
    print(result)

    start = None
    start = TreeNode(1)
    start.left = TreeNode(2)
    start.right = TreeNode(3)
    start.left.left = TreeNode(4)
    start.left.left.left = TreeNode(5)

    result = right_side_view(start)
    print(result)

    start = None
    result = right_side_view(start)
    print(result)


if __name__ == '__main__':
    main()
