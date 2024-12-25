/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimamgmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:24:33 by wimam             #+#    #+#             */
/*   Updated: 2024/12/21 18:17:35 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_nblen(int n)
{
	int	length;

	if (n <= 0)
		length = 1;
	else
		length = 0;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	long	nb;

	nb = n;
	len = ft_nblen(n);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (nb == 0)
		ret[0] = '0';
	while (nb > 0)
	{
		ret[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ret);
}
