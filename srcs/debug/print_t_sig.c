/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:31:57 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 10:54:34 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_t_sig_part2(t_sig sig)
{
	if (sig == ERR_NOT_CUB)
		l_printf("ERR_NOT_CUB\n");
	else if (sig == LSIG_COMPLETE)
		l_printf("LSIG_COMPLETE\n");
}

void	print_t_sig(t_sig sig)
{
	if (sig == LSIG_RESOLUTION)
		l_printf("LSIG_RESOLUTION\n");
	else if (sig == LSIG_NPATH)
		l_printf("LSIG_NPATH\n");
	else if (sig == LSIG_SPATH)
		l_printf("LSIG_SPATH\n");
	else if (sig == LSIG_EPATH)
		l_printf("LSIG_EPATH\n");
	else if (sig == LSIG_WPATH)
		l_printf("LSIG_WPATH\n");
	else if (sig == LSIG_SPRITE_PATH)
		l_printf("LSIG_SPRITE_PATH\n");
	else if (sig == LSIG_FLOOR_CLR)
		l_printf("LSIG_FLOOR_CLR\n");
	else if (sig == LSIG_CEILING_CLR)
		l_printf("LSIG_CEILING_CLR\n");
	else if (sig == LSIG_MAP)
		l_printf("LSIG_MAP\n");
	else if (sig == LSIG_UNKNOW)
		l_printf("LSIG_UNKNOW\n");
	else if (sig == LSIG_EMPTY)
		l_printf("LSIG_EMPTY\n");
	else
		print_t_sig_part2(sig);
}
