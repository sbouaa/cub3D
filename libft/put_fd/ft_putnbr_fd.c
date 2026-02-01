/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:08 by kraoui            #+#    #+#             */
/*   Updated: 2025/01/31 16:17:42 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	c;

	if (fd < 0)
		return ;
	c = n;
	if (c < 0)
	{
		ft_putchar_fd('-', fd);
		c *= -1;
	}
	if (c > 9)
		ft_putnbr_fd(c / 10, fd);
	ft_putchar_fd(c + 48, fd);
}
