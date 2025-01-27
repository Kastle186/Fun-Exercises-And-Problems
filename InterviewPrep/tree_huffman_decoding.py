#!/usr/bin/env python3

import queue as Queue

cntr = 0

class Node:
    def __init__(self, freq, data):
        self.freq = freq
        self.data = data
        self.left = None
        self.right = None
        global cntr
        self._count = cntr
        cntr = cntr + 1
        
    def __lt__(self, other):
        if self.freq != other.freq:
            return self.freq < other.freq
        return self._count < other._count


# Builds the tree and returns root

def huffman_hidden():
    q = Queue.PriorityQueue()
    
    for key in freq:
        q.put((freq[key], key, Node(freq[key], key)))
    
    while q.qsize() != 1:
        a = q.get()
        b = q.get()
        obj = Node(a[0] + b[0], '\0')

        obj.left = a[2]
        obj.right = b[2]
        q.put((obj.freq, obj.data, obj))
        
    root = q.get()
    root = root[2] # Contains root object
    return root


def dfs_hidden(obj, already):
    if (obj is None):
        return
    elif (obj.data != '\0'):
        code_hidden[obj.data] = already

    dfs_hidden(obj.right, already + "1")
    dfs_hidden(obj.left, already + "0")


def is_leaf(node):
    return node.left is None and node.right is None


def decode_huff(root, s):
    answer = ""
    i = 0

    while i < len(s):
        searcher = root
        next_ch = s[i]

        # while not is_leaf(searcher):
        while True:
            if next_ch == '0':
                searcher = searcher.left

            if next_ch == '1':
                searcher = searcher.right

            if is_leaf(searcher):
                break

            i += 1
            next_ch = s[i]

        answer += searcher.data
        i += 1

    print(answer)


ip = input()
freq = {} # Maps each character to its frequency
cntr = 0

for ch in ip:
    if (freq.get(ch) is None):
        freq[ch] = 1
    else:
        freq[ch] += 1

root = huffman_hidden() # Contains root of huffman tree
code_hidden = {} # Contains code for each object

dfs_hidden(root, "")

if len(code_hidden) == 1: # If there is only one character in the i/p
    for key in code_hidden:
        code_hidden[key] = "0"

to_be_decoded = ""

for ch in ip:
    to_be_decoded += code_hidden[ch]

decode_huff(root, to_be_decoded)
