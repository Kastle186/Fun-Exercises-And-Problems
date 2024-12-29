-module('PlusMinus').
-export([main/0]).

%
% Complete the 'plusMinus' function below.
%
% The function accepts INTEGER_ARRAY arr as parameter.
%

plusMinus(Arr) ->
    % First, we need to count how many we have of each, positive, negative,
    % and zeroes.
    Zeroes = length([X || X <- Arr, X == 0]),
    Pos = length([X || X <- Arr, X > 0]),
    Neg = length([X || X <- Arr, X < 0]),
    Len = length([X || X <- Arr]),

    % Then, print the division of each by the total number of elements to get
    % the ratio.
    io:format("~.6f~n", [Pos / Len]),
    io:format("~.6f~n", [Neg / Len]),
    io:format("~.6f~n", [Zeroes / Len]).


main() ->
    {N, _} = string:to_integer(re:replace(io:get_line(""),
                                          "(^\\s+)|(\\s+$)",
                                          "",
                                          [global, {return, list}])),

    ArrTemp = re:split(re:replace(io:get_line(""),
                                  "\\s+$",
                                  "",
                                  [global, {return, list}]),
                       "\\s+", [{return, list}]),

    Arr = lists:map(fun(X) -> {I, _} = string:to_integer(re:replace(X,
                                                                    "(^\\s+)|(\\s+$)",
                                                                    "",
                                                                    [global, {return, list}])),
                              I end, ArrTemp),

    plusMinus(Arr),

    ok.
