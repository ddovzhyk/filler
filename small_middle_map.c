/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_middle_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 16:02:47 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/06/28 16:02:48 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		func_all(void)
{
	int point[3];
	int opp[2];

	point[0] = -1;
	point[1] = -1;
	point[2] = -1;
	if (g_fill.s_plato[0] == 15)
		small_map_o(point, opp);
	else if (g_fill.s_plato[0] == 24)
		middle_map_o(point, opp);
	else if (g_fill.s_plato[0] == 100)
		big_map_x(point, opp);
	if (point[0] == -1)
	{
		ft_printf("0 0\n");
		return (0);
	}
	ft_printf("%d %d\n", point[0], point[1]);
	return (1);
}

void	small_map_x(int *point, int *opp)
{
	if (find_way(opp, 12, 16, 1) ||
		find_way(opp, 0, 12, 1) ||
		find_way(opp, 3, 0, 1) ||
		find_way(opp, 12, 0, 1))
		;
	else if (g_fill.plato[11][0] == 'O' || g_fill.plato[11][1] == 'O' ||
				g_fill.plato[12][0] == 'O' || g_fill.plato[12][1] == 'O' ||
				g_fill.plato[13][0] == 'O' || g_fill.plato[13][1] == 'O')
	{
		opp[0] = 14;
		opp[1] = 0;
	}
	else
	{
		opp[0] = 0;
		opp[1] = 16;
	}
	define_my(point, opp);
}

void	small_map_o(int *point, int *opp)
{
	if (g_fill.my == 'O' && (find_way(opp, 0, 16, 1) ||
		find_way(opp, 14, 0, 1)))
		;
	else if (g_fill.my == 'O')
	{
		opp[0] = 14;
		opp[1] = 16;
	}
	else
	{
		small_map_x(point, opp);
		return ;
	}
	define_my(point, opp);
}

void	middle_map_x(int *point, int *opp)
{
	if (find_way(opp, 19, 39, 2) || find_way(opp, 19, 0, 2) ||
		find_way(opp, 16, 0, 1) ||
		((g_fill.plato[10][28] == 'O' || g_fill.plato[10][29] == 'O' ||
		g_fill.plato[10][30] == 'O' || g_fill.plato[11][28] == 'O' ||
		g_fill.plato[11][29] == 'O' || g_fill.plato[11][30] == 'O' ||
		g_fill.plato[12][28] == 'O' || g_fill.plato[12][29] == 'O' ||
		g_fill.plato[12][30] == 'O' || g_fill.plato[13][28] == 'O' ||
		g_fill.plato[13][29] == 'O' || g_fill.plato[13][30] == 'O') &&
		(find_way(opp, 13, 0, 1) ||
		find_way(opp, 15, 35, 1) || find_way(opp, 10, 39, 1) ||
		find_way(opp, 5, 39, 1) || find_way(opp, 1, 38, 2))) ||
		find_way(opp, 9, 22, 1) || find_way(opp, 9, 26, 2) ||
		find_way(opp, 10, 30, 1) || find_way(opp, 10, 34, 1) ||
		find_way(opp, 10, 39, 1) || find_way(opp, 13, 39, 1) ||
		find_way(opp, 0, 39, 2) || find_way(opp, 0, 0, 1) ||
		find_way(opp, 0, 12, 1))
		;
	else
	{
		opp[0] = 2;
		opp[1] = 30;
	}
	define_my(point, opp);
}

void	middle_map_o(int *point, int *opp)
{
	if (g_fill.my == 'O' && (find_way(opp, 0, 27, 3) ||
			find_way(opp, 23, 10, 2) ||
			find_way(opp, 12, 35, 2) ||
			find_way(opp, 23, 1, 2)))
		;
	else if (g_fill.my == 'O')
	{
		opp[0] = 23;
		opp[1] = 39;
	}
	else
	{
		middle_map_x(point, opp);
		return ;
	}
	define_my(point, opp);
}
