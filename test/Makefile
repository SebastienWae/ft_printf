NAME := test

USER := $(shell whoami)
RM := rm -f

CC := gcc
CFLAGS := -Wall -Wextra -Werror
ifdef MAKE_DEBUG
	CFLAGS := -g3 -fsanitize=address
endif
CPPFLAGS := -I./include -I/goinfre/$(USER)/homebrew/include
LDFLAGS :=  -L./src -lftprintf -L/goinfre/$(USER)/homebrew/lib -lcriterion

$(NAME): $(OBJS)
	$(MAKE) -C ../srcs

run_test: $(NAME)
	./$(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all