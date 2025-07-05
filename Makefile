# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:04:31 by lenakach          #+#    #+#              #
#    Updated: 2025/07/05 14:12:50 by lenakach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nom de l'exec
NAME = push_swap

#Compilateur et flags
CC = cc
FLAGS = -Wall -Wextra -Werror -I.

#Fichiers sources
OPES_DIR = opes
OPES = $(OPES_DIR)/opes_swap.c $(OPES_DIR)/opes_push.c $(OPES_DIR)/opes_rotate.c \
		$(OPES_DIR)/opes_revrotate.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strlen.c \
		$(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_swap.c

UTILS_DIR = utils
UTILS = $(UTILS_DIR)/arguments.c $(UTILS_DIR)/get_tab.c $(UTILS_DIR)/quick_sort.c \
		$(UTILS_DIR)/lst.c $(UTILS_DIR)/init_stack.c $(UTILS_DIR)/print.c \
		$(UTILS_DIR)/free.c

ALGO_DIR = algo
ALGO = $(ALGO_DIR)/algo_start.c $(ALGO_DIR)/algo_small.c \
	$(ALGO_DIR)/algo_utils.c $(ALGO_DIR)/algo.c $(ALGO_DIR)/algo_cost_to_B.c \
	$(ALGO_DIR)/algo_cost_to_A.c $(ALGO_DIR)/algo_cost_A.c $(ALGO_DIR)/algo_cost_B.c

SRCS = $(ALGO) $(OPES) $(LIBFT) $(UTILS) push_swap.c

#Fichiers objets
OBJS = $(SRCS:.c=.o)

#Commandes
RM = rm -f

#Regles

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re test