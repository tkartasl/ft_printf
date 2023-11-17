#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:28:56 by tkartasl          #+#    #+#              #
#    Updated: 2023/11/17 13:22:27 by tkartasl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libftprintf.a

MAKE = make 

SRCS = ft_printf.c \
		ft_putnbr.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_write_fail_test.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

${OBJS}: ${SRCS}
	cc ${FLAGS} -c ${SRCS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all