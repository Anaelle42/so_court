/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahenault <ahenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:04:02 by ahenault          #+#    #+#             */
/*   Updated: 2024/04/03 18:38:13 by ahenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"
# include <fcntl.h>  // open
# include <stdio.h>  // main
# include <stdlib.h> // malloc free
# include <unistd.h> // read

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif