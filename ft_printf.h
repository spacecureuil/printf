/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:32:55 by pmaury            #+#    #+#             */
/*   Updated: 2021/05/26 18:08:49 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stdarg.h>

typedef struct s_printf_env
{
	int		total_length;
	va_list	args;
	char	buff[BUFFER_SIZE];
	int		buff_pos;
}			t_printf_env;

int		ft_printf(const char *format, ...);
/*
	Ajoute une string str de taille size au buffer. 
*/
void	add_to_buff(t_printf_env *printf_env, char *str, int size);
/*
	Vide le buffer sur la sortie standard.
*/
void	ft_flush(t_printf_env *printf_env);
/*
	Ajoute n fois le caractere c au buffer.
*/
void	add_n_to_buff(t_printf_env *printf_env, char c, int n);

#endif
