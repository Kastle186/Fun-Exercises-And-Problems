#!/usr/bin/env ruby

def super_digit(n, k)
  # Since the first iteration can be a ridiculously big number, we process it
  # directly as a string. We don't have to do this for the entire n * k sequence,
  # since we can more efficiently multiply the result of the sum of one n by k
  # directly as a number.
  reasonable = n.chars.map { |c| c.to_i }.reduce(:+)

  # Now, we can call our main helper with a decently-sized number.
  super_digit_helper(reasonable * k)
end

def super_digit_helper(num)
  return num if num < 10
  next_reduced = 0

  while num > 0
    next_reduced += num % 10
    num /= 10
  end

  super_digit_helper(next_reduced)
end
