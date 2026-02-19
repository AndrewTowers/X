#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char 	*ft_join(char *s1, char *s2)
{
    int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (free(s1), NULL)
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j];
	res[i] = '\0';
	free(s1);
	return (res);
}

int  has_nl(char *stash)
{
  int  i;

  i = 0;
  while (stash && stash[i])
  {
    if (stash[i] == '\n')
      return (1)
    i++;
  }
  return (0);
}

char *get_line(char *s)
{
	char	*line;
	int		i = 0;

	if (!s || !s[0])
		return (NULL);
	while (s && s[i] != '\n')
		i++;
	line = malloc(i + (s[i] == '\n') + 1);
	if (!line)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		line[i] == s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] == '\n';
	line[i] = '\0';
	return (line);
}

char	*cut_stash(char* s)
{
	char	*new;
	int		i = 0;
	int		j = 0;

	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	new = malloc(fr_strlen(s) - i);
	if (!new)
		return (free(s), NULL);
	i++;
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	return (free(s), new);
}

char *get_next_line(int fd)
{
  static char  *stash;
  char  *buf[BUFFER_SIZE + 1]
  char  *line
  int    rd;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  rd = 1;
  while (!has_nl(stash) && rd > 0)
  {
    rd = read(fd, &buf, BUFFER_SIZE)
    if (rd < 0)
      return (free(stash), stash = NULL, NULL);
    buf = '\0';
    stash = ft_join(stash, buf);
  }
	line = get_line(stash);
	stash = cut_stash(stash);
  return (line);
}
