-module('LibraryFine').
-export([main/0]).

libraryFine(D1, M1, Y1, D2, M2, Y2) ->
    % Returned at least one year before means it was obviously returned on time,
    % so no extra fees.
    if
        Y1 < Y2 -> 0;
        % One or more years late delivery is a fixed 10,000 credits extra fee.
        Y1 > Y2 -> 10000;
        true ->
            MonthDiff = M1 - M2,
            % The extra fee is 500 credits for each month late.
            if
                MonthDiff > 0 -> 500 * MonthDiff;
                % At least one month before the due date means delivery on time,
                % so no extra fees.
                MonthDiff < 0 -> 0;
                true ->
                    % The extra fee is 15 credits for each day late if returned
                    % within the same month.
                    DayDiff = D1 - D2,
                    if
                        DayDiff =< 0 -> 0;
                        true -> 15 * DayDiff
                    end
            end
    end.


main() ->
    FirstMultipleInput = re:split(re:replace(io:get_line(""),
                                             "\\s+$",
                                             "",
                                             [global, {return, list}]),
                                  "\\s+", [{return, list}]),

    {D1, _} = string:to_integer(lists:nth(1, FirstMultipleInput)),
    {M1, _} = string:to_integer(lists:nth(2, FirstMultipleInput)),
    {Y1, _} = string:to_integer(lists:nth(3, FirstMultipleInput)),

    SecondMultipleInput = re:split(re:replace(io:get_line(""),
                                              "\\s+$",
                                              "",
                                              [global, {return, list}]),
                                   "\\s+", [{return, list}]),

    {D2, _} = string:to_integer(lists:nth(1, SecondMultipleInput)),
    {M2, _} = string:to_integer(lists:nth(2, SecondMultipleInput)),
    {Y2, _} = string:to_integer(lists:nth(3, SecondMultipleInput)),

    Result = libraryFine(D1, M1, Y1, D2, M2, Y2),
    io:format("~w~n", [Result]),

    ok.
