/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:50:06 by agaga             #+#    #+#             */
/*   Updated: 2024/11/13 18:30:13 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int c)
{
    return (write(1, &c, 1));
}
static int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return i;
}

static int ft_putnbr_base(long n, int base, int b)
{
	int i;
	char *symb;

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
static int ft_putptr(unsigned long ptr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_putnbr_base(ptr, 16, 1);
	return (i);
}
static int ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putnbr_u(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

static char	ft_print_format(char specifier, va_list ap)
{
	int i;

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
		i += ft_putptr((unsigned long)va_arg(ap, void *));
	else if (specifier == 'u')
		i += ft_putnbr_u(va_arg(ap, unsigned int));
	else
		i += write(1, &specifier, 1);
	return (i); 
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return count;
}
