#!/usr/bin/env ruby

def main
  q = gets.strip.to_i

  q.times do
    first_multiple_input = gets.rstrip.split

    n = first_multiple_input[0].to_i
    k = first_multiple_input[1].to_i

    arrA = gets.rstrip.split.map(&:to_i)
    arrB = gets.rstrip.split.map(&:to_i)

    result = two_arrays(k, arrA, arrB)
    puts result
  end
end

def two_arrays(k, arrA, arrB)
  # If we want to have both arrays in such a way that adding their respective
  # elements on a given position, e.g. a[1] + b[1], then the best we can look
  # for is some sort of middle sum. To achieve this, we'll sort one array in
  # ascending order, and one in descending. Then, test each of the sums to
  # determine whether achieving this property is possible or not.

  arrA.sort!
  arrB.sort!.reverse!

  arrA.zip(arrB).each do |elem_a, elem_b|
    return "NO" if elem_a + elem_b < k
  end

  "YES"
end

main()
