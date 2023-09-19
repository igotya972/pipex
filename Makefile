# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dferjul <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 19:01:35 by dams              #+#    #+#              #
#    Updated: 2023/09/19 19:24:20 by dferjul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	pipex.c	\
			utils.c	\
			libft/ft_split.c	\
			libft/ft_strncmp.c	\
			libft/ft_strjoin.c	\
			

OBJ_DIR = obj_o

# Extraire les noms de dossiers à partir de la variable SRCS #
DIR := $(sort $(dir $(SRC)))

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror 

RM	=	rm -rf

NAME	=	pipex

#--Règle pour compiler les fichiers .c en fichiers .o--#
 $(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ 

#---------------------rules---------------------#

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONE : all push_swap.a clean fclean re
