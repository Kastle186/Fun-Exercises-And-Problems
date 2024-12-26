#!/usr/bin/env ruby

class QueueUsingStacks
  attr_accessor :main_stack, :helper_stack, :current

  # Ruby's Arrays are implemented as general data structures, and thus already have
  # the stack functionality embedded within. For the sake of this exercise's purpose,
  # we will only use push(), pop(), and empty?() to work with the arrays, so that we
  # truly treat them as stacks.

  def initialize
    @main_stack = []
    @helper_stack = []
  end

  # To enqueue an item, we simply push it to the main/in stack. To dequeue and peek
  # at the front of the queue, we check if the helper/out stack is empty. If it is,
  # we pass all the items from the main/in stack to the helper/out stack, and do pop
  # or peek accordingly on it. If it is not empty, then it means we still have items
  # to process before bringing in more, so we simply take the top item from it.

  def enqueue(item)
    @main_stack.push(item)
  end

  def dequeue
    if @helper_stack.empty?
      move_stacks(@main_stack, @helper_stack)
    end

    @helper_stack.pop
  end

  def front(fptr)
    if @helper_stack.empty?
      move_stacks(@main_stack, @helper_stack)
    end

    fptr.write("#{@helper_stack[-1]}\n")
  end

  private

  def move_stacks(from, to)
    until from.empty?
      to.push(from.pop)
    end
  end
end


fptr = File.open(ENV['OUTPUT_PATH'], 'w')
q = gets.strip.to_i
the_queue = QueueUsingStacks.new

q.times do
  query = gets.strip.split(' ').map(&:to_i)

  # The problem's description guarantees that we won't get a bad query index.
  case query[0]
  when 1 then the_queue.enqueue(query[1])
  when 2 then the_queue.dequeue
  when 3 then the_queue.front(fptr)
  end
end

fptr.close
