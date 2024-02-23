/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:24:55 by kalam             #+#    #+#             */
/*   Updated: 2024/02/02 12:16:57 by kalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*array;
	long	num;

	num = n;
	len = get_num_len(num);
	array = malloc(sizeof(char) * (len + 1));
	if (array == NULL)
		return (NULL);
	array[len] = '\0';
	len--;
	if (num == 0)
		array[0] = '0';
	if (num < 0)
	{
		array[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		array[len] = (num % 10) + 48;
		num = num / 10;
		len--;
	}
	return (array);
}

int	ft_printdigit(int n)
{
	char	*nbrstr;
	int		len;

	len = 0;
	nbrstr = ft_itoa(n);
	len = ft_printstr(nbrstr);
	free(nbrstr);
	return (len);
}

int	ft_printunsigned(unsigned long n)
{
	int		len;
	char	*array;
	long	num;

	num = n;
	len = get_num_len(num);
	array = malloc(sizeof(char) * (len + 1));
	if (array == NULL)
		return (0);
	array[len] = '\0';
	len--;
	if (num == 0)
		array[0] = '0';
	while (num > 0)
	{
		array[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	len = ft_printstr(array);
	free(array);
	return (len);
}
