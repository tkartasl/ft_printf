#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:28:56 by tkartasl          #+#    #+#              #
#    Updated: 2023/11/16 15:22:35 by tkartasl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libftprintf.a

LIBFTDIR = ../Libft

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
	@${MAKE} all bonus -C ${LIBFTDIR}
	ar -rcs ${NAME} ${OBJS}

${OBJS}: ${SRCS}
	cc ${FLAGS} -c ${SRCS}

clean:
	rm -f ${OBJS}
	${MAKE} clean -C ${LIBFTDIR} 

fclean: clean
	rm -f ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re: fclean all