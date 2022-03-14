USER := $(shell whoami)
UNAME_S := $(shell uname -s)
RM := rm -f

CC := gcc
CFLAGS = -g3 -fsanitize=address -Wall -Werror -Wextra
CPPFLAGS := -I../include -I/goinfre/$(USER)/homebrew/include
LDFLAGS :=  -L../debug -lftprintf -L/goinfre/$(USER)/homebrew/lib -lcmocka
ifeq ($(UNAME_S),Linux)
	LDFLAGS +=  -luuid
endif

TESTS = ft_printf.test
SRCS = $(addsuffix .c,$(TESTS))
OBJS := $(SRCS:.c=.o)

all: $(TESTS)

%: %.c
	$(CC) $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ 
	-./$@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

clean_logs:
	$(RM) test.*.log

re: fclean all

.PHONY: all clean fclean re
