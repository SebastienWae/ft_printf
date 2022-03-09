NAME := test

USER := $(shell whoami)
RM := rm -f

CC := gcc
CFLAGS := -Wall -Wextra -Werror
ifdef MAKE_DEBUG
	CFLAGS := -g3 -fsanitize=address
endif
CPPFLAGS := -I../include -I/goinfre/$(USER)/homebrew/include
LDFLAGS :=  -L../ -lftprintf -L/goinfre/$(USER)/homebrew/lib -lcriterion

SRCS := test.c
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
ifdef MAKE_DEBUG
	$(MAKE) -C ../ re
else
	$(MAKE) -C ../
endif
	$(CC) $(OBJS) -o $@ $(CFLAGS) $(LDFLAGS)

run_test: $(NAME)
	./$(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ../ fclean
	$(RM) $(NAME)

re: fclean all
	$(MAKE) -C ../ re