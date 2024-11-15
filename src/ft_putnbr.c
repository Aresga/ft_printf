/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:02:55 by agaga             #+#    #+#             */
/*   Updated: 2024/11/15 18:24:22 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base)
{
	int		i;
	char	*symb;

	symb = "0123456789";
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr(-n, base) + 1);
	}
	if (n < base)
		return (ft_putchar(symb[n]));
	else
	{
		i = ft_putnbr(n / base, base);
		return (i + ft_putnbr(n % base, base));
	}
}
