USER = $(shell whoami)
UNAME_S = $(shell uname -s)
RM = rm -f

CC = gcc
ifdef MAKE_DEBUG
CFLAGS = -g3 -fsanitize=address
LDFLAGS = -L../debug
else
CFLAGS = -g3
LDFLAGS = -L../
endif
CPPFLAGS = -I../include
LDFLAGS += -lftprintf -lcmocka
ifeq ($(USER),swaegene)
CPPFLAGS += -I/goinfre/$(USER)/homebrew/include
LDFLAGS += -L/goinfre/$(USER)/homebrew/lib
endif
ifeq ($(UNAME_S),Linux)
	LDFLAGS +=  -luuid
endif

TESTS = ft_printf.test ft_printf_bonus.test
SRCS = $(addsuffix .c,$(TESTS))
OBJS := $(SRCS:.c=.o)

all: $(TESTS)

%: %.c
	$(CC) $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TESTS)

clean_logs:
	$(RM) test.*.log

re: fclean all

.PHONY: all clean fclean re
