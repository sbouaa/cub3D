/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:03:41 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 19:11:03 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_hex(unsigned long n, char *base, t_flags f, int flag)
{
	int		len;
	int		sep;

	len = 0;
	f.base = base;
	f.flag = flag;
	if (f.flag)
	{
		f.precision = -1;
		f.hash_flag = 1;
		f.zero_flag = 0;
	}
	sep = count_shex(n, f);
	if (f.minus_flag)
	{
		ft_puthex(n, sep, f, 1);
		len = flag_handler(' ', sep, f.width, f.fd);
	}
	else
	{
		len = flag_handler(' ', sep, f.width, f.fd);
		ft_puthex(n, sep, f, 1);
	}
	return (len);
}
