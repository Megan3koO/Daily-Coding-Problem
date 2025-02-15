/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

You are given a 2D matrix of 1s and 0s where 1 represents land and 0 represents water.

Grid cells are connected horizontally orvertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

An island is a group is cells connected horizontally or vertically, but not diagonally. There is guaranteed to be exactly one island in this grid, and the island doesn't have water inside that isn't connected to the water around the island. Each cell has a side length of 1.

Determine the perimeter of this island.

For example, given the following matrix:

[[0, 1, 1, 0],
[1, 1, 1, 0],
[0, 1, 1, 0],
[0, 0, 1, 0]]

Return 14.
*/

#include <iostream>
#define H 4
#define W 4
const int island[H][W] = {{0,0,1,0},{1,1,1,0},{0,1,1,0},{0,0,1,0}};

int ComputeEdge(const int i_island[H][W], int v_coord, int h_coord)
{
    if (i_island[v_coord][h_coord] != 1)
    {
        //sea
        return 0;
    }

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
    if (v_coord > 0)
    {
        up = i_island[v_coord - 1][h_coord]; //do if v_coord > 0
    }
    if (v_coord < H - 1)
    {
        down = i_island[v_coord + 1][h_coord]; //do if v_coord < V - 1
    }
    if (h_coord > 0)
    {
        left = i_island[v_coord][h_coord - 1]; //do if h_coord > 0
    }
    if (h_coord < W - 1)
    {
        right = i_island[v_coord][h_coord + 1]; //do if h_coord < V - 1
    }

    return 4 - (up + down + left +  right);
}
int ComputePerimeter(const int i_island[H][W])
{
    int perimeter = 0;
    for (int i=0; i<H; i++)
    {
        for (int j=0; j<W; j++)
        {
            perimeter+=ComputeEdge(i_island, i, j);
        }
    }
    return perimeter;
}
void PrintIsland(const int i_island[H][W])
{
for (int i=0; i<H; i++)
    {
        for (int j=0; j<W; j++)
        {
            std::cout << i_island[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    PrintIsland(island);
    std::cout << "The perimeter of the island is: " << ComputePerimeter(island) << std::endl;
    return 0;
}
