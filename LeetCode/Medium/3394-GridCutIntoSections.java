// Name: 3394. Check if Grid can be Cut into Sections
// Topics: Array, Sorting

import java.util.Arrays;
import java.util.Comparator;

class GridCutIntoSections
{
    public static void main(String[] args)
    {
        int[][] grid1 =
        {
            {1, 0, 5, 2},
            {0, 2, 2, 4},
            {3, 2, 5, 3},
            {0, 4, 4, 5}
        };

        int[][] grid2 =
        {
            {0, 0, 1, 1},
            {2, 0, 3, 4},
            {0, 2, 2, 3},
            {3, 0, 4, 3}
        };

        int[][] grid3 =
        {
            {0, 2, 2, 4},
            {1, 0, 3, 2},
            {2, 2, 3, 4},
            {3, 0, 4, 2},
            {3, 2, 4, 4}
        };

        System.out.println(checkValidCuts(5, grid1));
        System.out.println(checkValidCuts(4, grid2));
        System.out.println(checkValidCuts(4, grid3));
    }

    private static boolean checkValidCuts(int n, int[][] rectangles)
    {
        // To find whether we can make 2 horizontal or 2 vertical cuts to our grid,
        // we have to check the included rectangles in order to find if there is
        // enough "space between them".
        return canBeSliced(rectangles, 'x') || canBeSliced(rectangles, 'y');
    }

    private static boolean canBeSliced(int[][] rectangles, char dim)
    {
        // First, sort the rectangles grid based on the dimension we are going
        // to analyse.
        sortByDimension(rectangles, dim);

        // Set the indices for the given dimension.
        int startIndex = dim == 'x' ? 0 : dim == 'y' ? 1 : -1;
        int endIndex = dim == 'x' ? 2 : dim == 'y' ? 3 : -2;

        int totalCuts = 0;
        int cutMinStart = rectangles[0][endIndex];

        for (int i = 1; i < rectangles.length; i++)
        {
            // If the next rectangle starts when/after the previous one ends,
            // then we can make a cut here.
            if (rectangles[i][startIndex] >= cutMinStart)
            {
                totalCuts++;

                // We've found our goal, so we can finish early.
                if (totalCuts >= 2)
                    return true;
            }

            // If not, then just update the step where the next cut has to be
            // at least.
            cutMinStart = Math.max(cutMinStart, rectangles[i][endIndex]);
        }

        return false;
    }

    private static void sortByDimension(int[][] grid, char dim)
    {
        // Sort our list/grid of rectangles by dimension. Each dimension's values
        // are represented in the following form:
        //
        // [0] = StartX <-> [2] = EndX
        // [1] = StartY <-> [3] = EndY

        int startIndex = dim == 'x' ? 0 : dim == 'y' ? 1 : -1;
        int endIndex = dim == 'x' ? 2 : dim == 'y' ? 3 : -2;

        Arrays.sort(grid, new Comparator<int[]>()
        {
            @Override
            public int compare(int[] r1, int[] r2)
            {
                return r1[startIndex] == r2[startIndex]
                    ? Integer.compare(r1[endIndex], r2[endIndex])
                    : Integer.compare(r1[startIndex], r2[startIndex]);
            }
        });
    }
}
