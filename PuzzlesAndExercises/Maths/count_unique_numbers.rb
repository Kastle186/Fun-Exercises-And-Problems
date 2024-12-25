#!/usr/bin/env ruby

TestCase = Struct.new(:limit_digits, :expected)

def main
  test_cases = [
    TestCase.new(3, 739),
    TestCase.new(2, 91),
    TestCase.new(1, 10),
    TestCase.new(0, 1),
  ]

  test_cases.each_with_index do |t, i|
    result = count_unique_numbers(t.limit_digits)

    if result == t.expected
      puts "Test #{i} passed!"
    else
      puts "Test #{i} failed! Expected: #{t.expected}, Actual #{result}"
    end
  end
end


def count_unique_numbers(limit_digits)
  return -1 if limit_digits > 9
  result = 1

  until limit_digits.zero?
    result += count_unique_numbers_n_digits(limit_digits, 9)
    limit_digits -= 1
  end

  result
end


def count_unique_numbers_n_digits(n, result, rem = 9)
  return result if n == 1
  count_unique_numbers_n_digits(n - 1, result * rem, rem - 1)
end


main()
