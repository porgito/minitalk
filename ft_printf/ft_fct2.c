/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:42:11 by porg              #+#    #+#             */
/*   Updated: 2021/11/18 00:26:13 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase(t_print *tab, unsigned int n, char *base);

void	ft_base(t_print *tab, unsigned int n, char c)
{
	if (c == 'x')
		ft_putbase(tab, n, "0123456789abcdef");
	if (c == 'X')
		ft_putbase(tab, n, "0123456789ABCDEF");
}

void	ft_putbase(t_print *tab, unsigned int n, char *base)
{
	if (n >= 16)
		ft_putbase(tab, n / 16, base);
	ft_putchar(tab, base[n % 16]);
}

void	ft_putptr(t_print *tab, unsigned long int n)
{
	ft_putstr(tab, "0x");
	ft_putbase(tab, n, "0123456789abcdef");
}
