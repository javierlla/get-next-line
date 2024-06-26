/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:12:46 by jllarena          #+#    #+#             */
/*   Updated: 2023/12/11 11:49:58 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_gnlcalloc(size_t count, size_t size);
char	*ft_gnlstrchr(const char *s, int c);
char	*ft_gnlstrjoin(char *s1, char const *s2);
size_t	ft_gnlstrlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_gnlstrlcat(char *dst, const char *src, size_t dstsize);

#endif