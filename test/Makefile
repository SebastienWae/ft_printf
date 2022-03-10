NAME := test

USER := $(shell whoami)
RM := rm -f

CC := gcc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I../include -I/goinfre/$(USER)/homebrew/include
LDFLAGS :=  -L../ -lftprintf -L/goinfre/$(USER)/homebrew/lib -lcriterion -L../libft -lft

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
ifdef DEBUG
	$(MAKE) -C ../ re
else
	$(MAKE) -C ../
endif
	$(CC) $(OBJS) -o $@ $(CFLAGS) $(LDFLAGS)

run_test: re
	./$(NAME)

debug_test: DEBUG = 1
debug_test: CFLAGS := -g3 -fsanitize=address
debug_test: re
	./$(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
