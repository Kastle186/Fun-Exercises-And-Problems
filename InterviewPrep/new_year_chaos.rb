#!/usr/bin/env ruby

def new_year_chaos(queue)
  # Making our queue 0-based to make it much easier to use indices as the original
  # positions of the people in the queue. An alternative would be to use Julia or Lua,
  # since those languages work with 1-index based arrays.
  queue.map! { |e| e - 1 }

  bribes = 0

  for i in 0...queue.length
    # If any certain person is more than two spots away from their original one,
    # then we know there were more than 2 bribes involved, so we can just print
    # the "too chaotic" message and finish early.

    if queue[i] > i + 2
      puts "Too chaotic"
      return
    end

    # The next part is interesting. For any given person in the queue, the farthest
    # we have to look ahead for potential bribes is one ahead from where that person
    # started. Keyword here being "started", not actual. Because if there was a
    # "larger" person further ahead, then that would mean said person bribed more
    # than two people, and thus would've got caught already in our previous if clause.
    # Then, for each person ahead of the actual spot now that is "larger", a bribe
    # had to happen, so we will be looping to check this and add accordingly.

    start = [0, queue[i] - 1].max

    for j in start...i
      bribes += 1 if queue[j] > queue[i]
    end
  end

  puts bribes
end


def main
  t = gets.strip.to_i

t.times do
  n = gets.strip.to_i
  q = gets.rstrip.split.map(&:to_i)
  new_year_chaos(q)
end

main()
