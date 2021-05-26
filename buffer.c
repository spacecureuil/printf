/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:50:43 by pmaury            #+#    #+#             */
/*   Updated: 2021/05/26 18:01:59 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	add_to_buff(t_printf_env *printf_env, char *str, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		if (printf_env->buff_pos == BUFFER_SIZE)
			ft_flush(printf_env);
		printf_env->buff[printf_env->buff_pos] = str[i];
		printf_env->buff_pos++;
		i++;
	}
	printf_env->total_length += size;
}

void	ft_flush(t_printf_env *printf_env)
{
	write(1, printf_env->buff, printf_env->buff_pos);
	printf_env->buff_pos = 0;
}

void	add_n_to_buff(t_printf_env *printf_env, char c, int n)
{
	while (n--)
		add_to_buff(printf_env, &c, 1);
}
