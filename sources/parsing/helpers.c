/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:29:56 by vkostand          #+#    #+#             */
/*   Updated: 2024/12/29 00:24:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 3 functions

#include "parsing.h"


int	is_empty_line(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i] && char_match(str[i], set))
		i++;
	if (str[i])
		return (0);
	return (1);
}

t_type	check_type(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (EMPTY);
	if (ft_strstr(str + i, "NO"))
		return (NORTH);
	if (ft_strstr(str + i, "SO"))
		return (SOUTH);
	if (ft_strstr(str + i, "WE"))
		return (WEST);
	if (ft_strstr(str + i, "EA"))
		return (EAST);
	if (ft_strstr(str + i, "F"))
		return (FLOOR);
	if (ft_strstr(str + i, "C"))
		return (CEILING);
	return (NOT_VALID);
}

void clean_parsing_data(t_parse *data)
{
    free_array(data->map);
    if(data->north)
    {
        free(data->north);
        data->north = NULL;
    }
    if(data->south)
    {
        free(data->south);
        data->south = NULL;
    }
    if(data->east)
    {
        free(data->east);
        data->east = NULL;
    }
    if(data->west)
    {
        free(data->west);
        data->west = NULL;
    }
}
