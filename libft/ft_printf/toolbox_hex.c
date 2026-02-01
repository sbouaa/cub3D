/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:56:50 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 19:12:39 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthex(unsigned long n, int sep, t_flags f, int flag)
{
	if (flag)
	{
		if ((f.hash_flag && n != 0 && !f.flag) || (f.hash_flag && f.flag))
		{
			ft_putstr(&f.base[16], 2, f.fd);
			sep -= 2;
		}
		if (f.precision == 0 && n == 0)
			return ;
		flag_handler('0', count_hex(n), sep, f.fd);
	}
	if (n > 15)
		ft_puthex(n / 16, sep, f, 0);
	ft_putchar_fd(f.base[n % 16], f.fd);
}

int	count_hex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	count_shex(unsigned long n, t_flags f)
{
	int	i;
	int	j;

	i = count_hex(n);
	j = 0;
	if ((f.hash_flag && n != 0 && !f.flag) || (f.hash_flag && f.flag))
		j = 2;
	if (f.precision > i || (f.precision == 0 && n == 0))
		return (f.precision + j);
	if (f.width > i + j && f.zero_flag && f.precision == -1 && !f.minus_flag)
		return (f.width);
	return (i + j);
}
