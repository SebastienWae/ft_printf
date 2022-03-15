# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seb <seb@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:06:03 by swaegene          #+#    #+#              #
#    Updated: 2022/03/15 22:44:39 by seb              ###   ########.fr        #
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
SRCS = ft_printf.c ft_hex.c ft_convert_char.c ft_convert_pointer.c \
		ft_convert_string.c ft_convert_decimal.c ft_convert_unsigned.c \
		ft_convert_hex.c ft_convert_percent.c ft_flags.c \
		ft_parse_alternate_form.c ft_parse_dot_precision.c \
		ft_parse_left_blank.c ft_parse_minus_padding.c ft_parse_plus_sign.c \
		ft_parse_zero_padding.c ft_string.c
OBJS = $(addprefix $(OUT_DIR),$(SRCS:%.c=%.o))

all: $(NAME)

bonus: all

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

norm:
	-@norminette $(SRC_DIR)
	-@norminette $(INC_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
