/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:49:51 by agaga             #+#    #+#             */
/*   Updated: 2024/11/13 17:36:13 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{
	ft_printf("String is: %s\n", "adbsn");
	ft_printf("Character: %c\n", 'A');
	ft_printf("My Age is %d\n", INT_MIN);
	ft_printf("My Age is %d\n", INT_MAX);
	ft_printf("my char in base16 are %x\n", 52545);
	ft_printf("my char in base16 are %X\n", 52545);
	ft_printf("%%\n");

	printf("\n");
	printf("String is: %s\n", "adbsn");
	printf("Character: %c\n", 'A');
	printf("My Age is %d\n", INT_MIN);
	printf("My Age is %d\n", INT_MAX);
	printf("my char in base16 are %x\n", 52545);
	printf("my char in base16 are %X\n", 52545);
	printf("%%\n");
    return 0;
}
