/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:26:13 by jlange            #+#    #+#             */
/*   Updated: 2020/11/02 20:55:16 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		check_colup(t_rush *r, t_pos p)
{
	int view;
	int count;
	int bigger;

	view = r->cu[p.x];
	count = 0;
	bigger = 0;
	p.y = 0;
	if (view == 0)
		return (1);
	while (p.y < r->sq_size)
	{
		if (r->fmap[p.y * r->sq_size + p.x] > bigger)
		{
			++count;
			bigger = r->fmap[p.y * r->sq_size + p.x];
		}
		else if (!r->fmap[p.y * r->sq_size + p.x])
			return (1);
		p.y++;
	}
	return (count == view);
}

int		check_coldown(t_rush *r, t_pos p)
{
	int view;
	int count;
	int bigger;

	view = r->cd[p.x];
	count = 0;
	bigger = 0;
	p.y = r->sq_size - 1;
	if (view == 0)
		return (1);
	while (p.y >= 0)
	{
		if (r->fmap[p.y * r->sq_size + p.x] > bigger)
		{
			++count;
			bigger = r->fmap[p.y * r->sq_size + p.x];
		}
		else if (!r->fmap[p.y * r->sq_size + p.x])
			return (1);
		p.y--;
	}
	return (count == view);
}

int		check_rowleft(t_rush *r, t_pos p)
{
	int view;
	int count;
	int bigger;

	view = r->rl[p.y];
	count = 0;
	bigger = 0;
	p.x = 0;
	if (view == 0)
		return (1);
	while (p.x < r->sq_size)
	{
		if (r->fmap[p.y * r->sq_size + p.x] > bigger)
		{
			++count;
			bigger = r->fmap[p.y * r->sq_size + p.x];
		}
		else if (!r->fmap[p.y * r->sq_size + p.x])
			return (1);
		p.x++;
	}
	return (count == view);
}

int		check_rowright(t_rush *r, t_pos p)
{
	int view;
	int count;
	int bigger;

	view = r->rr[p.y];
	count = 0;
	bigger = 0;
	p.x = r->sq_size - 1;
	if (view == 0)
		return (1);
	while (p.x >= 0)
	{
		if (r->fmap[p.y * r->sq_size + p.x] > bigger)
		{
			++count;
			bigger = r->fmap[p.y * r->sq_size + p.x];
		}
		else if (!r->fmap[p.y * r->sq_size + p.x])
			return (1);
		p.x--;
	}
	return (count == view);
}

int		check_dup(t_rush *r, t_pos p)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < r->sq_size)
	{
		if (r->fmap[p.y * r->sq_size + x] == p.val && p.x != x)
			return (0);
		x++;
	}
	while (y < r->sq_size)
	{
		if (r->fmap[y * r->sq_size + p.x] == p.val && p.y != y)
			return (0);
		y++;
	}
	return (1);
}
