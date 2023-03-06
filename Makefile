NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

RDLINE_LIB = -lreadline -L${HOME}/.brew/opt/readline/lib
RELINE_INC = -I${HOME}/.brew/opt/readline/include
LIBFT_LIB = ./libft/libft.a
SRCS = main.c \

OBJS = $(SRCS:.c=.o)
INC = -I./inc

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(INC) $(LIBFT_LIB) $(OBJS) $(RDLINE_LIB)

%.c : %.o
	$(CC) $(CFLAGS) $(INC) $(RDLINE_INC) -c $< -o $@

$(LIBFT_LIB) :
	make -C ./libft bonus

clean :
	make -C ./libft fclean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all
