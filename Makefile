NAME := libftprintf.a

RM := rm -f
AR := ar rus

CC := gcc
CFLAGS := -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS := -g3 -fsanitize=address
endif
CPPFLAGS := -I./include

SRCS := ./src/ft_printf.c
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all