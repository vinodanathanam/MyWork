/*
 * Queen.h
 *
 *  Created on: 7 Mar 2015
 *      Author: vinod
 */

#ifndef QUEEN_H_
#define QUEEN_H_

const int DIM = 8;

bool canPlaceQ(int *grid[DIM], int row, int col)
{
	//check same row towards left
	for(int c = 0; c < col; c++)
	{
		if(grid[row][c] == 1)
			return false;
	}

	//check top left diagonal
	int r(row), c(col);
	for(; r >= 0 && c >= 0; r--, c--)
	{
		if(grid[r][c] == 1)
			return false;
	}

	//check bottom left diagonal
	r = row;
	c = col;
	for(;r <= DIM && c >= 0; r++, c--)
	{
		if(grid[r][c] == 1)
			return false;
	}

	return true;
}

bool placeQueen(int *grid[DIM], int col)
{
	if(col < 0 || col >= DIM)
		return true;

	for(int r = 0; r < DIM; r++)
	{
		if(canPlaceQ(grid, r, col))
		{
			grid[r][col] = 1;
			if(placeQueen(grid, col + 1))
				return true;

			grid[r][col] = 0;
		}
	}
	return false;
}

void printQGrid(int *grid[DIM])
{
	for(int r = 0; r < DIM; r++)
	{
		for(int c = 0; c < DIM; c++)
		{
			printf("%d ", grid[r][c]);
		}
		printf("\n");
	}
}

void placeQueens(int dim, int startcol)
{
	//int grid[DIM][DIM] = {{}};

	//printQGrid(&grid);

	int *a[DIM];
	for(int i=0; i < DIM; i++)
		a[i] = new int[DIM];

	if(placeQueen(a, 0))
		printQGrid(a);
	else
		printf("Failed to place Q\n");

	for(int i=0; i < DIM; i++)
		delete [] a[i];

}

#endif /* QUEEN_H_ */
