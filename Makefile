# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seb <seb@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 19:06:03 by swaegene          #+#    #+#              #
#    Updated: 2022/03/16 17:35:12 by seb              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a
MKDIR = mkdir
RM = rm -f
AR = ar rsu
CP = cp
MV = mv
NORM = python3 -m norminette

SRC_DIR = ./src/
B_SRC_DIR = ./bonus_src/
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

HEADERS = ft_printf.h ft_utils.h ft_flags.h ft_parse.h ft_print_convert.h
HEADERS := $(addprefix $(INC_DIR),$(HEADERS))
SRCS = ft_printf.c ft_hex.c ft_flags.c ft_string.c ft_print_char.c \
	ft_print_pointer.c ft_print_string.c ft_print_decimal.c ft_print_int.c \
	ft_print_unsigned.c ft_print_hex.c ft_print_percent.c \
	ft_parse_alternate_form.c ft_parse_dot_precision.c ft_parse_left_blank.c \
	ft_parse_minus_padding.c ft_parse_plus_sign.c ft_parse_zero_padding.c
OBJS = $(addprefix $(OUT_DIR),$(SRCS:%.c=%.o))
B_HEADERS = ft_format_bonus.h
B_HEADERS := $(addprefix $(INC_DIR),$(B_HEADERS))
B_SRCS = ft_printf.c ft_hex.c ft_flags.c ft_format_bonus.c ft_string.c \
	ft_print_char_bonus.c ft_print_pointer_bonus.c ft_print_string_bonus.c \
	ft_print_decimal_bonus.c ft_print_int_bonus.c ft_print_unsigned_bonus.c \
	ft_print_hex_bonus.c ft_print_percent_bonus.c ft_parse_alternate_form.c \
	ft_parse_dot_precision.c ft_parse_left_blank.c ft_parse_minus_padding.c \
	ft_parse_plus_sign.c ft_parse_zero_padding.c
B_OBJS = $(addprefix $(OUT_DIR),$(B_SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(DIRS) $(OBJS) $(LIBFT_DIR)$(LIBFT)
	$(CP) $(LIBFT_DIR)$(LIBFT) $(OUT_DIR)
	$(AR) $(OUT_DIR)$(LIBFT) $(OBJS)
	$(MV) $(OUT_DIR)$(LIBFT) $(NAME)

bonus: $(DIRS) $(B_OBJS) $(LIBFT_DIR)$(LIBFT)
	$(CP) $(LIBFT_DIR)$(LIBFT) $(OUT_DIR)
	$(AR) $(OUT_DIR)$(LIBFT) $(B_OBJS)
	$(MV) $(OUT_DIR)$(LIBFT) $(NAME)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OUT_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) $(B_HEADERS) 
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(DIRS):
	$(MKDIR) "$@"

norm:
	-@$(NORM) $(SRC_DIR)
	-@$(NORM) $(INC_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OUT_DIR)$(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
