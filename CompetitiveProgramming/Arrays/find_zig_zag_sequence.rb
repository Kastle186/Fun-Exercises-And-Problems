#!/usr/bin/env ruby

def find_zig_zag_sequence(arr, n)
  arr.sort!
  mid = n / 2
  arr[mid], arr[n - 1] = arr[n - 1], arr[mid]

  st = mid + 1
  ed = n - 2

  while st <= ed
    arr[st], arr[ed] = arr[ed], arr[st]
    st += 1
    ed -= 1
  end

  puts arr.join(' ')
end

test_cases = gets.strip.to_i

test_cases.times do
  n = gets.strip.to_i
  arr = gets.strip.split(' ').map(&:to_i)
  find_zig_zag_sequence(arr, n)
end
