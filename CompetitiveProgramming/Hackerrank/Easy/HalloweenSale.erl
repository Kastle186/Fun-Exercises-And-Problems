-module('HalloweenSale').
-export([main/0]).
-export([howManyGames/4]).

howManyGames(FirstPrice, Discount, LowestPrice, Budget) ->
    howManyGames(FirstPrice, Discount, LowestPrice, Budget, 0).

howManyGames(_, _, _, Budget, Games) when Budget < 0 -> 
    Games;

howManyGames(FirstPrice, Discount, LowestPrice, Budget, Games) ->
    NextPrice = max(FirstPrice - Games * Discount, LowestPrice),
    RemBudget = Budget - NextPrice,
    if
        RemBudget < 0 -> 
            Games;
        true -> 
            howManyGames(FirstPrice, Discount, LowestPrice, RemBudget, Games + 1)
    end.


main() ->
    FirstMultipleInput = re:split(re:replace(io:get_line(""),
                                             "\\s+$",
                                             "",
                                             [global, {return, list}]),
                                  "\\s+", [{return, list}]),

    {P, _} = string:to_integer(lists:nth(1, FirstMultipleInput)),
    {D, _} = string:to_integer(lists:nth(2, FirstMultipleInput)),
    {M, _} = string:to_integer(lists:nth(3, FirstMultipleInput)),
    {S, _} = string:to_integer(lists:nth(4, FirstMultipleInput)),

    Answer = howManyGames(P, D, M, S),
    io:fwrite("~w~n", [Answer]),

    ok.
