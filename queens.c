#include <stdio.h>
#include <stdlib.h>

int abs_dif(int a, int b) {return (a > b) ? a - b : b - a;}


int is_safe(int board[],int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		if (board[i] == col || abs_dif(board[i], col) == row - i)
			return 0;
	}
	return 1;
}

int solve_queens(int board[], int row, int n)
{
	if(row == n)
		return 1;
	int count = 0;
	for(int col = 0; col < n; col++)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			count += solve_queens(board, row + 1, n);
		}
	}
	return count;
}

int main(void)
{
	int board[10];
	printf("number of solutions: %d\n",solve_queens(board, 0, 10));
	return 0;
}