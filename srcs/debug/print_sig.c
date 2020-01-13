/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:31:57 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/13 14:27:31 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_t_sig(t_sig sig)
{
	if (sig == LSIG_RESOLUTION)
		ft_printf("LSIG_RESOLUTION\n");
	else if (sig == LSIG_NPATH)
		ft_printf("LSIG_NPATH\n");
	else if (sig == LSIG_SPATH)
		ft_printf("LSIG_SPATH\n");
	else if (sig == LSIG_EPATH)
		ft_printf("LSIG_EPATH\n");
	else if (sig == LSIG_WPATH)
		ft_printf("LSIG_WPATH\n");
	else if (sig == LSIG_SPRITE_PATH)
		ft_printf("LSIG_SPRITE_PATH\n");
	else if (sig == LSIG_FLOOR_CLR)
		ft_printf("LSIG_FLOOR_CLR\n");
	else if (sig == LSIG_CEILING_CLR)
		ft_printf("LSIG_CEILING_CLR\n");
	else if (sig == LSIG_MAP)
		ft_printf("LSIG_MAP\n");
	else if (sig == LSIG_UNKNOW)
		ft_printf("LSIG_UNKNOW\n");
	else if (sig == LSIG_EMPTY)
		ft_printf("LSIG_EMPTY\n");
}
