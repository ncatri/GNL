/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:13:38 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/01 18:16:30 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	get_next_line(int fd, char **line)
{
	int	ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = get_line(fd, line)) > 0)
		;
	return (ret);
}

/* returns the index of the new line in buffer if found, or length of buff if nl not found */

int	check_nl(char *buf)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}


int	get_line(int fd, char **line)
{
	static	char	buffer[BUFFER_SIZE];
	int nl_index;
	char	*tmp;

	if (buffer[0] == 0)
		read(fd, buffer, BUFFER_SIZE);
	nl_index = check_nl(buffer);
	if (!*line) //-> *line not previously allocated, needs to copy nl_index char
	{
		if (!(tmp = malloc(sizeof(char) * (nl_index + 1)))) //+1 for \0
			return (-1);
		strlcpy(tmp, buffer, nl_index + 1);
		*line = tmp;
		return (nl_index);
	}
	else if (nl_index >= 0 && !(*line))

