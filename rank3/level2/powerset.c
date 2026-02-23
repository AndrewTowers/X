#include <stdio.h>
#include <stdlib.h>

static void	print_subset(int *subset, int subset_size)
{
	for (i = 0; i < subset_size, i++)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subset[i]);
		i++;
	}
	printf("\n");
}

static void	backtrack(int *set, int set_size, int target, int index, int *subset, int subset_size, int current_sum)
{
	// Summa igual a target -> print
	if (current_sum == target)
		print_subset(subset,subset_size);
	// Llegar final
	if (index == set_size)
		return ;
	// Incluir set[index] en subset
	subset[subset_size] = set[index];
	backtrack(set, set_size, target, index + 1, subset, subset_size + 1, current_sum + set[index]);
	backtrack(set, set_size, target, index + 1, subset, subset_size, current_sum + set[index]);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	int	target = argv[1];
	int	set_size = argc - 2;
	int	*set = malloc(sizeof(int) * set_size);
	if (!set)
		return (1);
	for (int i = 0; i < set_size; i++)
		set[i] = atoi(argv[i + 2]);
	int	*subset = malloc(sizeof(int) * set_size);
	if (!subset)
	{
		free(set);
		return (1);
	}
	bactrack(set, set_size, target, 0, subset, 0, 0);
	free(set);
	free(subset);
	return (0);
}
