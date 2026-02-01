/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:35:27 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 19:10:40 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_char(char c, t_flags f, int flag)
{
	int		len;
	char	padd;

	len = 1;
	padd = ' ';
	if (flag && f.zero_flag)
		padd = '0';
	if (f.minus_flag)
	{
		ft_putchar_fd(c, f.fd);
		len = flag_handler(' ', len, f.width, f.fd);
	}
	else
	{
		len = flag_handler(padd, len, f.width, f.fd);
		ft_putchar_fd(c, f.fd);
	}
	return (len);
}
