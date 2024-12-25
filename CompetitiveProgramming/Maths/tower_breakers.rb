#!/usr/bin/env ruby

# This is one of those problems that sounds some complicated divisors stuff,
# but in the end, it's a reading comprehension joke.
#
# - If the tower heights (m) is 1, then P2 wins by default because P1 can't make
#   a move.
#
# - If the number of towers (n) is even, and the height (m) is greater than 1,
#   then P2 wins because they can copy the moves of P1 on a different tower,
#   and since there are an even number of towers, P2 will always be the one to
#   make the last move.
#
# - If the number of towers (n) is odd, and the height (m) is greater than 1,
#   then P1 wins because they can reduce the first tower to height 1, and then
#   we apply the n-even case by definition.

def tower_breakers(n, m)
  if m == 1 or (n % 2).zero? then 2 else 1 end
end
