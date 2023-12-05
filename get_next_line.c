/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:13:59 by mkulikov          #+#    #+#             */
/*   Updated: 2023/12/05 18:25:06 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_get_line(char *buf, char *line, int r)
// {
// 	char	*temp;
// 	char	*substr;

// 	if (r == 0)
// 		return (NULL);
// 	line = ft_strdup("");
// 	buf[r] = '\0';
// 	temp = line;
// 	if (ft_strchr(buf, ENDL))
// 	{
// 		substr = ft_substr(buf, 0, ft_strchr(buf, ENDL) - buf + 1);
// 		line = ft_strjoin(temp, substr);
// 		free(substr);
// 		return (line);
// 	}
// 	line = ft_strjoin(temp, buf);
// 	free(temp);
// 	return (line);
// }

int	fill_str(char **str, char *buf)
{
	int		i;
	char	*substr;
	char	*temp;

	if (ft_strlen(buf) == 0)
		return (-1);
	i = 0;
	while (*(buf + i) && (*(buf + i) != ENDL))
		i++;
	substr = ft_substr(buf, 0, i + 1);
	temp = *str;
	*str = ft_strjoin(temp, substr);
	printf("str - %s\n", *str);
	return (i);
}

char	*ft_read(int fd, char *buf, char *stash)
{
	ssize_t	r;
	char	*temp;

	r = 1;
	while (r)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(stash);
			return (NULL);
		}
		if (r == 0)
			break ;
		*(buf + r) = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(stash, ENDL))
			break ;
	}
	return (stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	while (*(stash + i) && *(stash + i) != ENDL)
		i++;
	line = ft_substr(stash, 0, i + 1);
	temp = stash;
	stash = ft_substr(temp, i + 1, ft_strlen(temp) - 1);
	// free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char	*stash;

	stash = ft_strdup("");
	if (BUFFER_SIZE <= 0 || fd == -1 || read(fd, buf, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	temp = stash;
	stash = ft_read(fd, buf, temp);
	free(temp);
	temp = NULL;
	line = ft_get_line(stash);
	if (!line)
		return (NULL);
	return (line);
}
