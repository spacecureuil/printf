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

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		is_type(const char c)
{
	int	i;
	const char	*id = "csdiupxX%";

	i = 0;
	while (id[i])
	{
		if (c == id[i])
			return (i);
		i++;
	}
	return (-1);
}

void	ft_parse(const char *format, t_printf_env *printf_env)
{
	int	i;
	int	id;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			id = is_type(format[i]);
			if (id != -1)
				printf_env->tab[id](printf_env);
		}
		else
			add_to_buff(printf_env, (char *)(format + i), 1);
		i++;
	}
}

int		identifier_c(t_printf_env *printf_env)
{
	char	c;

	c = (char)va_arg(printf_env->args, int);
	add_to_buff(printf_env, &c, 1);
	return (1);
}

int		identifier_s(t_printf_env *printf_env)
{
	char	*s;
	int		i;

	i = 6;
	s = va_arg(printf_env->args, char*);
	if (s == NULL)
		add_to_buff(printf_env, "(null)", 6);
	else
	{
		i = ft_strlen(s);
		add_to_buff(printf_env, s, i);
	}
	return (i);
}

void	init_tab(t_printf_env *printf_env)
{
	printf_env->tab[0] = identifier_c;
	printf_env->tab[1] = identifier_s;
}

int	ft_printf(const char *format, ...)
{
	t_printf_env	printf_env;

	printf_env = (t_printf_env){};
	init_tab(&printf_env);
	va_start(printf_env.args, format);
	ft_parse(format, &printf_env);
	va_end(printf_env.args);
	ft_flush(&printf_env);
	return (printf_env.total_length);
}

int		main(void)
{
	ft_printf("%s\n%s\n", "bonjour", 0);
	return (0);
}