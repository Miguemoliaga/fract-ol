NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -c

CFLAGSR = -Wall -Werror -Wextra

FUNCTIONS =	ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strrchr.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strnstr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strtod.c \
			ft_format_hexa.c \
			ft_format_int.c \
			ft_format_string_char.c \
			ft_format_unsigned.c \
			ft_printf.c

FUNCTIONS_B =	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
			
OBJECTS = ${FUNCTIONS:.c=.o}

OBJECTS_B = ${FUNCTIONS_B:.c=.o}

all: ${NAME}

%o: %c
	${CC} ${CFLAGS} $< -o $@

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}

bonus: ${NAME} ${OBJECTS_B}
	ar rc ${NAME} ${OBJECTS_B}

clean: 
	rm -f ${OBJECTS_B}
	rm -f ${OBJECTS} 2> /dev/null

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all re clean fclean bonus