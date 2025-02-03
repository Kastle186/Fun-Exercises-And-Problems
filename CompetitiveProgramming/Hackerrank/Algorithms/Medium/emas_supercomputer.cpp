#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <hackerrank.hpp>

class Point
{
public:
    int x;
    int y;

    Point(int x_val, int y_val)
    {
        x = x_val;
        y = y_val;
    }

    bool operator< (const Point &right) const
    {
        return x < right.x && y < right.y;
    }

    std::string to_str() const
    {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
};


class PlusCross
{
public:
    int area;
    std::set<Point> tiles;

    PlusCross(int area_val)
    {
        area = area_val;
    }

    void add_tiles(std::set<Point> tile_coords)
    {
        tiles.insert(tile_coords.begin(), tile_coords.end());
    }

    bool overlaps_with(PlusCross other)
    {
        for (std::set<Point>::iterator it = tiles.begin(); it != tiles.end(); it++)
        {
            if (other.tiles.find(*it) != other.tiles.end())
                return true;
        }

        return false;
    }

    void print_plus_cross()
    {
        std::cout << "AREA: " << area << std::endl;
        std::cout << "TILES: " << std::endl;

        for (auto it = tiles.begin(); it != tiles.end(); it++)
        {
            std::cout << (*it).to_str() << std::endl;
        }
    }
};


int two_pluses(std::vector<std::string>);
std::vector<PlusCross> find_crosses_from_source(std::vector<std::string>,
                                                int,
                                                int,
                                                int,
                                                int);

bool are_part_of_cross(std::vector<std::string>, int, int, int);
bool are_in_grid(int, int, int, int, int);

int main(void)
{
    std::string first_multiple_input_temp;
    std::getline(std::cin, first_multiple_input_temp);

    std::vector<std::string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));

    int n = std::stoi(first_multiple_input[0]);
    int m = std::stoi(first_multiple_input[1]);

    std::vector<std::string> grid(n);

    for (int i = 0; i < n; i++) {
        std::string grid_item;
        std::getline(std::cin, grid_item);
        grid[i] = grid_item;
    }

    int result = two_pluses(grid);
    std::cout << result << std::endl;
    return 0;
}

int two_pluses(std::vector<std::string> grid)
{
    int highest_prod_area = 0;
    std::vector<PlusCross> pluses;

    // First, we need to find all the possible pluses/crosses in the grid we
    // we were given.

    for (int i = 0; i < grid.size(); i++)
    {
        std::string row = grid[i];

        for (int j = 0; j < row.length(); j++)
        {
            // Not a "good" tile, so nothing to search here.
            if (row[j] != 'G')
                continue;

            std::vector<PlusCross> tile_crosses =
                find_crosses_from_source(grid, i, j, grid.size(), row.length());
            pluses.insert(pluses.end(), tile_crosses.begin(), tile_crosses.end());
        }
    }

    // Now, we find the two pluses/crosses whose area product is the maximum one.

    for (int i = 0; i < pluses.size(); i++)
    {
        for (int j = i + 1; j < pluses.size(); j++)
        {
            if (pluses[i].overlaps_with(pluses[j]))
                continue;

            highest_prod_area = std::max(highest_prod_area,
                                         pluses[i].area * pluses[j].area);
        }
    }

    return highest_prod_area;
}

std::vector<PlusCross> find_crosses_from_source(
    std::vector<std::string> grid,
    int x,
    int y,
    int rows,
    int columns)
{
    // We have to keep track of all coordinates taken by the current plus/cross,
    // as there will be overlaps. Like for example, a 5x5 cross also includes
    // a 3x3 and a 1x1 one by definition.

    std::set<Point> tiles_used;
    std::vector<PlusCross> pluses;
    int total_area = 1;
    int i = 1;

    // The current point counts as a 1x1 plus/cross, so we add it to the set of
    // tiles visited, and the pluses/crosses we found starting from here.

    tiles_used.emplace(Point(x, y));
    PlusCross orig_cross(total_area);
    orig_cross.add_tiles(tiles_used);

    pluses.push_back(orig_cross);

    // In this loop, we grow each edge of the plus/cross by one and test if it
    // still is a valid plus/cross. If yes, then we record it into a new object.
    // If not, then we end the loop and we're done with this tile as an origin.

    while (are_in_grid(x, y, i, rows, columns) && are_part_of_cross(grid, x, y, i))
    {
        tiles_used.emplace(Point(x + i, y));
        tiles_used.emplace(Point(x - i, y));
        tiles_used.emplace(Point(x, y + i));
        tiles_used.emplace(Point(x, y - i));

        total_area += 4;
        i++;

        PlusCross next_cross(total_area);
        next_cross.add_tiles(tiles_used);
        pluses.push_back(next_cross);
    }

    return pluses;
}

bool are_part_of_cross(std::vector<std::string> grid, int x, int y, int i)
{
    return (grid[x+i][y] == 'G'
            && grid[x-i][y] == 'G'
            && grid[x][y+i] == 'G'
            && grid[x][y-i] == 'G');
}

bool are_in_grid(int x, int y, int i, int rows, int columns)
{
    return (x + i < rows && x - i >= 0 && y + i < columns && y - i >= 0);
}
