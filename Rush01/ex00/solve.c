/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:32:35 by jlange            #+#    #+#             */
/*   Updated: 2020/11/02 22:23:44 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int					check_pos(t_rush *r, t_pos p)
{
	int oldv;

	oldv = r->fmap[p.y * r->sq_size + p.x];
	r->fmap[p.y * r->sq_size + p.x] = p.val;
	if (check_colup(r, p) && check_coldown(r, p)
		&& check_rowleft(r, p) && check_rowright(r, p)
		&& check_dup(r, p))
		return (1);
	r->fmap[p.y * r->sq_size + p.x] = oldv;
	return (0);
}

static inline int	next_pos(t_rush *r, t_pos p)
{
	if (p.x < r->sq_size - 1)
		return (ft_solve(r, (t_pos){ p.x + 1, p.y, 1 }));
	else if (p.y < r->sq_size - 1)
		return (ft_solve(r, (t_pos){ 0, p.y + 1, 1 }));
	return (0);
}

int					ft_solve(t_rush *r, t_pos p)
{
	if (r->fmap[p.y * r->sq_size + p.x])
		return (next_pos(r, p));
	while (p.val <= r->sq_size)
	{
		if (check_pos(r, p))
		{
			if (!next_pos(r, p))
				return (0);
		}
		p.val++;
	}
	if (p.val > r->sq_size)
	{
		r->fmap[p.y * r->sq_size + p.x] = 0;
		return (1);
	}
	return (0);
}
