/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:12:28 by ncatrien          #+#    #+#             */
/*   Updated: 2020/12/10 15:51:28 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
	char *line;

//	int fd = open("42_with_nl", O_RDWR);
	int fd = 0;
	int r;
	line = NULL;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
/*	if (r == 0)
	{
		printf("%s\n", line);
		free(line);
	}	
*/
}
