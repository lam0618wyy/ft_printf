/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:21:08 by kalam             #+#    #+#             */
/*   Updated: 2024/01/31 15:24:02 by kalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (ft_printstr("(null)"));
	while (*str)
	{
		len = len + ft_printchar(*str);
		str++;
	}
	return (len);
}
