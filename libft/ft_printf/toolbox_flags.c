/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:18:07 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 19:04:59 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	flag_handler(char c, int len, int width, int fd)
{
	while (len < width)
	{
		ft_putchar_fd(c, fd);
		len++;
	}
	return (len);
}

void	init_flags(t_flags *f)
{
	f->base = NULL;
	f->flag = 0;
	f->fd = 1;
	f->width = 0;
	f->precision = -1;
	f->minus_flag = 0;
	f->zero_flag = 0;
	f->hash_flag = 0;
	f->space_flag = 0;
	f->plus_flag = 0;
}

int	flag_checker(char flag)
{
	if (flag == '-' || flag == '0' || flag == '#'
		|| flag == ' ' || flag == '+' || flag == '.'
		|| flag == '>' || (flag >= '1' && flag <= '9'))
		return (1);
	return (0);
}

void	flag_filler(const char *flag, int *index, t_flags *f)
{
	if (flag[*index] == '-')
		f->minus_flag = 1;
	if (flag[*index] == '0')
		f->zero_flag = 1;
	if (flag[*index] == '#')
		f->hash_flag = 1;
	if (flag[*index] == ' ')
		f->space_flag = 1;
	if (flag[*index] == '+')
		f->plus_flag = 1;
	if (flag[*index] >= '1' && flag[*index] <= '9')
		f->width = ft_atoi_pf(flag, index);
	if (flag[*index] == '.')
		f->precision = ft_atoi_pf(flag, index);
	if (flag[*index] == '>')
		f->fd = ft_atoi_pf(flag, index);
	(*index)++;
}

int	ft_atoi_pf(const char *str, int *index)
{
	int	result;

	result = 0;
	if (str[*index] == '.' || str[*index] == '>')
		(*index)++;
	while (str[*index] >= '0' && str[*index] <= '9' && str[*index])
	{
		result = result * 10 + str[*index] - 48;
		(*index)++;
	}
	(*index)--;
	return (result);
}
