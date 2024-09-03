/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:22:08 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/02 13:16:32 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

void	if_newline_pos(char **newline_pos, char **line, char **remainder)
{
	char	*tmp;

	**newline_pos = '\0';
	*line = ft_strdup(*remainder);
	tmp = ft_strdup(*newline_pos + 1);
	free(*remainder);
	*remainder = tmp;
	*line = ft_strjoin(*line, "\n");
}

int	main_while(int fd, char **newline_pos, char **remainder)
{
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	*newline_pos = ft_strchr(*remainder, '\n');
	while (!*newline_pos)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		buffer[bytes_read] = '\0';
		*remainder = ft_strjoin(*remainder, buffer);
		*newline_pos = ft_strchr(*remainder, '\n');
		if (bytes_read == 0)
			break ;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;
	char		*newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	newline_pos = NULL;
	if (main_while(fd, &newline_pos, &remainder))
		return (NULL);
	if (newline_pos)
		if_newline_pos(&newline_pos, &line, &remainder);
	else if (remainder && *remainder)
		line = ft_strdup(remainder);
	if (!newline_pos)
	{
		free(remainder);
		remainder = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char *str;
// 	int	i = 0;

// 	fd = open("texte.txt", O_RDONLY);
// 	str = "";
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// }