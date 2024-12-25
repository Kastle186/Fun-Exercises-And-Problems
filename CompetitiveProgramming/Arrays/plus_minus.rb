#!/usr/bin/env ruby

def plus_minus(arr)
  pos = 0
  neg = 0
  zero = 0

  arr.each do |elem|
    # We could use else instead of the last when clause, but leaving it as is
    # for extra clarity on what the code intends to do.
    case
    when elem > 0
      pos += 1
    when elem == 0
      zero += 1
    when elem < 0
      neg += 1
    end
  end

  puts pos.fdiv(arr.length).round(6)
  puts neg.fdiv(arr.length).round(6)
  puts zero.fdiv(arr.length).round(6)
end

# Available Test Cases:
#
# Input: [-4, 3, -9, 0, 4, 1]
# Output: 0.500000
#         0.333333
#         0.166667
#
# Input: [1, 2, 3, -1, -2, -3, 0, 0]
# Output: 0.375000
#         0.375000
#         0.250000
