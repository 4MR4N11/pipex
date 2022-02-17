# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 21:23:06 by kel-amra          #+#    #+#              #
#    Updated: 2022/02/17 23:38:18 by kel-amra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	pipex.c\
		parsing.c\
		path.c\
		executing.c\
		error_msg.c\
		ft_split.c\
		ft_strjoin.c\
		ft_strnstr.c\
		ft_strtrim.c\
		ft_substr.c

NAME = pipex

HEADER = pipex.h

OBJECT = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT) $(HEADER)
			make -C ft_printf/
			gcc $(FLAGS) $(OBJECT) ft_printf/libftprintf.a -o $(NAME)

%.o : %.c
			gcc $(FLAGS) -c $<

clean :
			make clean -C ft_printf/
			rm -rf $(OBJECT)

fclean : clean
			make fclean -C ft_printf/
			rm -rf $(NAME)

re : fclean all