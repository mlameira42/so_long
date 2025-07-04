/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:28:51 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/08 10:42:30 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		size;
	char		*hld;

	size = 1;
	hld = NULL;
	while ((fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0) && size > 0)
	{
		if (buff[0])
		{
			hld = get_lines(hld, buff, '\n');
			if (!hld)
				return (NULL);
			if (hld[ft_findchr(hld, '\n') - 1] == '\n')
				break ;
		}
		else
		{
			size = read(fd, buff, BUFFER_SIZE);
			if (size < 0)
				return (free(hld), NULL);
			buff[size] = '\0';
		}
	}
	return (hld);
}

/*
#include <fcntl.h>

int	main(int argc, char const *argv[])
{
	int		fd;
	int		i;
	int		msize;
	char	*hld;
	char	*map;

	
	msize = 0;
	if (argc == 2)
	{
	fd = open(argv[1], O_RDONLY);
		while (hld = get_next_line(fd))
		{
			i = 0; 
			printf("d=%s\n", hld);
			free(hld);
		}
		map[++msize] = '\0';
		
	close(fd);
	}
	return (0);
}
*/
