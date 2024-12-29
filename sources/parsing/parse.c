/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:46:33 by vkostand          #+#    #+#             */
/*   Updated: 2024/12/29 13:24:37 by marvin           ###   ########.fr       */
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

static void read_file(t_parse *data, char *file_name)
{
    int fd;
    int not_empty_line;
    char *str;
    int type;
    int status;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
		send_error(FILE_OPEN_ERR);
    not_empty_line = 0;
    while(not_empty_line < 6)
    {
        str = get_next_line(fd);
        if(!str)
            break ;
        if(is_empty_line(str, " \n\t\v"))
        {
            free(str);
            str = NULL;
            continue;
        }
        type = check_type(str);
        if(type == NOT_VALID)
        {
            free(str);
            str = NULL;
            break ;
        }
        status = save_textures(data, str, type);
        if(status != SUCCESS)
        {
            decide_error(str, type, status);
            free(str);
            str = NULL;
            close(fd);
            clean_parsing_data(data);
            exit(1);
        }
        free(str);
        str = NULL;
        not_empty_line++;
    }
    close(fd);
    (void)data;
}

void parse(int argc, char **argv)
{
    t_parse data;

    ft_bzero(&data, sizeof(data));
    check_name(argc, argv);
    read_file(&data, argv[1]);
    clean_parsing_data(&data);
    (void)argc;
    (void)argv;
    (void)data;
}
