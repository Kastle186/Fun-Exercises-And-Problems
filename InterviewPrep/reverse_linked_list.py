#!/usr/bin/env python3

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node


def main():
    tests = int(input())

    for _ in range(tests):
        llist_count = int(input())
        llist = SinglyLinkedList()

        for _ in range(llist_count):
            llist_item = int(input())
            llist.insert_node(llist_item)

        llist1 = reverse(llist)
        print_singly_linked_list(llist1, ' ')
        print('\n')


def reverse(llist):
    if not llist.head or not llist.head.next:
        return llist

    prev_n = None
    curr_n = llist.head
    next_n = curr_n.next

    llist.tail = curr_n

    while True:
        curr_n.next = prev_n

        if not next_n:
            break

        prev_n = curr_n
        curr_n = next_n
        next_n = curr_n.next

    llist.head = curr_n
    return llist


def print_singly_linked_list(llist, sep):
    node = llist.head

    while node:
        print(str(node.data), end='')
        node = node.next

        if node:
            print(sep, end='')


if __name__ == '__main__':
    main()
