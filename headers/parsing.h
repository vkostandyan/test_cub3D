/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:01:20 by vkostand          #+#    #+#             */
/*   Updated: 2024/12/28 13:33:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "get_next_line.h"
#include "libft.h"

# define ARG_ERR "\033[1;31mInvalid number of arguments\033[0m\n"
# define FILE_NAME_ERR "\033[1;31mInvalid file name\033[0m\n"
# define FILE_OPEN_ERR "\033[1;31mCan't open file\033[0m\n"
# define CHAR_ERR "\033[1;31mInvalid char in the map\033[0m\n"
# define COIN_ERR "\033[1;31mMap must contain at least 1 coin\033[0m\n"
# define PLAYER_ERR "\033[1;31mMap must contain 1 player\033[0m\n"
# define EXIT_ERR "\033[1;31mMap must contain 1 exit\033[0m\n"
# define FD_ERR "\033[1;31mMap must contain 1 exit\033[0m\n"
# define EMPTY_LINE_ERR "\033[1;31mMap must not have empty spaces\033[0m\n"
# define RECTANGLE_ERR "\033[1;31mMap must be rectangular\033[0m\n"
# define WALL_ERR "\033[1;31mMap must be surrounded by walls\033[0m\n"
# define MALLOC_ERR "\033[1;31mMemory allocation failed\033[0m\n"
# define SIZE_ERR "\033[1;31mMap is larger than screen\033[0m\n"

typedef struct s_parse
{
    char		**map;
    char		*north;
	char		*west;
	char		*east;
	char		*south;
    int			ceiling_color;
	int			floor_color;
}               t_parse;

void parse(int argc, char **argv);

//helpers
void	send_error(char *str);

#endif