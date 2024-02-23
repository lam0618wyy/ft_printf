NAME = libftprintf.a 

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_printchar.c \
		ft_printf.c \
		ft_printdigit.c \
		ft_printhex.c \
		ft_printptr.c

OBJ = $(SRC:.c=.o)

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
