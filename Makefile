# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:06:03 by swaegene          #+#    #+#              #
#    Updated: 2022/03/12 14:06:38 by swaegene         ###   ########.fr        #
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

SRCS := ft_printf.c ft_hex.c ft_print_char.c ft_print_pointer.c \
		ft_print_string.c ft_print_decimal.c ft_print_unsigned.c \
		ft_print_hex.c
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
ifdef DEBUG
	$(MAKE) -C ./libft re
else
	$(MAKE) -C ./libft
endif
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
