/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:46:10 by kalam             #+#    #+#             */
/*   Updated: 2024/01/31 16:52:16 by kalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_ptr_len(unsigned long n)
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

char	*ft_pitoa(unsigned long n)
{
	int	len;
	char	*array;

	len = get_ptr_len(n);
	array = malloc(sizeof(char) * (len + 1));
	if (array == NULL)
		return (0);
	array[len] = '\0';
	len--;
	if (n == 0)
		array[0] = '0';
	while (n > 0)
	{
		array[len] = hex_to_dec(n, 'x');
		n = n / 16;
		len--;
	}
	return (array);
}

int	ft_printptr(void *n)
{
	unsigned long	num;
	int	len;
	char	*ptrstr;

	num = (unsigned long) n;
	if (!num)
		return (ft_printstr("(nil)"));
	ptrstr = ft_pitoa(num);
	len = 0;
	len = ft_printstr("0x");
	len += ft_printstr(ptrstr);
	free(ptrstr);
	return (len);
}
