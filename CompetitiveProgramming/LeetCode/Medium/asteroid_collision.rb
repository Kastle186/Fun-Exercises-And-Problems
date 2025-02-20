#!/usr/bin/env ruby

# Name: Asteroid Collision
# Topics: Array, Stack, Simulation
# Companies:
# - Myntra
# - SoFi
# - Sprinklr
# - Flipkart
# - Deutsche Bank
# - DoorDash
# - Salesforce
# - EPAM Systems
# - Lyft
# - Zoho
# - ServiceNow
# - Walmart Labs
# - Citadel

def asteroid_collision(asteroids)
  remaining_asteroids = []

  # If we find an asteroid going right (i.e. number > 0), then we add it to
  # the stack. When we find an asteroid going left (i.e. number < 0), then
  # we check the stack. If it's empty or only has negative numbers, then
  # add it. Otherwise, we have to check which is greater, the current one
  # or the one at the top of the stack. The smaller one gets destroyed by
  # the larger one.

  asteroids.each do |ast|
    if ast > 0 or remaining_asteroids.empty? or remaining_asteroids[-1] < 0
      remaining_asteroids << ast
      next
    end

    # The previous if clause guarantees we will get a positive number here.

    last_asteroid = remaining_asteroids[-1]

    # While we have colliding asteroids, we compare their absolute values
    # to see who destroys who. If the one going right wins, we just move
    # on to the next one. If it's a draw, we pop the one going right and
    # move on. If the asteroid going left wins, we have to iterate the
    # stack to see how many it beats and pop them accordingly. If it clears
    # them all, then it earns its spot in the stack for the final result.

    while last_asteroid > 0
      break if last_asteroid > ast.abs

      if last_asteroid == ast.abs
        remaining_asteroids.pop
        break
      end

      remaining_asteroids.pop

      if remaining_asteroids.empty?
        remaining_asteroids << ast
        break
      end

      # If there are only facing left asteroids remaining, then append this one,
      # since it teams up with the others.

      last_asteroid = remaining_asteroids[-1]
      if last_asteroid < 0 then remaining_asteroids << ast end
    end
  end

  remaining_asteroids
end

def main()
  asteroid_field_1 = asteroid_collision([5, 10, -5])
  asteroid_field_2 = asteroid_collision([8, -8])
  asteroid_field_3 = asteroid_collision([10, 2, -5])
  asteroid_field_4 = asteroid_collision([-2, -2, 1, -2])

  p asteroid_field_1
  p asteroid_field_2
  p asteroid_field_3
  p asteroid_field_4
end

main()
