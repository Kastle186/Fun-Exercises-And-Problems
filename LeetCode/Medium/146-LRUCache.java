// Name: 146. LRU Cache
// Topics: Hash Table, Linked List, Design, Doubly-Linked List
// Companies:
// - Walmart Labs
// - Oracle
// - Disney
// - ByteDance
// - Zenefits
// - MongoDB
// - TikTok
// - Snap
// - Coupang
// - Samsung
// - ServiceNow
// - Twitter/X
// - Palantir Technologies
// - eBay
// - Nvidia
// - thoughtspot
// - SoFi
// - Splunk
// - Cruise
// - Tesla
// - Netflix
// - VMware
// - Intuit
// - Zepto
// - Citadel
// - Palo Alto Networks
// - Myntra
// - Salesforce
// - Qualcomm
// - Docusign
// - PayPal
// - Cisco
// - Nutanix
// - Tencent
// - Visa
// - Wells Fargo
// - Grab
// - Yandex
// - Verkada
// - Morgan Stanley
// - MakeMyTrip
// - Instacart
// - Intel
// - Rubrik
// - LinkedIn
// - Arista Networks
// - Swiggy
// - Goldman Sachs
// - Twilio
// - Paytm
// - SAP
// - DE Shaw
// - Media.net
// - Expedia
// - Sprinklr
// - Snowflake
// - PhonePe
// - IBM
// - DoorDash

import java.util.HashMap;

class LRUCache
{
    private class LRUNode
    {
        int key;
        int value;
        LRUNode next;
        LRUNode prev;

        public LRUNode(int keyArg, int valueArg)
        {
            key = keyArg;
            value = valueArg;
        }
    }

    private int cacheCapacity;
    private HashMap<Integer, LRUNode> mappingTable;
    private LRUNode listHead;
    private LRUNode listTail;

    public LRUCache(int capacity)
    {
        cacheCapacity = capacity;
        mappingTable = new HashMap<>(capacity);
        listHead = null;
        listTail = null;
    }

    public int get(int key)
    {
        if (!mappingTable.containsKey(key))
            return -1;

        LRUNode resultNode = mappingTable.get(key);
        moveToHead(resultNode);
        return resultNode.value;
    }

    public void put(int key, int value)
    {
        if (mappingTable.containsKey(key))
        {
            LRUNode existingNode = mappingTable.get(key);
            existingNode.value = value;
            moveToHead(existingNode);
        }
        else
        {
            LRUNode newNode = new LRUNode(key, value);
            addToHead(newNode);
            mappingTable.put(key, newNode);

            if (mappingTable.size() > cacheCapacity)
                removeFromTail();
        }
    }

    private void addToHead(LRUNode node)
    {
        node.prev = null;
        node.next = listHead;

        // Update head if exists.

        if (listHead != null)
            listHead.prev = node;

        listHead = node;

        // Make the new node also the tail if it's the only one.

        if (listTail == null)
            listTail = node;
    }

    private void moveToHead(LRUNode node)
    {
        if (node == listHead)
            return ;

        removeNode(node);
        addToHead(node);
    }

    private void removeNode(LRUNode node)
    {
        // Handle removing a potential head node.

        if (node.prev != null)
            node.prev.next = node.next;
        else
            listHead = node.next;

        // Handle removing a potential tail node.

        if (node.next != null)
            node.next.prev = node.prev;
        else
            listTail = node.prev;
    }

    private void removeFromTail()
    {
        if (listTail == null)
            return ;

        mappingTable.remove(listTail.key);
        removeNode(listTail);
    }
}

class Solution
{
    public static void main(String[] args)
    {
        LRUCache lruCache = new LRUCache(2);
        System.out.println("146. LRU Cache");

        lruCache.put(1, 1);
        lruCache.put(2, 2);
        System.out.println(lruCache.get(1));

        lruCache.put(3, 3);
        System.out.println(lruCache.get(2));

        lruCache.put(4, 4);
        System.out.println(lruCache.get(1));
        System.out.println(lruCache.get(3));
        System.out.println(lruCache.get(4));
    }
}

// import java.util.LinkedList;

// public class Example {
//     public static void main(String[] args) {
//         LinkedList<Integer> list = new LinkedList<>();

//         list.addFirst(1);  // Add to head
//         list.addLast(2);   // Add to tail

//         System.out.println("Head: " + list.getFirst()); // O(1)
//         System.out.println("Tail: " + list.getLast());  // O(1)
//     }
// }

// import java.util.HashMap;

// public class HashMapExample {
//     public static void main(String[] args) {
//         // Create a HashMap
//         HashMap<String, Integer> map = new HashMap<>();

//         // Put key-value pairs into the map
//         map.put("Alice", 25);
//         map.put("Bob", 30);
//         map.put("Charlie", 22);

//         // Get a value by key
//         int age = map.get("Alice");
//         System.out.println("Alice's age: " + age);

//         // Check if a key exists
//         if (map.containsKey("Bob")) {
//             System.out.println("Bob is in the map.");
//         }

//         // Remove a key-value pair
//         map.remove("Charlie");

//         // Iterate through entries
//         for (String name : map.keySet()) {
//             System.out.println(name + " is " + map.get(name) + " years old.");
//         }
//     }
// }
