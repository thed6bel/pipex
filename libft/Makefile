# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 09:35:36 by hucorrei          #+#    #+#              #
#    Updated: 2023/01/17 10:55:53 by hucorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_memchr.c \
		  ft_memcpy.c \
		  ft_memset.c \
		  ft_memcmp.c \
		  ft_memmove.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_strmapi.c \
		  ft_itoa.c \
		  ft_split.c \
		  ft_printf.c \
		  ft_printtools.c \
		  ft_printhex.c \
		  ft_printptr.c \
		  ft_numbers.c \
		  ft_lstnew.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_front.c \
		  ft_lstadd_back.c \
		  ft_lstiter.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstmap.c \


OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc
RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}
.o.c:
		${CC} ${CFLAGS} -o  $@ -c  $<

all:	${NAME}


clean:
		${RM} ${OBJS} ${OBJS_B}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re bonus
