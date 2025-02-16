# Name: Ice Cream Parlor
# Topics: Algorithms, Search

#!/usr/bin/env julia

function main()
    t = parse(Int32, strip(readline(stdin)))

    for t_itr = 1:t
        m = parse(Int32, strip(readline(stdin)))
        n = parse(Int32, strip(readline(stdin)))
        arr = map(x -> parse(Int32, x), Array{String}(split(rstrip(readline(stdin)))))

        result = icecreamParlor(m, arr)
        println(join(result, " "))
    end
end

function icecreamParlor(money, icecosts)
    # To solve this problem, we have to find out the combination of 2 ice creams
    # that matches the the exact amount of money we have. A possible approach
    # would be to compare each ice cream against the rest, and we'll eventually
    # reach the answer.
    #
    # However, we can be more efficient by applying a bit of dynamic programming-like
    # knowledge here. We can keep track of the ice creams we find using a dictionary
    # for quick access, using the cost as the key. Then, for each ice cream we
    # iterate, we check the dictionary for whether we've found a complementary one.
    # If yes, we're done. If not, we add the current ice cream and continue searching.

    icestorage = Dict{Int, Int}()

    for i in eachindex(icecosts)
        icecreamcost = icecosts[i]
        costneeded = money - icecreamcost
        matchingice = get(icestorage, costneeded, -1)

        if matchingice != -1
            return sort([matchingice, i])
        end

        icestorage[icecreamcost] = i
    end

    [-1, -1]
end

main()
