/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:46:33 by vkostand          #+#    #+#             */
/*   Updated: 2025/01/23 21:45:10 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	read_textures(t_parse *data, int fd)
{
	int		not_empty_line;
	char	*str;
	int		type;
	int		status;

	status = 0;
	not_empty_line = 0;
	while (not_empty_line < 6)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (is_empty_line(str, " \n\t\v"))
		{
			free_and_set_null(str);
			continue ;
		}
		type = check_type(str, data, fd, type, status);
		status = save_textures(data, str, type);
		if (status != SUCCESS)
		{
			decide_error(str, type, status);
			free_and_set_null(str);
			close(fd);
			clean_parsing_data(data);
			exit(1);
		}
		free_and_set_null(str);
		not_empty_line++;
	}
}

void	fill_parse_data_with_null(t_parse *data)
{
	data->ceiling_color = 0;
	data->floor_color = 0;
}

t_parse	parse(int argc, char **argv)
{
	t_parse	data;
	int		fd;

	ft_bzero(&data, sizeof(data));
	check_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		send_error(FILE_OPEN_ERR);
	read_textures(&data, fd);
	read_and_parse_map(&data, fd);
	get_player_position(&data);
	get_map_height_and_width(&data);
	// get_textures_fds(&data);
	return (data);
	clean_parsing_data(&data);
	(void)argc;
	(void)argv;
	(void)data;
}
