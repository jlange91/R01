/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:23:03 by jlange            #+#    #+#             */
/*   Updated: 2020/11/02 23:13:26 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

static int	check_arg(t_rush *r, char *vstr)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (vstr[i])
	{
		if (vstr[i] == '0' && is_numeric(vstr[i + 1]))
			return (1);
		if (!is_numeric(vstr[i]))
			return (1);
		i += str_intlen(&vstr[i]);
		if (vstr[i] != 0 && vstr[i] != ' ')
			return (1);
		i += (vstr[i] == ' ' && vstr[i + 1]) ? 1 : 0;
		++count;
	}
	r->sq_size = find_size_sq(count);
	if (r->sq_size == 0)
		return (1);
	return (0);
}

void		free_struct(t_rush *r)
{
	if (r->cu)
		free(r->cu);
	if (r->cd)
		free(r->cd);
	if (r->cu)
		free(r->rl);
	if (r->cu)
		free(r->rr);
	if (r->fmap)
		free(r->fmap);
}

int			main(int ac, char **av)
{
	t_rush	r;
	t_pos	p;

	r = (t_rush){ NULL, NULL, NULL, NULL, 0, NULL };
	if (ac > 2 || check_arg(&r, av[1])
		|| init_raw_col(&r, av[1]) || init_final_map(&r))
	{
		write(1, "Error\n", 6);
		free_struct(&r);
		return (0);
	}
	fill_easy_result(&r);
	p = (t_pos){ 0, 0, 1 };
	if (!ft_solve(&r, p))
		print_map(r.fmap, r.sq_size);
	else
		write(1, "Error\n", 6);
	free_struct(&r);
	return (0);
}
