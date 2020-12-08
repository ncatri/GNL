#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char *line;

	int fd_fr = open("frereJ_fr.txt", O_RDWR);
	int fd_en = open("frereJ_en.txt", O_RDWR);
	int fd_es = open("frereJ_es.txt", O_RDWR);
	int i = 0;
	while (i < 4)
	{
		get_next_line(fd_fr, &line);
		printf("fr:  %s\n",line);
		free(line);
		get_next_line(fd_en, &line);
		printf("en:  %s\n",line);
		free(line);
		get_next_line(fd_es, &line);
		printf("es:  %s\n",line);
		free(line);
		i++;
	}
	while (1)
		;
}
