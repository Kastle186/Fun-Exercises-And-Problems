#include <stdio.h>
#include "tools/hackerrank.h"

int page_count(int, int);

int main(void)
{
    int n = parse_int(ltrim(rtrim(readline())));
    int p = parse_int(ltrim(rtrim(readline())));
    int result = page_count(n, p);

    printf("%d\n", result);
    return 0;
}

int page_count(int n, int p)
{
    // We know the book has the following properties:
    // - Book opening only has Page 1
    // - Book closing is blank, so we can infer that it ends with page n and page n-1.
    //
    // With these in mind, we can deduce that turning pages from the front will
    // take p/2 turns. And turning pages from the back, the same applies but we
    // have to subtract the page we're looking for, from the total to get the effective
    // number of pages we have to traverse.

    int front = p / 2;
    int back = (n - p) / 2;

    // There is an exception to this rule when counting pages from the back, that
    // happens when the book has an even amount of pages. If we're looking for the
    // an odd-numbered page, then we will need one more turn that we normally would.

    if (n % 2 == 0 && p % 2 == 1)
        ++back;

    return front <= back ? front : back;
}
