/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:01:20 by vkostand          #+#    #+#             */
/*   Updated: 2024/12/29 00:24:50 by marvin           ###   ########.fr       */
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

typedef enum s_err_type
{
	SUCCESS  = 0,
	MALLOC = -1,
	DOUBLICATE = -2,
	INVALID_KEY = -3,
	TOO_MANY_VALUES = -4,
	TOO_FEW_VALUES = -5
}				t_err_type;

typedef enum s_type
{
	NOT_VALID,
	EMPTY,
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR,
	CEILING
}				t_type;

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
int	is_empty_line(char *str, char *set);
int	char_match(char c, char const *str);
t_type	check_type(char *str);
int save_textures(t_parse *data, char *str, int type);
void clean_parsing_data(t_parse *data);

// array utils
void	*free_array(char **str);
void	print_array(char **str);
int	count_array_len(char **str);

#endif