/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:44:58 by kraoui            #+#    #+#             */
/*   Updated: 2025/08/01 16:41:49 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_len(size_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_stoa(size_t num)
{
	int		len;
	char	*str;

	len = ft_get_len(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (ft_puterror(ERR_MALLOC));
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	while (len > 0 && num != 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
