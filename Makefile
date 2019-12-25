# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 15:45:08 by fbouibao          #+#    #+#              #
#    Updated: 2019/12/25 22:25:36 by fbouibao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror

SRC = c_hundler.c	ft_atoi.c	ft_get_spfr.c	ft_itoa.c	ft_itoa_long16.c	ft_memset.c	\
	ft_putstr.c	ft_strlen.c	ft_toupper.c	hundlers_utils.c	p_hundler.c	s_hundler.c	\
	utils_nbrs.c	x_hundler.c	d_hundler.c	ft_get_ob.c	ft_isdigit.c	ft_itoa_16.c	ft_itos.c	\
	ft_printf.c	ft_strdup.c	ft_substr.c	fts_l_list.c	pct_hundler.c	u_hundler.c	utils_str.c	\
	cut_width.c	cut_prec.c\

NAME = libftprintf.a



O = c_hundler.o	ft_atoi.o	ft_get_spfr.o	ft_itoa.o	ft_itoa_long16.o	ft_memset.o	\
	ft_putstr.o	ft_strlen.o	ft_toupper.o	hundlers_utils.o	p_hundler.o	s_hundler.o	utils_nbrs.o	x_hundler.o	\
	d_hundler.o	ft_get_ob.o	ft_isdigit.o	ft_itoa_16.o	ft_itos.o	ft_printf.o	ft_strdup.o	\
	ft_substr.o	fts_l_list.o	pct_hundler.o	u_hundler.o	utils_str.o cut_width.o cut_prec.o

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
