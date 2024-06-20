NAME = 	libftprintf.a

MY_SOURCES = utilis.c\
			 ft_printf.c  

OBJECTS = $(MY_SOURCES:.c=.o)

COMPILER =cc

CFLAGS = -Wall -Wextra -Werror

INCS = ft_printf.h

RM = rm -f

LIBC = ar rcs

$(NAME): $(OBJECTS) $(INCS)
	$(LIBC) $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean  re .c .o