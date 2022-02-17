
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 13:57:22 by amoujane          #+#    #+#              #
#    Updated: 2020/12/12 13:02:50 by amoujane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_putchar.c\
		ft_putnbr.c\
		ft_putupperx.c\
		ft_putnbr_unsigned.c\
		ft_putstr.c\
		ft_printf.c\
		ft_byte_len.c\
		ft_putx.c\
		ft_strlen.c\
		ft_strdup.c

NAME = libftprintf.a

HEADER = ft_printf.h

OBJECT = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJECT) $(HEADER)
			ar rcs $(NAME) $(OBJECT)

%.o : %.c
			cc $(FLAGS) -c $<

clean :
			rm -rf $(OBJECT)
			rm -rf $(OBJECTB)

fclean : clean
			rm -rf $(NAME)

re : fclean all
