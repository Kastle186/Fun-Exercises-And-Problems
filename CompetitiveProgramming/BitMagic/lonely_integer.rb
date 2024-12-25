#!/usr/bin/env ruby

# We could solve this problem by using a HashMap to store the occurrences of
# each number and whichever key has '1' as its value is the lonely integer.
#
# We could also sort the array, and when we find a number different from both,
# the previous and the next one, then that's our lonely integer.
#
# Or we could use some bit magic. We are guaranteed that every number occurs
# twice sans one (the lonely integer). If we XOR any number with itself, then
# it becomes zero. So, if we XOR everything, all the repeated numbers will cancel
# themselves out, leaving us with the answer we seek: The Lonely Integer.

def lonely_integer(arr)
  loner = 0
  arr.each { |num| loner ^= num }
  loner
end

# Available Test Cases:
#
# Input: [1, 1, 2]
# Output: 2
#
# Input: [0, 0, 1, 2, 1]
# Output: 2
