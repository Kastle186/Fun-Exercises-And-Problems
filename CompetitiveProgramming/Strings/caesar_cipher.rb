#!/usr/bin/env ruby

def caesar_cipher(str, rots)
  # First, we build a dictionary with the mappings of the normal alphabet with
  # the resulting one after the rotations.

  orig_small = ('a'..'z').to_a
  orig_caps = ('A'..'Z').to_a

  encrypt_small = ('a'..'z').map do |l|
    letter_index = (l.ord - 'a'.ord + rots) % 26
    (letter_index + 'a'.ord).chr
  end

  encrypt_caps = ('A'..'Z').map do |l|
    letter_index = (l.ord - 'A'.ord + rots) % 26
    (letter_index + 'A'.ord).chr
  end

  mapping = Hash[(orig_small + orig_caps).zip(encrypt_small + encrypt_caps)]

  # And then, we can use our dictionary to translate the message letter by letter,
  # and like that transform it into its encrypted version. For non-letter symbols,
  # we leave them as they are.

  0.upto(str.length - 1) do |i|
    char = str[i]
    if mapping.has_key?(char) then str[i] = mapping[char] end
  end

  str
end

# Available Test Cases:
#
# Input: middle-Outz, 2
# Output: okffng-Qwvb
#
# Input: Always-Look-on-the-Bright-Side-of-Life, 5
# Output: Fqbfdx-Qttp-ts-ymj-Gwnlmy-Xnij-tk-Qnkj
