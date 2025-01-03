#include <stdio.h>
#include <string.h>
#include "tools/hackerrank.h"

char *time_conversion(char *);

int main(void)
{
    char* s = readline();
    char* result = time_conversion(s);
    printf("%s\n", result);

    free(s);
    free(result);
    return 0;
}

char *time_conversion(char *str)
{
    // First, we need to check the last two characters to know whether the given
    // 12-hour time is AM or PM.

    size_t len = strlen(str);
    char meridiem = *(str + len - 2); // "A" or "P".

    // Extract the hour string as int.

    char *endhour_ptr = str + 2;
    int hour = (int) strtol(str, &endhour_ptr, 10);

    // AM times are the same in 24-hour format, sans 12, which is 0 hours.
    // PM times are +12 in 24-hour format, sans 12, which remains the same.

    if (meridiem == 'A' && hour == 12)
        hour = 0;
    else if (meridiem == 'P' && hour < 12)
        hour += 12;

    char *hour24_time = calloc(9, sizeof(char));

    // Copy the new hours value.

    *hour24_time = (char) ((hour / 10) + '0');
    *(hour24_time + 1) = (char) ((hour % 10) + '0');
    *(hour24_time + 2) = ':';

    // Copy the minutes and seconds from the original string.

    for (int i = 3; i < len - 2; i++)
    {
        *(hour24_time + i) = *(str + i);
    }

    return hour24_time;
}
