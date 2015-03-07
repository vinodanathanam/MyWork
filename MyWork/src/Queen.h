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

bool canPlaceQ(int **grid, int row, int col, int dim)
{
	if(row >= dim || col >= dim)
		return false;

	//check same row towards left
	for(int c = 0; c <= col; c++)
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
	for(;r < dim && c >= 0; r++, c--)
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

bool placeQueen(int **grid, int col, int dim)
{
	if(col < 0 || col >= dim)
		return true;

	for(int r = 0; r < dim; r++)
	{
		if(canPlaceQ(grid, r, col, dim))
		{
			grid[r][col] = 1;
			if(placeQueen(grid, col + 1, dim))
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

void printQGrid(int **grid, int dim)
{
	for(int r = 0; r < dim; r++)
	{
		for(int c = 0; c < dim; c++)
		{
			printf("%d ", grid[r][c]);
		}
		printf("\n");
	}
}

void placeQueens(int startcol)
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

void placeQueens(int dim, int startcol)
{
	//int grid[DIM][DIM] = {{}};

	//printQGrid(&grid);

	int **a = new int *[dim];
	for(int i=0; i < dim; i++)
		a[i] = new int[dim];

	if(placeQueen(a, 0, dim))
	{
		printf("Success to place Q\n");
		printQGrid(a, dim);
	}
	else
		printf("Failed to place Q\n");

	for(int i=0; i < dim; i++)
		delete [] a[i];

	delete [] a;

}

#endif /* QUEEN_H_ */
