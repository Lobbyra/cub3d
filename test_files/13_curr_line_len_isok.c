/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_curr_line_len_isok.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:55:23 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/17 13:25:27 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		last_empty(char *line)
{
	int i;

	i = l_strlen(line) - 1;
	while (line[i] != '0' && line[i] != '2' && i > 0)
		i--;
	return (i);
}

t_bool	curr_line_len_isok(char *prev, char *curr)
{
	if (!prev || !curr)
		return (FALSE);
	if ((int)l_strlen(curr) - 1 < last_empty(prev))
		return (FALSE);
	else if ((int)l_strlen(prev) - 1 < last_empty(curr))
		return (FALSE);
	return (TRUE);
}

int		main(int argc, char **argv)
{
	int	arg;

	if (argc < 2)
	return (0);
	arg = atoi(argv[1]);
	if (arg == 1)
	{
		/*SUPPOSED TRUE*/
		char *prev = "10111001N1010110011";
		char *curr = "10111001N1010110011";
		if (curr_line_len_isok(prev, curr) == FALSE)
			ft_printf("FALSE");
		else
			ft_printf("TRUE");
	}
	else if (arg == 2)
	{
		/*SUPPOSED FALSE*/
		char *prev = "101110010110011";
		char *curr = "10111001N1010110011";
		if (curr_line_len_isok(prev, curr) == FALSE)
			ft_printf("FALSE");
		else
			ft_printf("TRUE");
	}
	else if (arg == 3)
	{
		/*SUPPOSED TRUE*/
		char *prev = "10111100101100011";
		char *curr = "10111001N1010110011";
		if (curr_line_len_isok(prev, curr) == FALSE)
			ft_printf("FALSE");
		else
			ft_printf("TRUE");
	}
	else if (arg == 4)
	{
		/*SUPPOSED TRUE*/
		char *prev = "101110010110001111111111";
		char *curr = "10111001N1010110011";
		if (curr_line_len_isok(prev, curr) == FALSE)
			ft_printf("FALSE");
		else
			ft_printf("TRUE");
	}
	else if (arg == 5)
	{
		/*SUPPOSED FALSE*/
		char *prev = "10111001N1010110011";
		char *curr = "101110010110011";
		if (curr_line_len_isok(prev, curr) == FALSE)
			ft_printf("FALSE");
		else
			ft_printf("TRUE");
	}
	return (0);
}
