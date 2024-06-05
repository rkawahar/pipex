# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 16:34:46 by rkawahar          #+#    #+#              #
#    Updated: 2024/06/05 16:47:57 by rkawahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_here_doc.c ft_print_specifier.c ft_printf.c ft_split.c ft_strtrim.c list_utils.c path.c \
		pipex_utils.c pipex.c
NAME = pipex
CC = cc
CFLGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)

%.o : %.c
	$(CC) $(CFLGS) -c $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 