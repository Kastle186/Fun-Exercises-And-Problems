#!/usr/bin/env ruby

class Node
  attr_accessor :data, :next

  def initialize(data)
    @data = data
  end
end


class LinkedList
  attr_accessor :head, :tail

  def insert_node(data)
    new_node = Node.new(data)

    if @head.nil?
      @head = new_node
    else
      @tail.next = new_node
    end

    @tail = new_node
  end

  def print
    iter = @head
    list_str = ""

    until iter.nil?
      list_str << "#{iter.data} "
      iter = iter.next
    end

    puts list_str.strip
  end
end


def merge_lists(lst1, lst2)
  # If any of the lists is null, then the merged one is equal to the non-null one.
  return lst2 if lst1.nil?
  return lst1 if lst2.nil?

  iter1 = lst1.head
  iter2 = lst2.head

  merged_list = nil
  merged_ptr = nil
  skip_ptr = nil

  # First, we need to define which of the lists will be the vessel for the merged
  # one. So, for that, we check which one has the smaller value. If equal, then
  # we'll choose list 1.

  if iter1.data <= iter2.data
    merged_list = lst1
    iter1 = iter1.next
  else
    merged_list = lst2
    iter2 = iter2.next
  end

  # This little pointer is the one in charge of moving the lists' nodes links.
  merged_ptr = merged_list.head

  # While we still have elements left, we go checking which one is less or equal
  # than the other, and set the "next" pointers accordingly, so that both lists
  # are connected/merged.

  until iter1.nil? or iter2.nil?
    if iter1.data <= iter2.data
      merged_ptr.next = iter1
      iter1 = iter1.next
    else
      merged_ptr.next = iter2
      iter2 = iter2.next
    end
    merged_ptr = merged_ptr.next
  end

  # Once we reach the end of one list, we have at least 1 element left in the
  # other one. So, we just iterate through those remaining items and concatenate
  # them together.

  until iter1.nil?
    merged_ptr.next = iter1
    iter1 = iter1.next
    merged_ptr = merged_ptr.next
  end

  until iter2.nil?
    merged_ptr.next = iter2
    iter2 = iter2.next
    merged_ptr = merged_ptr.next
  end

  merged_list
end

t = gets.strip.to_i

t.times do
  n1 = gets.strip.to_i
  lst1 = LinkedList.new

  n1.times do
    m = gets.strip.to_i
    lst1.insert_node(m)
  end

  n2 = gets.strip.to_i
  lst2 = LinkedList.new

  n2.times do
    m = gets.strip.to_i
    lst2.insert_node(m)
  end

  lst3 = merge_lists(lst1, lst2)
  lst3.print
end
