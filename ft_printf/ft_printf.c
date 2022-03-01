/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:46:42 by porg              #+#    #+#             */
/*   Updated: 2022/02/15 16:34:30 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->tl = 0;
	return (tab);
}

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	tab->tl += write(1, &a, 1);
}
static void	get_format(t_print *tab, const char *s, int i)
{
	if (s[i] == 'c')
		ft_print_char(tab);
	if (s[i] == 'd' || s[i] == 'i')
		ft_itoa(tab, va_arg(tab->args, int));
	if (s[i] == 's')
		ft_putstr(tab, va_arg(tab->args, char *));
	if (s[i] == 'u')
		ft_putuns(tab, va_arg(tab->args, unsigned int));
	if (s[i] == 'x' || s[i] == 'X')
		ft_base(tab, va_arg(tab->args, unsigned int), s[i]);
	if (s[i] == 'p')
		ft_putptr(tab, (unsigned long int)va_arg(tab->args, void *));
	if (s[i] == '%')
		ft_putchar(tab, '%');
}

int	ft_printf(const char *s, ...)
{
	t_print	*tab;
	int		len;
	int		i;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, s);
	len = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != '%')
			len += write(1, &s[i], 1);
		else
		{
			i++;
			get_format(tab, s, i);
		}
	}
	va_end(tab->args);
	len += tab->tl;
//	printf("%d\n", len);
	free(tab);
	return (len);
}
/*
int	main()
{
	char			s = '8';
	unsigned int	testes = 123;
	char			*str = "test";
	void			*ptr = str;
	ft_printf("saluttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt\n");
}*/
