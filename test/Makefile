NAME := test

USER := $(shell whoami)
UNAME_S := $(shell uname -s)
RM := rm -f

CC := gcc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I../include -I/goinfre/$(USER)/homebrew/include
LDFLAGS :=  -L../ -lftprintf -L../libft -lft -L/goinfre/$(USER)/homebrew/lib -lcmocka
ifeq ($(UNAME_S),Linux)
	LDFLAGS +=  -luuid
endif

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
