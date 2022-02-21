# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 21:46:39 by dselmy            #+#    #+#              #
#    Updated: 2022/02/21 15:15:16 by dselmy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC_DIR = ./

SRCS =	death_thread.c \
		free.c \
		init.c \
		main.c \
		parse.c \
		philo_life.c \
		timer.c \
		utils_atoi.c \
		utils_calloc.c \
		utils_print.c

OBJ = $(SRCS:.c=.o)
DEP = $(SRCS:.c=.d)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		gcc -pthread -o $(NAME) $(CFLAGS) -I$(INC_DIR) $(OBJ) 

%.o:	%.c
		gcc -c $(CFLAGS) -I$(INC_DIR) $< -o $@ -MD

clean:
		rm -f $(OBJ) $(DEP)

fclean: clean
		rm -f $(NAME)
		
re: fclean all

include $(wildcard $(DEP))

.PHONY: all clean fclean re
