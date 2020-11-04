/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:24:04 by jlange            #+#    #+#             */
/*   Updated: 2020/11/02 22:12:03 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int				is_numeric(char c)
{
	return (c >= 48 && c <= 57);
}

int				str_intlen(char *str)
{
	int i;

	i = 0;
	while (str[i] && is_numeric(str[i]))
		++i;
	return (i);
}

unsigned int	atoui(char *str)
{
	unsigned int	ret;
	int				len;

	ret = 0;
	len = str_intlen(str);
	while (len--)
	{
		ret *= 10;
		ret += (*str - 48);
		str++;
	}
	return (ret);
}

int				find_size_sq(int nb)
{
	int div;

	div = nb / 4;
	return (nb % 4 || div < MIN_SQ || div > MAX_SQ) ? 0 : div;
}
