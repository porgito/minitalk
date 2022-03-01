/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:52:31 by jlaurent          #+#    #+#             */
/*   Updated: 2022/03/01 17:26:01 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		m;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	m = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(m + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

int	ft_atoi(char *nb)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;

	while (nb[i] >= '0' && nb[i] <= '9')
	{
		nbr = nbr * 10 + (nb[i] - '0');
		i++;
	}
	return (nbr);
}
