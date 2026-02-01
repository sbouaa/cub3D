/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:03:37 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 19:11:20 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_nbr(long n, t_flags f, int flag)
{
	int		len;
	int		sep;

	len = 0;
	if (flag)
	{
		f.plus_flag = 0;
		f.space_flag = 0;
	}
	sep = count_snbr(n, f);
	if (f.minus_flag)
	{
		ft_putnbr_pf(n, sep, f, 1);
		len = flag_handler(' ', sep, f.width, f.fd);
	}
	else
	{
		len = flag_handler(' ', sep, f.width, f.fd);
		ft_putnbr_pf(n, sep, f, 1);
	}
	return (len);
}
