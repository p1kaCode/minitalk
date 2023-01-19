NAME = minitalk

NAME_C = client

NAME_S = server

SRCS_S =	main_serv.c

OBJS_S = $(SRCS_S:.c=.o)

SRCS_C =	main_client.c

OBJS_C = $(SRCS_C:.c=.o)

HDRS = minitalk.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

%.o : %.c $(HDRS) Makefile
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS_S) $(OBJS_C)
	$(CC) $(OBJS_S) libftmax/libftmax.a -o $(NAME_S)
	$(CC) $(OBJS_C) libftmax/libftmax.a -o $(NAME_C)

clean :
	$(RM) $(OBJS_S) $(OBJS_C)

fclean : clean
	$(RM) $(NAME_C) $(NAME_S)

re : fclean all

.PHONY : all clean fclean re