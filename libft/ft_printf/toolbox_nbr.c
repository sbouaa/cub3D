/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:56:50 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 19:13:05 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_pf(long n, int sep, t_flags f, int flag)
{
	if (flag)
	{
		if (f.plus_flag || f.space_flag || n < 0)
		{
			ft_putchar_fd(mid_handler(n, f), f.fd);
			sep--;
		}
		if (f.precision == 0 && n == 0)
			return ;
		if (n < 0)
			n *= -1;
		flag_handler('0', count_nbr(n), sep, f.fd);
	}
	if (n > 9)
		ft_putnbr_pf(n / 10, sep, f, 0);
	ft_putchar_fd((n % 10) + 48, f.fd);
}

int	count_nbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	count_snbr(long n, t_flags f)
{
	int	i;
	int	j;

	i = count_nbr(n);
	j = 0;
	if (f.plus_flag || f.space_flag || n < 0)
		j++;
	if (f.precision > i || (f.precision == 0 && n == 0))
		return (f.precision + j);
	if (f.width > i + j && f.zero_flag && f.precision == -1 && !f.minus_flag)
		return (f.width);
	return (i + j);
}

char	mid_handler(long n, t_flags f)
{
	char	mid;

	if (f.space_flag)
		mid = ' ';
	if (f.plus_flag)
		mid = '+';
	if (n < 0)
		mid = '-';
	return (mid);
}
