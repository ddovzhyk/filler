/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:57:38 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/06/28 15:57:40 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_zone(int x, int y)
{
	int		n;
	int		i;
	int		j;

	n = 0;
	i = 0;
	while (i < g_fill.s_piece[0])
	{
		j = 0;
		while (j < g_fill.s_piece[1])
		{
			if (g_fill.piece[i][j] == '*' &&
					g_fill.plato[x + i][y + j] == g_fill.my)
				n++;
			if ((g_fill.piece[i][j] == '*' &&
					g_fill.plato[x + i][y + j] == g_fill.opp) || n > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (n);
}

int		compare_dist(int x, int y, int *opp, int *distance)
{
	int i;
	int j;

	i = (opp[0] - x < 0) ? -(opp[0] - x) : opp[0] - x;
	j = (opp[1] - y < 0) ? -(opp[1] - y) : opp[1] - y;
	if (*distance == -1 || (i + j < *distance))
	{
		*distance = i + j;
		return (1);
	}
	else
		return (0);
}

int		check_area(int x, int m_x, int y, int m_y)
{
	int i;
	int j;

	i = x;
	while (i <= m_x)
	{
		j = y;
		while (j <= m_y)
		{
			if (g_fill.plato[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	define_my(int *point, int *opp)
{
	int i;
	int j;

	point[0] = -1;
	point[1] = -1;
	point[2] = -1;
	i = 0;
	while (i <= g_fill.s_plato[0] - g_fill.s_piece[0])
	{
		j = 0;
		while (j <= g_fill.s_plato[1] - g_fill.s_piece[1])
		{
			if (check_zone(i, j) && compare_dist(i, j, opp, point + 2))
			{
				point[0] = i;
				point[1] = j;
			}
			j++;
		}
		i++;
	}
}

int		find_way(int *opp, int x, int y, int m)
{
	if (check_area((x - m < 0) ? 0 : x - m,
					(x + m > g_fill.s_plato[0] - 1) ?
						g_fill.s_plato[0] - 1 : x + m,
					(y - m < 0) ? 0 : y - m,
						(y + m > g_fill.s_plato[1] - 1) ?
					g_fill.s_plato[1] - 1 : y + m))
	{
		opp[0] = x;
		opp[1] = y;
		return (1);
	}
	return (0);
}
