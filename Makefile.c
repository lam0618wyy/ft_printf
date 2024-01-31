/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:52:57 by kalam             #+#    #+#             */
/*   Updated: 2024/01/31 17:01:47 by kalam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = libftprintf.a 
// declare the name of the product of this make file

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = \
		ft_printchar.c \
		ft_printf.c \
		ft_printdigit.c \
		ft_printhex.c \
		ft_printptr.c
//declare the variable called SRC, by calling all the .c files using wildcard

OBJ = $(SRC:.c=.o)
//declare the variable called OBJ,
//by calling the SRC which declare in the previous step, and substitute the .c to .o,
//making the empty .o file for the next step

all: $(NAME)

$(NAME) :$(OBJ) #build the libft.a, by linking the OBJ to NAME
		ar rcs $@ $^

%.o : %.c #compole the .c file to .o source code, with the flags
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re #tell the Makefile clean is not a actually file, but still need to be run
clean: #clean the OBJ file
		rm -f $(OBJ)

fclean: clean #clean the library and also call the clean command (which can clean the OBJ)
		rm -f $(NAME)

re: fclean all #rebuild + fclean(clean) + run all
