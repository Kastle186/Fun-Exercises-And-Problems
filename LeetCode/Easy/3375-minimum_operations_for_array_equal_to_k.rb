#!/usr/bin/env ruby

# Name: 3375. Minimum Operations to Make Array Values Equal to K
# Topics: Array, Hash Table

def min_operations(nums, k)
  # To make all numbers equal to k according to the rules specified in the problem,
  # first, we have to ensure that said k value is less than or equal to the smallest
  # number in the array. Otherwise, it's not possible to do.
  smallest = nums.min
  return -1 if k > smallest

  # Once we know it's possible, since each operation will change all equal numbers
  # to another one, then by definition we can infer that the number of operations
  # we need is the number of unique elements greater than k.
  nums.uniq.count { |num| num > k }
end


def main
  ops_1 = min_operations([5, 2, 5, 4, 5], 2)
  ops_2 = min_operations([2, 1, 2], 2)
  ops_3 = min_operations([9, 7, 5, 3], 1)

  puts ops_1
  puts ops_2
  puts ops_3
end


main()
