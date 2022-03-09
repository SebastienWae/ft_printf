NAME := test

USER := $(shell whoami)
RM := rm -f

CC := gcc
CFLAGS := -Wall -Wextra -Werror
ifdef MAKE_DEBUG
	CFLAGS := -g3 -fsanitize=address
endif
CPPFLAGS := -I../srcs -I/goinfre/$(USER)/homebrew/include
LDFLAGS :=  -L../srcs -lftprintf -L/goinfre/$(USER)/homebrew/lib -lcriterion

$(NAME): $(OBJS)

run_test: $(NAME)
	./$(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all