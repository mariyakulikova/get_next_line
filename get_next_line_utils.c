/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:14:15 by mkulikov          #+#    #+#             */
/*   Updated: 2023/12/11 11:45:01 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		++str;
		++len;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;

	len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*src)
	{
		*str = *src;
		src++;
		str++;
	}
	*str = '\0';
	return (str - len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while ((char)c != *ptr && *ptr)
		ptr++;
	if ((char)c == *ptr)
		return (ptr);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	substrlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	substrlen = ft_strlen(s) - start;
	if (len > substrlen)
		len = substrlen;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
