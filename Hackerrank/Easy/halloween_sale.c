#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <hackerrank.h>

int how_many_games(int, int, int, int);

int main(void)
{
    char **first_multiple_input = split_string(rtrim(readline()));

    int p = parse_int(*(first_multiple_input + 0));
    int d = parse_int(*(first_multiple_input + 1));
    int m = parse_int(*(first_multiple_input + 2));
    int s = parse_int(*(first_multiple_input + 3));

    int answer = how_many_games(p, d, m, s);
    fprintf(stdout, "%d\n", answer);

    free(first_multiple_input);
    return 0;
}

int how_many_games(int first_price, int discount, int lowest_price, int budget)
{
    int games = 0;
    int next_price = first_price;

    while(true)
    {
        int rem_budget = budget - next_price;

        // If we would go into the negatives, then we can't afford another game,
        // so we finish buying.
        if (rem_budget < 0)
            break;

        // Update the game count, budget, and price of the next game.
        games++;
        budget = rem_budget;
        next_price -= discount;

        // Make sure we don't go below the minimum acceptable price by the shop
        // for the game.
        if (lowest_price > next_price)
            next_price = lowest_price;
    }

    return games;
}
