/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:57:03 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/06/28 15:57:04 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_size(char *tmp, int *size)
{
	size[0] = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	size[1] = ft_atoi(tmp + 1);
}

void	read_plato(char **line)
{
	int i;

	get_size(*line + 8, g_fill.s_plato);
	ft_strdel(line);
	get_next_line(0, line);
	ft_strdel(line);
	g_fill.plato = (char **)malloc(sizeof(char *) * g_fill.s_plato[0]);
	i = 0;
	while (i < g_fill.s_plato[0])
	{
		get_next_line(0, line);
		g_fill.plato[i] = ft_strsub(*line, 4, (size_t)g_fill.s_plato[1]);
		ft_strdel(line);
		i++;
	}
}

void	read_piece(char **line)
{
	int i;

	get_size(*line + 6, g_fill.s_piece);
	ft_strdel(line);
	g_fill.piece = (char **)malloc(sizeof(char *) * g_fill.s_piece[0]);
	i = 0;
	while (i < g_fill.s_piece[0])
	{
		get_next_line(0, line);
		g_fill.piece[i] = *line;
		i++;
	}
}

void	clear_plato_piece(void)
{
	int i;

	i = 0;
	while (i < g_fill.s_plato[0])
	{
		ft_strdel(&g_fill.plato[i]);
		i++;
	}
	free(g_fill.plato);
	g_fill.plato = NULL;
	i = 0;
	while (i < g_fill.s_piece[0])
	{
		ft_strdel(&g_fill.piece[i]);
		i++;
	}
	free(g_fill.piece);
	g_fill.piece = NULL;
}
