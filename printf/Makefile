# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dferjul <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 13:05:12 by dferjul           #+#    #+#              #
#    Updated: 2022/12/19 11:10:25 by dferjul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_flags.c \
		ft_printf.c \
		ft_printf_tools.c \
		ft_printf_tools_bis.c \

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -rf

NAME	=	libftprintf.a

#rules

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONE : all libftprintf.a clean fclean re
