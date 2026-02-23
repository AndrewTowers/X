#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	print_solution(char *s){puts(s);}

int	is_valid(char *s)
{
	int	balance = 0;
	for(int i = 0; s[i]; i++)
	{
		if (s[i] == '(') balance++;
		else if (s[i] == ')') balance--;
		if (balance < 0) return (0);
	}
	return (balance == 0);
}

void	backtracking(char *s, int start, int remove_right, int remove_left)
{
	if (remove_right == 0 && remove_left == 0)
	{
		if (is_valid(s))
			print_solution(s);
		return ;
	}
	for(int i = start; s[i]; i++)
	{
		if (i > start && s[i] == s[i - 1]) continue;
		if (s[i] == '(' && remove_left > 0)
		{
			char	*copy = strdup(s);
			copy[i] = " ";
			backtracking(copy, i + 1, remove_right, remove_left - 1);
			free(copy);
		}
		else if (s[i] == ')' && remove_right > 0)
		{
			char	*copy = strdup(s);
			copy[i] = " ";
			backtracking(copy, i + 1, remove_right - 1, remove_left);
			free(copy);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	char	*s = argv[1];
	int		remove_right = 0, remove_left = 0, balance = 0;

	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(') balance++;
		else if (s[i] == ')')
		{
			if (balance == 0) remove_right++;
			else balance--;
		}
	}
	remove_left = balance;
	backtracking(s, 0, remove_right, remove_left);
}
