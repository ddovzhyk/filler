/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:56:01 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/06/28 15:56:02 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) == 1)
	{
		g_fill.my = (char)((line[10] == '1') ? 'O' : 'X');
		g_fill.opp = (char)((g_fill.my == 'O') ? 'X' : 'O');
		ft_strdel(&line);
	}
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
			read_plato(&line);
		else if (ft_strstr(line, "Piece"))
		{
			read_piece(&line);
			if (func_all() == 0)
			{
				clear_plato_piece();
				return (0);
			}
			clear_plato_piece();
		}
	}
	return (0);
}
