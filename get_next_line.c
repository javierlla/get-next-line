/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jllarena <jllarena@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:12:10 by jllarena          #+#    #+#             */
/*   Updated: 2023/12/08 11:06:31 by jllarena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*obtain_remaining(char *buffer)
{
	char	*end_of_line;
	size_t	remaining_length;
	char	*remaining;

	if (buffer == NULL)
		return (NULL);
	end_of_line = ft_GNLstrchr(buffer, '\n');
	if (end_of_line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	remaining_length = 0;
	while (end_of_line[remaining_length] != '\0')
		remaining_length++;
	remaining = malloc(sizeof (char) * remaining_length + 1);
	if (remaining == NULL)
	{
		free(buffer);
		return (NULL);
	}
	ft_GNLstrlcpy(remaining, end_of_line + 1, remaining_length);
	free(buffer);
	return (remaining);
}

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_GNLstrjoin(basin_buffer, read_buffer);
	if (basin_buffer)
	{
		free(basin_buffer);
	}
	return (temp);
}

char	*read_from_file(char *basin_buffer, int fd)
{
	char	*cup_buffer;
	int		bytes_read;

	bytes_read = 1;
	cup_buffer = ft_GNLcalloc((BUFFER_SIZE + 1), sizeof(char));
	if (!cup_buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			//printf("123456");
			free (cup_buffer);
			free(basin_buffer);
			basin_buffer = NULL;
			return (basin_buffer);
		}
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);

		if (cup_buffer[0] == '\n')
			break;
	}
	free(cup_buffer);
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = ft_GNLcalloc(1, sizeof(char));
	if (!ft_GNLstrchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
	{
		free(basin_buffer);
		basin_buffer = NULL;
		return (NULL);
	}
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	
	return (line);
}

/*
int main (void)
{
    int fd;
    char *line;
    int count;
    count = 0;
    fd = open("prueba.txt", O_RDONLY);
 
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }
    while(1)
    {
    printf("\n");
    line = get_next_line(fd);
    if(line == NULL)
        break;
    count++;
    printf("line[%d]:%s\n",count, line);
    free(line);
	close(fd);
    line = NULL;
    }
    close(fd);
    if(!line)
    printf("line[%d]:%s\n",count, line);
   // system ("leaks a.out");
    return(0);
}
*/