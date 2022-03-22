SRC			= 	push_swap.c ft_error.c ft_omplir_argv.c ft_check.c ft_standard.c ft_sort_int_tab.c ft_check_isorder.c ft_short_sort.c ft_long_sort.c ft_lst.c ft_3order.c main.c

SRC_DIR		=	srcs

SRCS		=	$(addprefix $(SRC_DIR)/,$(SRC))

LIB			=	ft

LIB_DIR		=	libft/

#INCLUDES	=	-Isrcs/push_swap.h

NAME		=	push_swap

OBJS		=	${SRC:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:		${NAME}

$(NAME):
			$(MAKE) -C $(LIB_DIR)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L $(LIB_DIR) -l$(LIB) -I$(LIB_DIR)libft.h
clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C./libft

fclean:		clean
			$(MAKE) fclean -C./libft
			$(RM) $(NAME)

re:			fclean all
