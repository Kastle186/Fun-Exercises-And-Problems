#include <stdio.h>
#include <stdlib.h>
#include <hackerrank.h>

int library_fine(int, int, int, int, int, int);

int main(void)
{
    char **first_multiple_input = split_string(rtrim(readline()));

    int d1 = parse_int(*(first_multiple_input + 0));
    int m1 = parse_int(*(first_multiple_input + 1));
    int y1 = parse_int(*(first_multiple_input + 2));

    char **second_multiple_input = split_string(rtrim(readline()));

    int d2 = parse_int(*(second_multiple_input + 0));
    int m2 = parse_int(*(second_multiple_input + 1));
    int y2 = parse_int(*(second_multiple_input + 2));

    int result = library_fine(d1, m1, y1, d2, m2, y2);
    fprintf(stdout, "%d\n", result);

    free(first_multiple_input);
    free(second_multiple_input);
    return 0;
}

int library_fine(int d1, int m1, int y1, int d2, int m2, int y2)
{
    // Returned at least one year before means it was obviously returned on time,
    // so no extra fees.
    if (y1 < y2)
        return 0;

    // One or more years late delivery is a fixed 10,000 credits extra fee.
    if (y1 > y2)
        return 10000;

    int month_diff = m1 - m2;

    // The extra fee is 500 credits for each month late.
    if (month_diff > 0)
        return 500 * month_diff;

    // At least one month before the due date means delivery on time, so no
    // extra fees.
    if (month_diff < 0)
        return 0;

    // The extra fee is 15 credits for each day late if returned within the
    // same month.
    int day_diff = d1 - d2;
    return day_diff <= 0 ? 0 : 15 * day_diff;
}
