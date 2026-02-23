#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

float	distance(float a[2], float b[2])
{
	float	dx = a[0] - b[0];
	float	dy = a[1] - b[1];
	return sqrtf(dx * dx + dy * dy);
}

void	tsp(float cities[][2], int n, int current, int count, float coast, int *visited, float *best)
{
	if (count == n)
	{
		cost += distance(cities[current], cities[0]);
		if (cost < *best)
			*best = cost;
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			tsp(cities, n, i, count + 1, coast + distance(cities[current], cities[i]), visited, best);
			visited[i] = 0;
		}
	}
}

int	main(void)
{
	float	cities[11][2];
	int		n = 0;

	while (fscanf(stdin, "%f, %f\n", &cities[n][0], &cities[n][1]) == 2)
		n++;
	float	best = FLT_MAX
	int		visited[11] = {0};
	visited[0] = 1;
	tsp(cities, n, 0, 1, 0.0, visited, &best);
	printf("%.2f\n", best);
	return (0);
}
