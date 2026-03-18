#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# ifndef        BUFFER_SIZE
#    define  BUFFER_SIZE 42
# endif

char    *get_next_line(int fd)
{
        static  char buffer[BUFFER_SIZE];
        static  int     i = 0;
        static  int     bytes = 0;
        char    *line;
        int             j = 0;

        //proteccion
        if (fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);

        //reserva de memoria malloc sin medir
        line = malloc(10000);
        if (!line)
                return (NULL);
        while(1)
        {
                if (i >= bytes)
                {
                        bytes = read(fd, buffer, BUFFER_SIZE);
                        i = 0;
                        if (bytes <= 0)
                        {
                                free(line);
                                return (NULL);
                        }
                }
                line[j++] = buffer[i++];
                if (line[j - 1] == '\n')
                        break ;
        }
        line[j] = '\0';
        return (line);

}
int main()
{
        int fd = open("test.txt", O_RDONLY);
        char *line;

        line = get_next_line(fd);
        while (line)
        {
                printf("aa");
                printf("%s", line);
                free(line);
                line = get_next_line(fd);
        }
        close(fd);
        return (0);
}

/*variables estaticas
proteccion inicial
reserva de line con malloc 10000
bucle principal
return
*/