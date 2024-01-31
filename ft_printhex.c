/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:38:34 by kalam             #+#    #+#             */
/*   Updated: 2024/01/31 16:45:19 by kalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	hex_to_dec(unsigned long long value, char x_case)
{
	char result;

	result = '\0';
	if (value % 16 > 9)
	{
		if (x_case == 'x')
			result = (value % 16) + 87;
		else if (x_case == 'X')
			result = (value % 16) + 55;
	}
	else
		result = (value % 16) + 48;
	return (result);
}

int	ft_printhex(unsigned int n, char x_case)
{
	int	len;
	char	*array;
	long long	num;

	num = n;
	len = get_hex_len(num);
	array = malloc(sizeof(char) * (len + 1));
	if (array == NULL)
		return (0);
	array[len] = '\0';
	len--;
	if (num == 0)
		array[0] = '0';
	while (num > 0)
	{
		array[len] = hex_to_dec(num, x_case);
		num = num / 16;
		len--;
	}
	len = 0;
	len += ft_printstr(array);
	free(array);
	return (len);
}
