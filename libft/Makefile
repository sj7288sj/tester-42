# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 14:23:24 by seungjun          #+#    #+#              #
#    Updated: 2024/01/14 17:31:39 by seungjun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS_MAN = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c get_next_line.c get_next_line_utils.c ft_printf.c utils_trans.c
SRCS_BON = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS_MAN = $(SRCS_MAN:.c=.o)
OBJS_BON = $(SRCS_BON:.c=.o)

all : make_man

bonus : make_bon

$(NAME) : all

make_man : $(OBJS_MAN)
	@rm -f make_man
	ar -cru $(NAME) $^
	@touch $@

make_bon : $(OBJS_MAN) $(OBJS_BON)
	@rm -f make_bon
	ar -cru $(NAME) $^
	@touch $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS_MAN) $(OBJS_BON)
	@rm -f make_man make_bon

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
