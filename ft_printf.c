/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:17:50 by kalam             #+#    #+#             */
/*   Updated: 2024/02/16 17:09:55 by kalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//return the total length of the print
int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += ft_printchar(format[i]);
		else
		{
			i++;
			len += ft_format(format[i], args);
		}
		i++;
	}
	va_end (args);
	return (len);
}

int	ft_format(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (format == 's')
		len = ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len = ft_printdigit(va_arg(args, int));
	else if (format == 'u')
		len = ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		len = ft_printptr(va_arg(args, unsigned long *));
	else if (format == 'x' || format == 'X')
		len = ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len = ft_printchar('%');
	return (len);
}

int	main(void)
{
	ft_printf("%s", "oioio");
}
