# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:04:31 by lenakach          #+#    #+#              #
#    Updated: 2025/07/06 17:40:03 by lenakach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nom de l'exec
NAME = push_swap
NAME_BONUS = checker

#Compilateur et flags
CC = cc
FLAGS = -Wall -Wextra -Werror -ggdb
#Push_swap mandatory

#Fichiers sources
OPES_DIR = opes
LIBFT_DIR = libft
UTILS_DIR = utils
ALGO_DIR = algo

OPES = $(OPES_DIR)/opes_swap.c $(OPES_DIR)/opes_push.c $(OPES_DIR)/opes_rotate.c \
		$(OPES_DIR)/opes_revrotate.c

LIBFT = $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strlen.c \
		$(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_swap.c

UTILS = $(UTILS_DIR)/arguments.c $(UTILS_DIR)/get_tab.c $(UTILS_DIR)/quick_sort.c \
		$(UTILS_DIR)/lst.c $(UTILS_DIR)/init_stack.c $(UTILS_DIR)/print.c \
		$(UTILS_DIR)/free.c

ALGO = $(ALGO_DIR)/algo_start.c $(ALGO_DIR)/algo_small.c \
		$(ALGO_DIR)/algo_utils.c $(ALGO_DIR)/algo.c $(ALGO_DIR)/algo_cost_to_B.c \
		$(ALGO_DIR)/algo_cost_to_A.c $(ALGO_DIR)/algo_cost_A.c $(ALGO_DIR)/algo_cost_B.c \
		$(ALGO_DIR)/algo_utils2.c

SRCS = $(ALGO) $(OPES) $(LIBFT) $(UTILS) push_swap.c
OBJS = $(SRCS:.c=.o)

#Checker

BONUS_DIR = bonus
UTILS_BONUS_DIR = ./bonus/utils_checker
OPES_BONUS_DIR = ./bonus/opes_checker

UTILS_BONUS = $(UTILS_BONUS_DIR)/ft_strcmp.c $(UTILS_BONUS_DIR)/ft_strjoin.c $(UTILS_BONUS_DIR)/arguments.c \
				$(UTILS_BONUS_DIR)/free.c $(UTILS_BONUS_DIR)/ft_strdup.c $(UTILS_BONUS_DIR)/ft_strlen.c \
				$(UTILS_BONUS_DIR)/get_tab.c $(UTILS_BONUS_DIR)/init_stack.c $(UTILS_BONUS_DIR)/lst.c\
				$(UTILS_BONUS_DIR)/ft_atoi.c $(UTILS_BONUS_DIR)/ft_split.c $(UTILS_BONUS_DIR)/quick_sort.c \
				$(UTILS_BONUS_DIR)/ft_swap.c $(UTILS_BONUS_DIR)/print.c
				
OPES_BONUS = $(OPES_BONUS_DIR)/opes_push_bonus.c $(OPES_BONUS_DIR)/opes_revrotate_bonus.c \
			$(OPES_BONUS_DIR)/opes_rotate_bonus.c $(OPES_BONUS_DIR)/opes_swap_bonus.c


SRCS_BONUS = $(UTILS_BONUS) $(OPES_BONUS) $(BONUS_DIR)/checker.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#Commandes
RM = rm -f

#Regles
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(FLAGS) -o $@ $(OBJS_BONUS)

%.o: %.c
	$(CC) $(FLAGS) -I./includes -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re test