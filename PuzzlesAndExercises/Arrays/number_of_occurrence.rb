#!/usr/bin/env ruby

TestCase = Struct.new(:arr, :target, :expected)

def main
  test_cases = [
    TestCase.new([1, 1, 2, 2, 2, 2, 3], 2, 4),
    TestCase.new([1, 1, 2, 2, 2, 2, 3], 4, 0),
    TestCase.new([8, 9, 10, 12, 12, 12], 12, 3)
  ]

  test_cases.each_with_index do |t, i|
    result = count_freq(t.arr, t.target)

    if result == t.expected
      puts "Test #{i} passed!"
    else
      puts "Test #{i} failed! Expected: #{t.expected}, Actual #{result}"
    end
  end
end

def count_freq(arr, target)
  # No need to even start looking if either our array is empty, or the target
  # would be out of bounds.
  return 0 if arr.empty? or arr[0] > target or arr[-1] < target

  # We could always use Ruby's count() built-in method, but that would defeat the
  # purpose of this exercise :D

  n = find_target_index(arr, target)

  # If the index is -1, then that means our target was not found in the given array.
  if n == -1 then return 0 end

  iter = n - 1
  result = 1

  # We've found our target value in the array. Now, we only need to count it and
  # how many repeats are before, and how many after it.

  while arr[iter] == target
    result += 1
    iter -= 1
  end

  iter = n + 1

  while arr[iter] == target
    result += 1
    iter += 1
  end

  result
end

def find_target_index(arr, target)
  return -1 if arr.empty? or (arr.length == 1 and arr[0] != target)

  middle = arr.length / 2

  # Binary Search Time! If the middle is smaller than our target, then our target
  # is potentially in the second half of the array. Otherwise, it is in the first
  # half. So, we recurse accordingly.

  if arr[middle] < target
    return find_target_index(arr[(middle + 1)..], target)
  elsif arr[middle] > target
    return find_target_index(arr[...(middle + 1)], target)
  end

  middle
end

main()
