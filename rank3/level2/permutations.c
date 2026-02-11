#include <unistd.h>
#include <stdlib.h>

void swap(char *a, char*b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

void ft_putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
    write(1, "\n", 1);
}

static void	ft_sort(char *str)
{
	int i, j;
	char tmp;
	int len = ft_strlen(str);

	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
}

static void	ft_permute(char *str, int l, int r)
{
	int i;

	if (l == r)
	{
		ft_putstr(str);
		return ;
	}
	for (i = l; i <= r; i++)
	{
		ft_swap(&str[l], &str[i]);
		ft_permute(str, l + 1, r);
		ft_swap(&str[l], &str[i]); // backtrack
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_sort(av[1]);
		ft_permute(av[1], 0, ft_strlen(av[1]) - 1);
	}
	return (0);
}