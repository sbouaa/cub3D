/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kraoui <kraoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:01:41 by kraoui            #+#    #+#             */
/*   Updated: 2025/07/13 19:08:29 by kraoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	format_sp(const char format, t_flags f, va_list args)
{
	if (format == '%')
		return (ft_print_char('%', f, 1));
	else if (format == 'c')
		return (ft_print_char(va_arg(args, int), f, 0));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *), f));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int), f, 0));
	else if (format == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int), f, 1));
	else if (format == 'x')
		return (ft_print_hex(
				va_arg(args, unsigned int), "0123456789abcdef0x", f, 0));
	else if (format == 'X')
		return (ft_print_hex(
				va_arg(args, unsigned int), "0123456789ABCDEF0X", f, 0));
	else if (format == 'p')
		return (ft_print_hex(
				va_arg(args, unsigned long), "0123456789abcdef0x", f, 1));
	else
		return (0);
}

static int	flag_sp(const char *init, int *index, va_list args)
{
	t_flags	f;
	int		tmp;

	(*index)++;
	tmp = 0;
	init_flags(&f);
	while (flag_checker(init[*index]) && init[*index + 1])
		flag_filler(init, index, &f);
	if (init[*index])
		tmp = format_sp(init[*index], f, args);
	return (tmp);
}

static void	print_init(const char *init, int *index, int *len)
{
	int	tmp;

	tmp = 0;
	if (*index)
		(*index)++;
	while (init[*index + tmp] && init[*index + tmp] != '%')
		tmp++;
	ft_putstr(&init[*index], tmp, 1);
	(*len) += tmp;
	(*index) += tmp;
}

int	ft_printf(const char *init, ...)
{
	int		len;
	int		index;
	va_list	args;

	len = 0;
	if (0 > write(1, NULL, 0))
		return (-1);
	if (init == NULL)
		return (0);
	index = 0;
	va_start(args, init);
	print_init(init, &index, &len);
	while (init[index] == '%' && init[index + 1])
	{
		len += flag_sp(init, &index, args);
		print_init(init, &index, &len);
	}
	va_end(args);
	return (len);
}
