# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 15:45:08 by fbouibao          #+#    #+#              #
#    Updated: 2019/12/01 15:45:11 by fbouibao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror

SRC = ft_get_ob.c ft_get_spfr.c ft_itoa.c ft_itoa_16.c ft_itos.c \
ft_printf.c ft_putstr.c ft_strdup.c ft_strlen.c ft_substr.c fts_l_list.c \

NAME = ft_printf.a



O = ft_get_ob.o ft_get_spfr.o ft_itoa.o ft_itoa_16.o ft_itos.o \
ft_printf.o ft_putstr.o ft_strdup.o ft_strlen.o ft_substr.o fts_l_list.o \



all: $(NAME)

$(NAME): 
	$(G) -c $(SRC)
	ar rc $(NAME) $(O)
	ranlib $(NAME)
	

clean: 
	rm -f $(O) $(OB)
fclean: clean
	rm -f $(NAME)
re:	fclean all

