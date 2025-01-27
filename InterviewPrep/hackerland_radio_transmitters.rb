#!/usr/bin/env ruby

def main
  first_multiple_input = gets.rstrip.split
  k = first_multiple_input[1].to_i
  x = gets.rstrip.split.map(&:to_i)

  result = hackerland_radio_transmitters(x, k)
  puts result
end


def hackerland_radio_transmitters(houses, t_range)
  # Firstly, we sort our array and eliminate duplicates. The houses are always
  # in order, and having more than one house in the same spot doesn't change the
  # amount of transmitters, as if one has access, then all have it because of
  # being in the same location.

  houses.sort!.uniq!
  return 1 if houses.length == 1

  index = 0
  transmitters = 0

  while index < houses.length
    next_half = houses[index] + t_range

    while index < houses.length and houses[index] <= next_half
      index += 1
    end

    index -= 1
    transmitters += 1
    next_half = houses[index] + t_range

    while index < houses.length and houses[index] <= next_half
      index += 1
    end
  end

  transmitters
end


main()
