# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seb <seb@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:06:03 by swaegene          #+#    #+#              #
#    Updated: 2022/03/14 12:39:21 by seb              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a
MKDIR = mkdir
RM = rm -f
AR = ar rs

SRC_DIR = ./src/
INC_DIR = ./include/
LIBFT_DIR = ./libft/

ifdef MAKE_DEBUG
OUT_DIR = ./debug/
NAME := $(OUT_DIR)$(NAME)
DIRS += $(OUT_DIR)
CFLAGS = -g3 -fsanitize=address
else
OUT_DIR = ./
endif

CC = gcc
CFLAGS += -Wall -Werror -Wextra
CPPFLAGS += -I$(INC_DIR) -I$(LIBFT_DIR)

HEADERS = ft_printf.h
HEADERS := $(addprefix $(INC_DIR),$(HEADERS))
SRCS = ft_printf.c ft_hex.c ft_print_char.c ft_print_pointer.c \
		ft_print_string.c ft_print_decimal.c ft_print_unsigned.c \
		ft_print_hex.c ft_flags.c
OBJS = $(addprefix $(OUT_DIR),$(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(DIRS) $(OBJS) $(LIBFT_DIR)$(LIBFT) $(LIBFT)
	$(AR) $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT):
	cp $(LIBFT_DIR)libft.a $(OUT_DIR)

$(OUT_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(DIRS):
	$(MKDIR) "$@"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
