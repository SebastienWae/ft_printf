USER := $(shell whoami)
UNAME_S := $(shell uname -s)
RM := rm -f

CC := gcc
CFLAGS = -g3 -fsanitize=address
CPPFLAGS := -I../include
LDFLAGS :=  -L../debug -lftprintf -lcmocka
ifeq ($(USER),swaegene)
CPPFLAGS += -I/goinfre/$(USER)/homebrew/include
LDFLAGS += -L/goinfre/$(USER)/homebrew/lib
endif
ifeq ($(UNAME_S),Linux)
	LDFLAGS +=  -luuid
endif

TESTS = ft_printf.test ft_dectohex.test
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
