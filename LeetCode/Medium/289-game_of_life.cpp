// Name: 289. Game of Life
// Topics: Array, Matrix, Simulation
// Companies:
// - Dropbox
// - Two Sigma
// - Snap
// - Anduril
// - Google
// - Cisco

#include <iostream>
#include <vector>

typedef enum FormerValuePlaceHolder
{
    NEW_ZERO = 2,
    NEW_ONE  = 3
} FormerValuePlaceHolder;

void game_of_life(std::vector<std::vector<int>>&);

int get_one_neighbors(std::vector<std::vector<int>>&,
                      std::vector<int>::size_type,
                      std::vector<int>::size_type,
                      std::vector<int>::size_type,
                      std::vector<int>::size_type);

void print_matrix(std::vector<std::vector<int>>&);

// Vectors to make it cleaner and simpler to check the neighbors:
// South, East, North, West, Southeast, Southwest, Northeast, Northwest.
std::vector<int> directions_x = { 0, 1, 0, -1, 1, -1, 1, -1 };
std::vector<int> directions_y = { 1, 0, -1, 0, 1, 1, -1, -1 };

int main(void)
{
    std::vector<std::vector<int>> board_1 = {
        { 0, 1, 0 },
        { 0, 0, 1 },
        { 1, 1, 1 },
        { 0, 0, 0 }
    };

    std::vector<std::vector<int>> board_2 = {
        { 1, 1 },
        { 1, 0 }
    };

    std::cout << "Matrix 1 Original:\n" << std::endl;
    print_matrix(board_1);

    std::cout << "\nMatrix 2 Original:\n" << std::endl;
    print_matrix(board_2);

    game_of_life(board_1);
    game_of_life(board_2);

    std::cout << "\nMatrix 1 Modified:\n" << std::endl;
    print_matrix(board_1);

    std::cout << "\nMatrix 2 Modified:\n" << std::endl;
    print_matrix(board_2);

    return 0;
}

void game_of_life(std::vector<std::vector<int>>& board)
{
    std::vector<int>::size_type rows = board.size();
    std::vector<int>::size_type cols = board[0].size();

    // This is a simulation problem with a twist. The tile changes ought to happen
    // at the same time. But how do we achieve that? We could build a copy of the
    // board and update the values there while referencing the original, or we can
    // do it in-place. For the latter approach, we will be replacing each tile value
    // that changes with a placeholder. This, with the goal of keeping track of the
    // new values, while being able to know that it was changed, and therefore we
    // should reference its previous value instead.

    for (std::vector<int>::size_type i = 0; i < rows; i++)
    {
        for (std::vector<int>::size_type j = 0; j < cols; j++)
        {
            // First, we have to get the number of neighbors with an original
            // value of 1 of each tile. Emphasis on "original" here. If it's
            // labeled as NEW_ZERO, then for this conditional's purposes it
            // counts as 1, as the problem specifies all the changes would happen
            // at the same time.

            int tile = board[i][j];
            int live_neighbors = get_one_neighbors(board, rows, cols, i, j);

            // Depending on the number of 1/NEW_ZERO neighbors, we can define how
            // this tile would change, if at all.

            if (tile == 1 && (live_neighbors < 2 || live_neighbors > 3))
                board[i][j] = NEW_ZERO;
            else if (tile == 0 && live_neighbors == 3)
                board[i][j] = NEW_ONE;
        }
    }

    // Update the values of the board by replacing NEW_ZERO with 0 and NEW_ONE
    // with 1.

    for (std::vector<int>::size_type i = 0; i < rows; i++)
    {
        for (std::vector<int>::size_type j = 0; j < cols; j++)
        {
            int tile = board[i][j];
            if (tile == NEW_ZERO)
                board[i][j] = 0;
            else if (tile == NEW_ONE)
                board[i][j] = 1;
        }
    }
}

int get_one_neighbors(std::vector<std::vector<int>>& board,
                      std::vector<int>::size_type rows,
                      std::vector<int>::size_type cols,
                      std::vector<int>::size_type i,
                      std::vector<int>::size_type j)
{
    int one_neighbors = 0;

    // Check the 8 directions and count the "live" neighbors (i.e. 1 or NEW_ZERO).
    // We use the directions_x and directions_y vectors for cleaner code.

    for (int k = 0; k < 8; k++)
    {
        int x = directions_x[k] + i;
        int y = directions_y[k] + j;

        if (x < 0 || x >= rows || y < 0 || y >= cols)
            continue;

        int neighbor = board[x][y];

        if (neighbor == 1 || neighbor == NEW_ZERO)
            one_neighbors++;
    }

    return one_neighbors;
}

void print_matrix(std::vector<std::vector<int>>& matrix)
{
    std::cout << "[" << std::endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        std::cout << "  [" << matrix[i][0];
        for (int j = 1; j < matrix[i].size(); j++)
        {
            std::cout << "," << matrix[i][j];
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}
