/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:12:46 by jllarena          #+#    #+#             */
/*   Updated: 2023/12/08 11:03:56 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


char	*get_next_line(int fd);
void	*ft_GNLcalloc(size_t count, size_t size);
char	*ft_GNLstrchr(const char *s, int c);
char	*ft_GNLstrjoin(char *s1, char const *s2);
size_t	ft_GNLstrlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_GNLstrlcat(char *dst, const char *src, size_t dstsize);

#endif