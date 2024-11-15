/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:17:31 by agaga             #+#    #+#             */
/*   Updated: 2024/11/15 12:22:13 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, int base, int b)
{
	int		i;
	char	*symb;

	if (b == 1)
		symb = "0123456789";
	else if (b == 6)
		symb = "0123456789abcdef";
	else if (b == 7)
		symb = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr_base(-n, base, b) + 1);
	}
	else if (n < base)
		return (ft_putchar(symb[n]));
	else
	{
		i = ft_putnbr_base(n / base, base, b);
		return (i + ft_putnbr_base(n % base, base, b));
	}
}
