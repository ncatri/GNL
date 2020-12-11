#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Needs 1 argument\n");
		return (0);
	}
	char *line;

	int j;
	int i;
	i = 1;
	j = 1;
	line = NULL;
	int fd = open(argv[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("\n|%s\n", line);
	printf("nb of lines: %d\n", j);
	free(line);
	close(fd);
}
