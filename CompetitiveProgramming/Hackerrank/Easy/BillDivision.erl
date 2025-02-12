-module('BillDivision').
-export([main/0]).
-export([bonAppetit/3]).

bonAppetit(Items, AnnaDiscard, AnnaCharged) ->
    % First, we need to get the items we need to calculate the amount that Anna
    % should be paying.

    {Left, [_|Right]} = lists:split(AnnaDiscard, Items),
    AnnaItems = Left ++ Right,
    AnnaExpected = trunc(lists:sum(AnnaItems) / 2),
    Diff = AnnaCharged - AnnaExpected,

    % If there is no difference, then Brian charged Anna correctly. Otherwise,
    % we print the amount that he owes her.
    if
        Diff == 0 ->
            io:format("Bon Appetit~n", []);
        true ->
            io:format("~B~n", [Diff])
    end.


main() ->
    FirstMultipleInput = re:split(re:replace(io:get_line(""),
                                             "\\s+$",
                                             "",
                                             [global, {return, list}]),
                                  "\\s+", [{return, list}]),

    {N, _} = string:to_integer(lists:nth(1, FirstMultipleInput)),
    {K, _} = string:to_integer(lists:nth(2, FirstMultipleInput)),

    BillTemp = re:split(re:replace(io:get_line(""),
                                   "\\s+$",
                                   "",
                                   [global, {return, list}]),
                        "\\s+", [{return, list}]),

    Bill = lists:map(
             fun(X) -> {I, _} = string:to_integer(
                                  re:replace(X,
                                             "(^\\s+)|(\\s+$)",
                                             "",
                                             [global, {return, list}])),
                       I end, BillTemp),

    {B, _} = string:to_integer(re:replace(io:get_line(""),
                                          "(^\\s+)|(\\s+$)",
                                          "", 
                                          [global, {return, list}])),

    bonAppetit(Bill, K, B),

    ok.
