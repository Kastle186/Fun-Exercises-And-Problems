// Name: 138. Copy List with Random Pointer
// Topics:
// Companies:
// - Docusign
// - Intel
// - Wix
// - Nvidia
// - Walmart Labs
// - Morgan Stanley
// - ZScaler
// - Oracle
// - eBay
// - PhonePe
// - Flipkart
// - Google

import java.util.HashMap;
import java.util.Map;

class Node
{
    int val;
    Node next;
    Node random;

    public Node(int val)
    {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution
{
    public static void main(String[] args)
    {
        int[][] randoms1 = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
        int[][] randoms2 = {{1, 1}, {2, 1}};
        int[][] randoms3 = {{3, -1}, {3, 0}, {3, -1}};

        Node rList1 = arrayToRandomList(randoms1);
        Node rList2 = arrayToRandomList(randoms2);
        Node rList3 = arrayToRandomList(randoms3);

        System.out.print("138. Copy List with Random Pointer\n\n");
        printRandomList(rList1);
        printRandomList(rList2);
        printRandomList(rList3);
    }

    private static Node copyRandomList(Node head)
    {
        // To effectuate a deep copy of a random pointer linked list, we can either
        // use a hash map, or do it in place. For this exercise, we will opt to do
        // it in place, using the original list as leverage to adjust the random
        // pointers of the deep-copied list. At the end, we will end up with two
        // completely separate identical lists, and will return the deep copied one,
        // effectually using up O(1) space and leaving the original untouched.

        if (head == null)
            return null;

        // First pass: Deep create the nodes' copies and interweave them with
        // the original list.

        Node ptr = head;

        while (ptr != null)
        {
            Node deepCpyNode = new Node(ptr.val);
            deepCpyNode.next = ptr.next;
            ptr.next = deepCpyNode;
            ptr = deepCpyNode.next;
        }

        // Second pass: Use the interweaved list to add the deep-copied random
        // pointers to the deep-copied counterpart nodes.

        ptr = head;

        while (ptr != null)
        {
            if (ptr.random != null)
                ptr.next.random = ptr.random.next;

            ptr = ptr.next.next;
        }


        // Third pass: Detach the deep created list from the original one, so we
        // can return it while leaving the original one untouched.

        ptr = head;
        Node deepCpyHead = ptr.next;

        while (ptr != null)
        {
            Node deepCpyNode = ptr.next;
            ptr.next = deepCpyNode.next;

            if (deepCpyNode.next != null)
                deepCpyNode.next = deepCpyNode.next.next;

            ptr = ptr.next;
        }

        return deepCpyHead;
    }

    private static Node arrayToRandomList(int[][] arr)
    {
        Node randomListHead = new Node(arr[0][0]);
        Node rListPtr = randomListHead;
        Map<Integer, Node> rListMap = new HashMap<>();
        rListMap.put(0, rListPtr);

        // Construct the linked list's nodes.

        for (int i = 1; i < arr.length; i++)
        {
            Node newNode = new Node(arr[i][0]);
            rListPtr.next = newNode;
            rListPtr = newNode;
            rListMap.put(i, newNode);
        }

        // Add the random pointers.

        rListPtr = randomListHead;
        for (int j = 0; j < arr.length; j++)
        {
            int randPtrIndex = arr[j][1];

            if (randPtrIndex != -1)
                rListPtr.random = rListMap.get(randPtrIndex);

            rListPtr = rListPtr.next;
        }

        return randomListHead;
    }

    private static void printRandomList(Node list)
    {
        Node listPtr = list;

        while (listPtr != null)
        {
            System.out.printf("Value: %d%n", listPtr.val);
            System.out.printf("Random: %d%n",
                              listPtr.random != null ? listPtr.random.val : -1);
            listPtr = listPtr.next;
        }

        System.out.print("\n");
    }
}
