/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:35:53 by jlange            #+#    #+#             */
/*   Updated: 2020/11/02 18:17:51 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void		fill_raw_col(t_rush *r, char *vstr, int *tab)
{
	static int	i = 0;
	int			count;

	count = 0;
	while (count < r->sq_size)
	{
		tab[count] = atoui(&vstr[i]);
		i += str_intlen(&vstr[i]);
		i += (vstr[i] == ' ' && vstr[i + 1]) ? 1 : 0;
		++count;
	}
}

int				init_raw_col(t_rush *r, char *vstr)
{
	if (!(r->cu = (int*)malloc(sizeof(int) * r->sq_size)))
		return (1);
	if (!(r->cd = (int*)malloc(sizeof(int) * r->sq_size)))
		return (1);
	if (!(r->rl = (int*)malloc(sizeof(int) * r->sq_size)))
		return (1);
	if (!(r->rr = (int*)malloc(sizeof(int) * r->sq_size)))
		return (1);
	fill_raw_col(r, vstr, r->cu);
	fill_raw_col(r, vstr, r->cd);
	fill_raw_col(r, vstr, r->rl);
	fill_raw_col(r, vstr, r->rr);
	return (0);
}

int				init_final_map(t_rush *r)
{
	int i;
	int area;

	i = 0;
	area = r->sq_size * r->sq_size;
	if (!(r->fmap = (int*)malloc(sizeof(int) * (area))))
		return (1);
	while (i < area)
	{
		r->fmap[i] = 0;
		++i;
	}
	return (0);
}
