# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melrose <melrose@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 17:25:40 by melrose           #+#    #+#              #
#    Updated: 2025/02/26 18:00:50 by melrose          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc -g
CFLAGS	= -Wall -Wextra -Werror
SRCS	= srcs/ft_atoi.c
HEADERS	= includes/libft.h
OBJS	= ${SRCS:.c=.o}
NAME	= libft

all: ${NAME}

${NAME}: ${OBJS} ${HEADERS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all
