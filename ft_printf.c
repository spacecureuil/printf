/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:27:40 by pmaury            #+#    #+#             */
/*   Updated: 2021/05/26 18:11:59 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_printf_env	printf_env;

	printf_env = (t_printf_env){};
	va_start(printf_env.args, format);
	add_to_buff(&printf_env, (char *)format, ft_strlen(format));
	va_end(printf_env.args);
	ft_flush(&printf_env);
	return (printf_env.total_length);
}
