#!/usr/bin/env ruby

def is_valid(str)
  # For a string to be considered valid in the context of this problem, all
  # characters must appear the same number of times, or at most one can be off
  # by one occurrence.
  #
  # So first, we must get the number of occurrences of each letter in the string.

  letter_occurrences_h = str.chars.uniq.map { |ch| [ch, str.chars.count(ch)] }.to_h
  letter_occurrences = letter_occurrences_h.values
  puts letter_occurrences_h
  p letter_occurrences

  # Next, we do the checks. If all characters appear the same number of times,
  # then we're done. We know it's valid. Or if only one character appears a different
  # number of times, with at most one of difference.

  occurrences_counts = letter_occurrences.map do |occ|
    [occ, letter_occurrences.count(occ)]
  end.to_h

  puts occurrences_counts

  return "YES" if occurrences_counts.size == 1
  return "NO" if occurrences_counts.size > 2

  occurrences = occurrences_counts.keys
  counts = occurrences_counts.values

  # TODO: Explain the second condition of this if clause.

  if (counts.include?(1) and (occurrences[0] - occurrences[1]).abs == 1) or
    (occurrences.include?(1) and occurrences_counts[1] == 1)
    return "YES"
  end

  "NO"
end


def main
  s = gets.chomp
  result = is_valid(s)
  puts result
end

main()
