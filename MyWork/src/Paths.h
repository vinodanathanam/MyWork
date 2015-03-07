/*
 * Paths.h
 *
 *  Created on: 7 Mar 2015
 *      Author: vinod
 */

#ifndef PATHS_H_
#define PATHS_H_

#include <vector>
#include <algorithm>

using namespace std;

const int DIMS = 8;

struct pt{
	int x;
	int y;
	pt(int a, int b):x(a), y(b){}
};

bool operator==(const pt& p1, const pt& p2)
{
	return (p1.x == p2.x) && (p1.y == p2.y);
}

vector<pt> g_path;


void printPath(int (&grid)[DIM][DIM])
{
	//first add the found path;
	for(vector<pt>::iterator it = g_path.begin(); it !=  g_path.end(); it++)
	{
		grid[it->x][it->y] = 1;
	}

	//print
	for(int i = 0; i < DIMS; i++)
	{
		for(int j = 0; j < DIMS; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

bool isFree(int (&grid)[DIM][DIM], int row, int col)
{
	if(NULL == grid || row >= DIMS || row < 0 || col < 0 || col >= DIMS)
		return false;

	//check grid
	if(grid[row][col] != 0)
		return false;

	//also check path so far
	if(g_path.end() != find(g_path.begin(), g_path.end(), pt(row,col)))
		return false;

	return true;
}

bool findPath(int (&grid)[DIM][DIM], int row, int col)
{
	pt p(row, col);
	g_path.push_back(p);
	if(DIMS == row+1 && DIMS == col+1)
	{
		printPath(grid);
		return true;
	}

	bool success(false);
	//check right
	if(col+1 < DIMS && isFree(grid, row, col + 1))
		success = findPath(grid, row, col + 1);

	//check down;
	if(false == success && row+1 < DIMS && isFree(grid, row + 1, col))
		success = findPath(grid, row+1, col);

	//check up
	if(false == success && row-1 >= 0 && isFree(grid, row -1, col))
		success = findPath(grid, row-1, col);

	//check left
	if(false == success && col >= 0 && isFree(grid, row, col-1))
		success = findPath(grid, row, col-1);

	//still false ? revert step
	if(false == success)
		g_path.erase(std::remove(g_path.begin(), g_path.end(), p), g_path.end());

	return success;
}




void findGridPath()
{
	/*
	int** grid = new int*[DIM];
	for(int i= 0; i < DIM; i++)
	{
		grid[i] = new int[DIM];
	}
	*/

	int grid[DIM][DIM] = {
			 {0,2,0,0,0,0,0,0}
			,{0,2,0,0,0,0,0,0}
			,{0,2,0,0,4,3,0,0}
			,{0,2,0,0,0,3,0,0}
			,{0,2,2,2,0,3,0,0}
			,{0,0,0,0,0,3,0,0}
			,{0,0,0,0,0,3,0,0}
			,{0,0,0,0,0,3,0,0}
	};

	findPath(grid, 0,0);

	/*for(int i= 0; i < DIM; i++)
	{
		delete [] grid[i];
	}
	delete [] grid;
	*/
}

#endif /* PATHS_H_ */
