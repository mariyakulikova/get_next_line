/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:13:59 by mkulikov          #+#    #+#             */
/*   Updated: 2023/12/01 16:40:07 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill_line(char **line, char *buf, int chars_read)
{
	int	i;

	i = 0;
	while (i < chars_read)
	{
		if (**(line + i) != ENDL)


	}
}

char	*get_next_line(int fd)
{
	int			chars_read;
	char		buf[BUFFER_SIZE];
	char		*line;
	static char	remind[BUFFER_SIZE];

	remind = {'\0'};
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	*line = '\0';
	chars_read = read(fd, buf, BUFFER_SIZE);
	while (chars_read)
	{
		fill_line(line, buf, chars_read);
		chars_read = read(fd, buf, BUFFER_SIZE);
	}


	line = NULL;
	return (line);
}
