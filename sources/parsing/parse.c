/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:46:33 by vkostand          #+#    #+#             */
/*   Updated: 2024/12/28 13:42:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 3 functions

#include "parsing.h"

static void	check_name(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		send_error(ARG_ERR);
	len = ft_strlen(argv[1]) - 4;
	if (len <= 0 || ft_strncmp(".cub", argv[1] + len, 4) != 0)
		send_error(FILE_NAME_ERR);
}

static void read_map(t_parse *data, char *file_name)
{
    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
		send_error(FILE_OPEN_ERR);
    
    //...
    close(fd);
    (void)data;
}

void parse(int argc, char **argv)
{
    t_parse data;

    ft_bzero(&data, sizeof(data));
    check_name(argc, argv);
    read_map(&data, argv[1]);
    (void)argc;
    (void)argv;
    (void)data;
}
