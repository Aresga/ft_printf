/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:49:42 by agaga             #+#    #+#             */
/*   Updated: 2024/11/15 16:04:24 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
//# include "./libft/libft.h"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
size_t	ft_putstr(const char *str);
int		ft_putnbr_base(long n, int base, int b);
int		ft_putptr(unsigned long ptr);
int		ft_putnbr_u(unsigned int n);
size_t	ft_print_format(char specifier, va_list ap);
size_t	ft_strlen(const char *str);

#endif
