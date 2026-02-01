/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:21:20 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 18:58:53 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr(const char *str, size_t len, int fd)
{
	size_t	index;

	index = 0;
	while (str[index] && index < len)
		index++;
	write(fd, str, index);
}
