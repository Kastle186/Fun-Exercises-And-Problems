# Name: Insert a Node at a Specific Position in a Linked List
# Topics: Data Structures, Linked Lists

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
    llist_count = int(input())
    llist = SinglyLinkedList()

    for _ in range(llist_count):
        llist_item = int(input())
        llist.insert_node(llist_item)

    data = int(input())
    position = int(input())
    llist_head = insert_node_at_position(llist.head, data, position)

    print_singly_linked_list(llist_head, ' ')
    print('\n')


def insert_node_at_position(llist_head, data, position):
    llist_ptr = llist_head
    index = 0
    new_node = SinglyLinkedListNode(data)

    if position == 0:
        new_node.next = llist_head
        return new_node

    while index < position - 1:
        llist_ptr = llist_ptr.next
        index += 1

    next_n = llist_ptr.next
    new_node.next = next_n
    llist_ptr.next = new_node

    return llist_head


def print_singly_linked_list(llist, sep):
    node = llist

    while node:
        print(str(node.data), end='')
        node = node.next

        if node:
            print(sep, end='')


if __name__ == '__main__':
    main()
