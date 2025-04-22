# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melrose <melrose@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 17:25:40 by melrose           #+#    #+#              #
#    Updated: 2025/04/22 00:11:09 by melrose          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard srcs/*.c)
HEADERS	= libft.h
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a

all: ${NAME}

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^
	@echo "libft.a ready"

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

BONUS_SRCS = $(wildcard srcs/*.c)
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

bonus: ${BONUS_OBJS}
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "libft.a with bonus ready"
