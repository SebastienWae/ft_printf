# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:06:03 by swaegene          #+#    #+#              #
#    Updated: 2022/03/13 15:06:06 by swaegene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

RM := rm -f
AR := ar rus

SRC_DIR := ./src
INC_DIR := ./include
LIBFT_DIR := ./libft

CC = gcc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I$(INC_DIR) -I$(LIBFT_DIR)

SRCS := ft_printf.c ft_hex.c ft_print_char.c ft_print_pointer.c \
		ft_print_string.c ft_print_decimal.c ft_print_unsigned.c \
		ft_print_hex.c ft_flags.c
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
