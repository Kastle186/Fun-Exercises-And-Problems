// Name: 637. Average of Levels in Binary Tree
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree
// Companies: Qualcomm

import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

class TreeNode
{
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class BinTreeLevelsAverage
{
    public static void main(String[] args)
    {
        TreeNode tree1 = new TreeNode(3);
        tree1.left = new TreeNode(9);
        tree1.right = new TreeNode(20);
        tree1.right.left = new TreeNode(15);
        tree1.right.right = new TreeNode(7);

        TreeNode tree2 = new TreeNode(3);
        tree2.left = new TreeNode(9);
        tree2.right = new TreeNode(20);
        tree2.left.left = new TreeNode(15);
        tree2.left.right = new TreeNode(7);

        List<Double> lvAvg1 = averageOfLevels(tree1);
        List<Double> lvAvg2 = averageOfLevels(tree2);

        System.out.print("[");
        for (double avg : lvAvg1)
            System.out.print(" " + avg);
        System.out.print(" ]\n");

        System.out.print("[");
        for (double avg : lvAvg2)
            System.out.print(" " + avg);
        System.out.print(" ]\n");
    }

    private static List<Double> averageOfLevels(TreeNode root)
    {
        List<Double> lvAverages = new ArrayList<>();
        LinkedList<TreeNode> bfsQueue = new LinkedList<>();
        bfsQueue.offer(root);

        // To calculate the sum and average of all nodes' values by level, we will
        // be using a flavor of Breadth-First Search. First, we begin by processing
        // the root node.

        while (!bfsQueue.isEmpty())
        {
            double lvSum = 0.0d;
            int lvNodes = bfsQueue.size();

            // The key lies in this for loop. By definition, we will start by having
            // all the nodes in a given level in the queue. Then, we make sure to
            // process them all with this for loop, to ensure that when we go to the
            // next iteration of the while loop, the queue will include only the
            // children nodes of the current level's ones'.

            for (int i = 0; i < lvNodes; i++)
            {
                TreeNode nextNode = bfsQueue.poll();
                lvSum += (double) nextNode.val;

                if (nextNode.left != null)
                    bfsQueue.offer(nextNode.left);

                if (nextNode.right != null)
                    bfsQueue.offer(nextNode.right);
            }

            lvAverages.add(lvSum / (double) lvNodes);
        }

        return lvAverages;
    }
}
