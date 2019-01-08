/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:50:23 by judumay           #+#    #+#             */
/*   Updated: 2018/12/17 16:14:10 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_exit(const char *str)
{
	if (str)
		ft_putendl(str);
	exit(1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		code;
	int		len;
	int		i;

//	(void)argv;
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
//		fd = 45241;
		while ((code = get_next_line(fd, &line)) > 0)
		{
			len = ft_strlen(line);
			printf("%d - %d - |%s|\n", code, len, line);
			free(line);
		}
		i++;
	}
	printf("LAST %d - |%s|\n", code, line);
	free(line);
	return (0);
}
