/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:13:59 by mkulikov          #+#    #+#             */
/*   Updated: 2023/12/06 17:59:04 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf, char *stash)
{
	ssize_t	r;

	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(stash);
			return (NULL);
		}
		if (r == 0)
			return (stash);
		*(buf + r) = '\0';
		if (ft_strchr(buf, ENDL))
		{
			stash = ft_strjoin(stash, buf);
			return (stash);
		}
	}
}

char	*ft_get_line(char **stash)
{
	int		i;
	char	*line;

	i = 0;
	while (*(*stash + i) && *(*stash + i) != ENDL)
		i++;
	line = ft_substr(*stash, 0, i + 1);
	*stash = ft_substr(*stash, i + 1, ft_strlen(*stash) - 1);
	if (ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;

	if (!stash)
		stash = ft_strdup("");
	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd, buf, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_read(fd, buf, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(&stash);
	return (line);
}
