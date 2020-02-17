/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:56:27 by jecaudal          #+#    #+#             */
/*   Updated: 2020/02/17 13:03:11 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

/*
** header error messages
*/
# define ERR_MSG_HEAD_MISS "Information(s) is missing in header.\n"
# define ERR_MSG_HEAD_UNKNO "This line contain unknow information.\n"
# define ERR_MSG_NOT_CUB "This program can't take other file than *.cub.\n"
# define ERR_MSG_MALLOC "Memory allocation error encountered.\n"
# define ERR_MSG_DUPED "Same informations type is duplicated in your file.\n"

# define ERR_MSG_CLR_FORMAT "The correct format is [C ]|[F ][R],[G],[B].\n"
# define ERR_MSG_CLR_VALUE "The value of colors must be between 0 and 255.\n"

# define ERR_MSG_RES_FORMAT "The correct format is [R ][x][' '][y].\n"
# define ERR_MSG_RES_VALUE_X "The value of x must be higher than 0.\n"
# define ERR_MSG_RES_VALUE_Y "The value of y must be higher than 0.\n"

/*
** Map error messages
*/
# define ERR_MSG_MAP_HOLE "Your map is not surrounded by walls.\n"
# define ERR_MSG_MAP_PLAY404 "Player not found."
# define ERR_MSG_MAP_PLAYDUP "Your map contain two players or more.\n"

#endif
