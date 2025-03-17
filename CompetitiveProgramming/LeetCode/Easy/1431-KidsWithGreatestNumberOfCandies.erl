-module("KidsWithGreatestNumberOfCandies").
-export([main/0]).

kids_with_candies(Candies, ExtraCandies) ->
    %% The premise of this exercise is simple enough. We have to know whether each
    %% kid will have the most candies if we give them the extra ones we have. So,
    %% we just have to compare the sum of each kid's candies with the extra, with
    %% the largest one untouched. The recorded veredicts will be our answer.

    Most = lists:max(Candies),
    lists:map(fun(Kid) -> (Kid + ExtraCandies) >= Most end, Candies).


main() ->
    Candies1 = [2, 3, 5, 1, 3],
    Candies2 = [4, 2, 1, 1, 2],
    Candies3 = [12, 1, 12],

    MostCandies1 = candies:kids_with_candies(Candies1, 3),
    MostCandies2 = candies:kids_with_candies(Candies2, 1),
    MostCandies3 = candies:kids_with_candies(Candies3, 10),

    io:format("~p~n", [MostCandies1]),
    io:format("~p~n", [MostCandies2]),
    io:format("~p~n", [MostCandies3]),

    ok.
