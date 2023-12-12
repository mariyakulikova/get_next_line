/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:51:18 by mkulikov          #+#    #+#             */
/*   Updated: 2023/12/12 13:35:49 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *buf, char *stash)
{
	ssize_t	r;
	char	*temp;

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
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(stash, ENDL))
			break ;
	}
	return (stash);
}

char	*ft_get_line(char **stash)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	while (*(*stash + i) && *(*stash + i) != ENDL)
		i++;
	temp = *stash;
	line = ft_substr(temp, 0, i + 1);
	*stash = ft_substr(temp, i + 1, ft_strlen(temp) - 1);
	free(temp);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash[1024];

	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd, NULL, 0) < 0)
	{
		free(*(stash + fd));
		*(stash + fd) = NULL;
		return (NULL);
	}
	if (!*(stash + fd))
		*(stash + fd) = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	*(stash + fd) = ft_read(fd, buf, *(stash + fd));
	if (!*(stash + fd))
		return (NULL);
	line = ft_get_line(&(*(stash + fd)));
	free(buf);
	return (line);
}
