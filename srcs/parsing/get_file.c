/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:09:26 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 14:28:16 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Return SUCCESS or print an error with errno with it can't open the file.
*/

static t_bool	is_cub(char *path)
{
	t_bool	ret;
	char	*temp;

	ret = FALSE;
	temp = l_strcut(path, l_strlen(path) - 4);
	if (l_strcmp(temp, ".cub") == 0)
		ret = TRUE;
	free(temp);
	return (ret);
}

static t_bool	is_complete(t_file *file)
{
	if (file->raw_res
		&& file->raw_n_path
		&& file->raw_s_path
		&& file->raw_e_path
		&& file->raw_w_path
		&& file->raw_sprite_path
		&& file->raw_floor_color
		&& file->raw_ceiling_color
		&& file->raw_map)
		return (TRUE);
	return (FALSE);
}

static t_err	saving(t_file *file, char *line, t_sig sig)
{
	if (sig == LSIG_RESOLUTION && !(file->raw_res = l_strdup(line)))
		return (ERR_MEMALLOC);
	else if (sig == LSIG_NPATH && !(file->raw_n_path = l_strdup(line)))
		return (ERR_MEMALLOC);
	else if (sig == LSIG_SPATH && !(file->raw_s_path = l_strdup(line)))
		return (ERR_MEMALLOC);
	else if (sig == LSIG_EPATH && !(file->raw_e_path = l_strdup(line)))
		return (ERR_MEMALLOC);
	else if (sig == LSIG_WPATH && !(file->raw_w_path = l_strdup(line)))
		return (ERR_MEMALLOC);
	else if (sig == LSIG_SPRITE_PATH && !(file->raw_sprite_path = l_strdup(line)))
		return (ERR_MEMALLOC);
	else if (sig == LSIG_FLOOR_CLR && !(file->raw_floor_color = l_strdup(line)))
		return (ERR_MEMALLOC);
	else if (sig == LSIG_CEILING_CLR && !(file->raw_ceiling_color = l_strdup(line)))
		return (ERR_MEMALLOC);
	else if (sig == LSIG_MAP && !(file->raw_map = l_strdup(line)))
		return (ERR_MEMALLOC);
	return (SUCCESS);
}

static t_bool	is_saved(t_file *file, t_sig sig)
{
	if (sig == LSIG_RESOLUTION && file->raw_res)
		return (TRUE);
	if (sig == LSIG_NPATH && file->raw_n_path)
		return (TRUE);
	if (sig == LSIG_SPATH && file->raw_s_path)
		return (TRUE);
	if (sig == LSIG_EPATH && file->raw_e_path)
		return (TRUE);
	if (sig == LSIG_WPATH && file->raw_w_path)
		return (TRUE);
	if (sig == LSIG_SPRITE_PATH && file->raw_sprite_path)
		return (TRUE);
	if (sig == LSIG_FLOOR_CLR && file->raw_floor_color)
		return (TRUE);
	if (sig == LSIG_CEILING_CLR && file->raw_ceiling_color)
		return (TRUE);
	if (sig == LSIG_MAP && file->raw_map)
		return (TRUE);
	return (FALSE);
}

t_err	get_file(t_file *file, char *path)
{
	t_sig	sig;
	char	*readed;

	errno = 0;
	if (is_cub(path) == FALSE)
		return (print_err_file(file->curr_line, ERR_NOT_CUB));
	if ((file->fd = open(path, O_RDONLY)) == -1)
		return (print_err_file(file->curr_line, ERR_ERRNO));
	while (get_next_line(file->fd, &readed) > 0)
	{
		file->curr_line++;
		sig = detect_line(readed);
		if (sig == LSIG_UNKNOW)
			return (print_err_file(file->curr_line, ERR_UNKNOW));
		if (is_saved(file, sig) == TRUE)
			return (print_err_file(file->curr_line, ERR_DUPED_INFO));
		else if (sig != LSIG_EMPTY && saving(file, readed, sig) == ERR_MEMALLOC)
				return (print_err_file(file->curr_line, ERR_MEMALLOC));
		if (sig == LSIG_MAP)
			break ;
	}
	if (is_complete(file) == TRUE)
		return (get_map(file));
	return (print_err_file(file->curr_line, ERR_MISSING));
}
