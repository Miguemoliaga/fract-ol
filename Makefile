NAME	= fractol
CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

SRCS	=	fractol.c \
			draw_num.c \
			parse.c \
			utils.c


LIBFT	= libft/

MAKE_LIB= make bonus

INCLUDE	= -L${LIBFT} -lft 

OBJS	= ${SRCS:.c=.o}

RM		= rm -rf

OS		:= $(shell uname -s)

ifeq ($(OS), Linux)
	INCLUDE += -static-libasan
	MAKE_LIB = make so
endif

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -Imlx -I${LIBFT} $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${MAKE_LIB} -C ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
		@${RM} ${OBJS} *.dSYM
		(cd libft; make fclean)

fclean:		clean
		@${RM} ${NAME}

bonus: all

re:		fclean all

.PHONY:	clean re fclean bonus all