# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 16:21:33 by seungjun          #+#    #+#              #
#    Updated: 2024/01/16 19:20:08 by seungjun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_B = checker
LIBFT = libft
LIBFT_AR = libft/libft.a
SRCS = ps_algo_main.c ps_algo_radix.c ps_command.c ps_get_stack.c ps_main.c ps_utils.c ps_utils_lst.c ps_utils_rdx.c
OBJS = $(SRCS:.c=.o)
SRCS_B = psc_main.c ps_get_stack.c ps_command.c ps_utils.c ps_utils_lst.c 
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT) all
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/*.o

bonus : $(NAME_B)
	
$(NAME_B) : $(NAME) $(OBJS_B)
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_B) $(LIBFT)/*.o
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT)

clean :
	make -C $(LIBFT) clean
	rm -f $(OBJS) psc_main.o

fclean :
	make -C $(LIBFT) fclean
	rm -f $(OBJS) psc_main.o
	rm -f $(NAME) $(NAME_B)

re : fclean all

.PHONY : all clean fclean re bonus
