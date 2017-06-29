/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovzhik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:51:02 by ddovzhik          #+#    #+#             */
/*   Updated: 2017/06/28 15:51:04 by ddovzhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./libft/ft_printf.h"

typedef struct	s_fill
{
	int		s_plato[2];
	int		s_piece[2];
	char	**plato;
	char	**piece;
	char	my;
	char	opp;
}				t_fill;

t_fill			g_fill;

void			read_plato(char **line);
void			read_piece(char **line);
void			clear_plato_piece(void);

int				find_way(int *opp, int x, int y, int m);
void			define_my(int *point, int *opp);

int				func_all(void);
void			small_map_o(int *point, int *opp);
void			small_map_x(int *point, int *opp);
void			middle_map_o(int *point, int *opp);
void			middle_map_x(int *point, int *opp);
void			big_map_o(int *point, int *opp);
void			big_map_x(int *point, int *opp);

#endif
