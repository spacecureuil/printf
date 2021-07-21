/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:27:46 by pmaury            #+#    #+#             */
/*   Updated: 2021/07/21 13:24:18 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

#include <stdio.h>

void	ft_putchar(char c, t_printf_env *printf_env)
{
	write(1, &c, 1);
	printf_env->total_length += 1;
}

void	ft_putstr(char *str, t_printf_env *printf_env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], printf_env);
		i++;
	}
}

int		is_type(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' 
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void	ft_conv(const char c, t_printf_env *printf_env)
{
	if (c == 'c')
		ft_putchar(va_arg(printf_env->args, int), printf_env);
	else if (c == 's')
		ft_putstr(va_arg(printf_env->args, char *), printf_env);
	else if (c == 'p')
		printf("Ceci est un pointeur\n");
	else if (c == 'd')
		printf("Ceci est un chiffre\n");
	else if (c == 'i')
		printf("Ceci est un entier\n");
	else if (c == 'u')
		printf("Ceci est un entier non signe\n");
	else if (c == 'x')
		printf("Ceci est un hexadecimal\n");
	else if (c == 'X')
		printf("Ceci est une \n");
	else if (c == '%')
		printf("Ceci est un pourcentage\n");
}

void	ft_parse(const char *format, t_printf_env *printf_env)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (is_type(format[i]) == 1)
				ft_conv(format[i], printf_env);
			else
				ft_putchar(format[i], printf_env);
		}
		else
			ft_putchar(format[i], printf_env);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_printf_env	printf_env;

	printf_env = (t_printf_env){};	
	va_start(printf_env.args, format);
	ft_parse(format, &printf_env);
	va_end(printf_env.args);
	return (printf_env.total_length);
}

int		main(void)
{
	ft_printf("%s, frite");
	return (0);
}