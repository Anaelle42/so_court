/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:03:46 by ahenault          #+#    #+#             */
/*   Updated: 2024/04/03 18:32:07 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *stock)
{
	char	*buffer;
	int		nb;

	nb = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (nb != 0 && !ft_strchr(stock, '\n'))
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb] = '\0';
		stock = ft_strjoin_gnl(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*ft_line(char *str)
{
	int		i;
	char	*newline;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newline = malloc(sizeof(char) * (i + 2));
	if (!newline)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		newline[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		newline[i] = '\n';
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*ft_clean(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_clean(stash);
	return (line);
}
