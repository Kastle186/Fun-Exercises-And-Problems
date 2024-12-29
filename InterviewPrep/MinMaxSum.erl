-module('MinMaxSum').
-export([main/0]).

%
% Complete the 'miniMaxSum' function below.
%
% The function accepts INTEGER_ARRAY arr as parameter.
%

miniMaxSum(Arr) ->
    % The minimum sum is achieved with the first n numbers and the maximum sum
    % from the last n numbers, from a sorted sequence.
    Arr2 = lists:sort(Arr),
    io:format("~p", [lists:sum(lists:sublist(Arr2, 1, 4))]),
    io:format(" ~p~n", [lists:sum(lists:sublist(Arr2, 2, 4))]).


main() ->

    ArrTemp = re:split(re:replace(
                         io:get_line(""), "\\s+$", "", [global, {return, list}]), "\\s+", [{return, list}]),

    Arr = lists:map(fun(X) -> {I, _} = string:to_integer(
                                         re:replace(
                                           X, "(^\\s+)|(\\s+$)", "", [global, {return, list}])),
                              I end, ArrTemp),

    miniMaxSum(Arr),

    ok.
