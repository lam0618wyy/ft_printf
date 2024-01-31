/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:28:28 by kalam             #+#    #+#             */
/*   Updated: 2024/01/31 16:34:22 by kalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

// %c & %s
int				ft_printchar(char c);
int				ft_printstr(char *str);

// %d & %i
int				get_num_len(long n);
char	*ft_itoa(int n);
int				ft_printdigit(int n);

// %u
int				ft_printunsigned(unsigned long n);
int				get_unsigned_len(unsigned long n);

// %x & %X
char	hex_to_dec(unsigned long long value, char x_case);
int				get_hex_len(unsigned int n);
int				ft_printhex(unsigned int n, char x_case);

// %p
int				get_ptr_len(uintptr_t n);
char	*ft_pitoa(unsigned long n);
int				ft_printptr(void *n);

int				ft_format(const char format, va_list args);
int				ft_printf(const char *format, ...);

#endif
