/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:14:15 by mkulikov          #+#    #+#             */
/*   Updated: 2023/12/06 16:27:35 by mkulikov         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (!s2)
		s2 = ft_strdup("");
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;
	size_t	substrlen;

	if (NULL == s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	substrlen = strlen - start;
	if (len > substrlen)
		len = substrlen;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < destsize)
		ft_memcpy(dest, src, srclen + 1);
	else if (destsize != 0)
	{
		ft_memcpy(dest, src, destsize - 1);
		*(dest + destsize - 1) = '\0';
	}
	return (srclen);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	ptrdst = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (!ptrdst && !ptrsrc)
		return (NULL);
	while (n > 0)
	{
		*ptrdst = *ptrsrc;
		ptrdst++;
		ptrsrc++;
		n--;
	}
	return (dest);
}
