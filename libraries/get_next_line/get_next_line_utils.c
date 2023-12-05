/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:52:46 by ebakirog          #+#    #+#             */
/*   Updated: 2023/10/29 11:12:59 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup_gnl(const char *s)
{
	size_t	len;
	char	*dup;
	int		i;

	i = 0;
	len = ft_strlen_gnl(s) + 1;
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	while (*s)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	calc_len;

	calc_len = ft_strlen_gnl(s);
	if (!s || len <= 0)
		return (NULL);
	if (len > calc_len)
		len = calc_len;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (i < calc_len && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (!*stash)
		return (NULL);
	if (create_line == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	else if (create_line == 1)
	{
		line = ft_strdup_gnl(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	return (NULL);
}
