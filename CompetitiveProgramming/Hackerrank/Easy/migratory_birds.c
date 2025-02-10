#include <stdio.h>
#include <stdlib.h>
#include <hackerrank.h>

#define NUM_BIRD_TYPES 5

int migratory_birds(int, int *);

int main(void)
{
    int arr_count = parse_int(ltrim(rtrim(readline())));
    char **arr_temp = split_string(rtrim(readline()));
    int *arr = (int *) malloc(arr_count * sizeof(int));

    for (int i = 0; i < arr_count; i++)
    {
        int arr_item = parse_int(*(arr_temp + i));
        *(arr + i) = arr_item;
    }

    int result = migratory_birds(arr_count, arr);
    fprintf(stdout, "%d\n", result);

    free(arr_temp);
    free(arr);
    return 0;
}

int migratory_birds(int num_sightings, int *birds)
{
    // To know the bird(s) sighted the most times, we need to sort the list
    // of sightings. However, since we know there are only 5 possible kinds
    // of birds, we can use Counting Sort, which runs in O(n), and then get
    // the max from it.

    // Using +1 here to account for the 0-based indexing.
    int *sorted_sightings = (int *) calloc(NUM_BIRD_TYPES + 1, sizeof(int));

    for (int i = 0; i < num_sightings; i++)
    {
        int bird_id = *(birds + i);
        *(sorted_sightings + bird_id) += 1;
    }

    int most_sightings = 0;
    int most_sighted = 0;

    for (int j = 0; j < NUM_BIRD_TYPES + 1; j++)
    {
        if (*(sorted_sightings + j) <= most_sightings)
            continue;

        most_sightings = *(sorted_sightings + j);
        most_sighted = j;
    }

    free(sorted_sightings);
    return most_sighted;
}
