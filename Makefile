# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:06:03 by swaegene          #+#    #+#              #
#    Updated: 2022/03/10 17:52:31 by swaegene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

RM := rm -f
AR := ar rus

SRC_DIR := ./src
INC_DIR := ./include

CC := gcc
CFLAGS := -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS := -g3 -fsanitize=address
endif
CPPFLAGS := -I$(INC_DIR) -I./libft

SRCS := ft_printf.c ft_convert.c
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
