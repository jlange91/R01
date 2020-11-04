/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:13:14 by jlange            #+#    #+#             */
/*   Updated: 2020/11/02 18:13:16 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int maxlen)
{
	char c;

	if (nb / 10)
		ft_putnbr(nb / 10, maxlen);
	c = nb % 10 + 48;
	ft_putchar(c);
}

void	print_map(int *map, int sq_size)
{
	int i;
	int size;

	i = 0;
	size = sq_size * sq_size;
	while (i < size)
	{
		ft_putnbr(map[i], sq_size);
		ft_putchar(((i + 1) % sq_size) ? ' ' : '\n');
		++i;
	}
}
