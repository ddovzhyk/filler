/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 18:08:27 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/06/28 18:08:28 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	big_map_o(int *point, int *opp)
{
	if (find_way(opp, 70, 0, 2) ||
		find_way(opp, 55, 98, 2) || find_way(opp, 65, 98, 1) ||
		find_way(opp, 60, 20, 2) ||
		find_way(opp, 85, 97, 1) || find_way(opp, 85, 90, 1) ||
		find_way(opp, 85, 83, 1) || find_way(opp, 85, 75, 1) ||
		find_way(opp, 85, 68, 1) || find_way(opp, 85, 61, 1) ||
		find_way(opp, 85, 54, 1) || find_way(opp, 85, 47, 1) ||
		find_way(opp, 85, 40, 1) || find_way(opp, 85, 33, 1) ||
		find_way(opp, 85, 26, 1) || find_way(opp, 85, 19, 1) ||
		find_way(opp, 85, 12, 1) || find_way(opp, 85, 1, 1) ||
		find_way(opp, 50, 70, 2) ||
		find_way(opp, 60, 20, 2) ||
		find_way(opp, 40, 20, 2) ||
		find_way(opp, 20, 20, 2) ||
		find_way(opp, 0, 40, 1) || find_way(opp, 0, 35, 1) ||
		find_way(opp, 0, 30, 1))
		;
	else
	{
		opp[0] = 30;
		opp[1] = 60;
	}
	define_my(point, opp);
}

void	big_map_x(int *point, int *opp)
{
	if (g_fill.my == 'X' && (find_way(opp, 0, 60, 2) ||
			find_way(opp, 0, 50, 2) ||
			find_way(opp, 99, 50, 2) ||
			find_way(opp, 99, 40, 2) ||
			find_way(opp, 15, 0, 2) ||
			find_way(opp, 30, 0, 2) ||
			find_way(opp, 30, 20, 2) ||
			find_way(opp, 70, 98, 2) ||
			find_way(opp, 80, 98, 2) ||
			find_way(opp, 20, 98, 2)))
		;
	else if (g_fill.my == 'X')
	{
		opp[0] = 20;
		opp[1] = 60;
	}
	else
	{
		big_map_o(point, opp);
		return ;
	}
	define_my(point, opp);
}
