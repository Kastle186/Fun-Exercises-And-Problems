#!/usr/bin/env ruby

TestCase = Struct.new(:lst, :expected)

def main
  test_cases = [
    TestCase.new((10..20).to_a, "10 12 13 14 15 16 17 18 19 20"),
    TestCase.new((1..10).to_a, "1 2 3 4 5 6 7 8 9 10"),
  ]

  test_cases.each_with_index do |t, i|
    result = unique_numbers(t.lst)

    if result == t.expected
      puts "Test #{i} passed!"
    else
      puts "Test #{i} failed! Expected: #{t.expected}, Actual #{result}"
    end
  end
end


def unique_numbers(lst)
  uniques = []

  lst.each do |num|
    bitset = 0
    num_proxy = num

    # We are assuming we are guaranteed to only receive positive numbers here.
    # So, we are saying that single digits by definition will always be unique,
    # therefore, we can add them to the result without processing.

    if num < 10
      uniques << num
      next
    end

    # Iterate all digits via modulo 10 operations. We then use some bit masking
    # magic as the hash set where we store the digits we have found so far.

    until num_proxy.zero?
      last_digit = num_proxy % 10
      mask = 1 << last_digit

      unless (bitset & mask).zero?
        break
      end

      bitset |= mask
      num_proxy /= 10
    end

    # If we got to zero, then we finished processing the number, which means it
    # has all unique digits. If we didn't then that means we broke earlier from
    # the loop because of a repeated digit.
    if num_proxy.zero? then uniques << num end
  end

  uniques.join(' ')
end


main()
