/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:29:56 by vkostand          #+#    #+#             */
/*   Updated: 2025/01/23 21:40:22 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	write_type(t_type type)
{
	if (type == NORTH)
		ft_putstr_fd("NO", STDERR_FILENO);
	else if (type == WEST)
		ft_putstr_fd("WE", STDERR_FILENO);
	else if (type == SOUTH)
		ft_putstr_fd("SO", STDERR_FILENO);
	else if (type == EAST)
		ft_putstr_fd("EA", STDERR_FILENO);
	else if (type == FLOOR)
		ft_putstr_fd("F", STDERR_FILENO);
	else if (type == CEILING)
		ft_putstr_fd("C", STDERR_FILENO);
}

void	write_key(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
}

t_type	check_type(char *str, t_parse *data, int fd, t_type type, int status)
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
	decide_error(str, type, status);
	clean_parsing_data(data);
	close(fd);
	free_and_set_null(str);
	exit(1);
	return (NOT_VALID);
}
