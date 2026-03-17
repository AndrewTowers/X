#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int abs_dif(int a, int b) {return (a > b) ? a - b : b - a;}

void	put_nbr(int n)
{
	char c = '0' + n;
	write(1, &c, 1);
}

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
	{
		for (int i = 0; i < n; i++)
		{
			put_nbr(board[i]);
			if (i < n - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
		}
		return 1;
	}
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

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Usage: ./queens N\n", 18);
		return 1;
	}
	int n = atoi(argv[1]);
	int *board = malloc(n * sizeof(int));
	if (!board)
		return 1;
	solve_queens(board, 0, n);
	free(board);
	return 0;
}