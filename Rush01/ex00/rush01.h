/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:38:33 by jlange            #+#    #+#             */
/*   Updated: 2020/11/02 17:01:24 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

#include <unistd.h>
#include <stdlib.h>
#define MIN_SQ 2
#define MAX_SQ 100

typedef struct	s_rush
{
	int				*cu;
	int				*cd;
	int				*rl;
	int				*rr;
	int				sq_size;
	int				*fmap;
}		t_rush;

typedef struct	s_pos
{
	int x;
	int y;
	int val;
}				t_pos;


int				is_numeric(char c);
int				str_intlen(char *str);
unsigned int	atoui(char *str);
int				find_size_sq(int nb);
int				check_colup(t_rush *r, t_pos p);
int				check_coldown(t_rush *r, t_pos p);
int				check_rowleft(t_rush *r, t_pos p);
int				check_rowright(t_rush *r, t_pos p);
int				check_dup(t_rush *r, t_pos p);
int				ft_solve(t_rush *r, t_pos p);
int				init_raw_col(t_rush *r, char *vstr);
int				init_final_map(t_rush *r);
void			fill_easy_result(t_rush *r);
void			print_map(int *map, int sq_size);

#endif
