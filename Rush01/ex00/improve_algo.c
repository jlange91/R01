/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:45:09 by jlange            #+#    #+#             */
/*   Updated: 2020/11/02 20:26:45 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int			get_index1(int i, int opt, int sq_size)
{
	int ret[4];

	if (opt > 3 || opt < 0)
		return (0);
	ret[0] = i;
	ret[1] = (sq_size - 1) * sq_size + i;
	ret[2] = i * sq_size;
	ret[3] = i * sq_size + sq_size - 1;
	return (ret[opt]);
}

static int			get_index2(int i, int j, int opt, int sq_size)
{
	int ret[4];

	if (opt > 3 || opt < 0)
		return (0);
	ret[0] = j * sq_size + i;
	ret[1] = j * sq_size + i;
	ret[2] = i * sq_size + j;
	ret[3] = i * sq_size + j;
	return (ret[opt]);
}

static inline void	fill_colum(t_rush *r, int *v, int opt)
{
	int i;
	int j;
	int stop;

	i = 0;
	stop = (opt % 2) ? -1 : r->sq_size;
	while (i < r->sq_size)
	{
		if (v[i] == 1)
			r->fmap[get_index1(i, opt, r->sq_size)] = r->sq_size;
		if (v[i] == r->sq_size)
		{
			j = (opt % 2) ? r->sq_size - 1 : 0;
			while (j != (stop))
			{
				r->fmap[get_index2(i, j, opt, r->sq_size)] = (opt % 2)
				? r->sq_size - j : j + 1;
				j += (opt % 2) ? -1 : 1;
			}
		}
		i++;
	}
}

void				fill_easy_result(t_rush *r)
{
	fill_colum(r, r->cu, 0);
	fill_colum(r, r->cd, 1);
	fill_colum(r, r->rl, 2);
	fill_colum(r, r->rr, 3);
}
