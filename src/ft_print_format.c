/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:23:03 by agaga             #+#    #+#             */
/*   Updated: 2024/11/15 17:35:13 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_format(char specifier, va_list ap)
{
	size_t	i;

	i = 0;
	if (specifier == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		i += ft_putnbr_base((long)va_arg(ap, int), 10, 1);
	else if (specifier == 'x')
		i += ft_putnbr_base((long)va_arg(ap, unsigned int), 16, 6);
	else if (specifier == 'X')
		i += ft_putnbr_base((long)va_arg(ap, unsigned int), 16, 7);
	else if (specifier == '%')
		i += ft_putchar('%');
	else if (specifier == 'p')
		i += ft_putptr(va_arg(ap, void *));
	else if (specifier == 'u')
		i += ft_putnbr_u(va_arg(ap, unsigned int));
	else
	//	i += ft_putchar(specifier);
		i += write(1, &specifier, 1);
	return (i); 
}
