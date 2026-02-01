/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:20:43 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 19:11:29 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_str(const char *str, t_flags f)
{
	int		len;
	int		sep;

	len = 0;
	if (str == NULL)
		str = "(null)";
	sep = ft_strlen(str);
	if (f.precision > -1 && f.precision < sep)
		sep = f.precision;
	if (f.minus_flag)
	{
		ft_putstr(str, sep, f.fd);
		len = flag_handler(' ', sep, f.width, f.fd);
	}
	else
	{
		len = flag_handler(' ', sep, f.width, f.fd);
		ft_putstr(str, sep, f.fd);
	}
	return (len);
}
