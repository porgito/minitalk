# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: porg <porg@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 14:34:11 by porg              #+#    #+#              #
#    Updated: 2022/03/01 17:31:09 by porg             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server.c

CLIENT	= client.c

PRINTF	= ./ft_printf/libftprintf.a

OBJ1	= ${SERVER:.c=.o}

OBJ2	= ${CLIENT:.c=.o}

GCC		= gcc -Wall -Werror -Wextra

RM		= rm -f

NAME1	= server

NAME2	= client

all:		${NAME1} ${NAME2}

${NAME1}:	${OBJ1}
						${GCC} ${SERVER} ${PRINTF} -I. -I./ft_printf -o ${NAME1}

${NAME2}:	${OBJ2}
						${GCC} ${CLIENT} ${PRINTF} -I. -I./ft_printf -o ${NAME2}

clean:
						${RM} ${OBJ1} ${OBJ2}

fclean:		clean
						${RM} ${NAME1} ${NAME2}

re:			fclean all

.PHONY:		all clean fclean re
