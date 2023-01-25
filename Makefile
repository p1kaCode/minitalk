NAME = minitalk

NAME_C = client

NAME_S = server

SRCS_S =	main_serv.c

OBJS_S = $(SRCS_S:.c=.o)

SRCS_S_B =	main_serv_bonus.c

OBJS_S_B = $(SRCS_S_B:.c=.o)

SRCS_C =	main_client.c

OBJS_C = $(SRCS_C:.c=.o)

SRCS_C_B =	main_client_bonus.c

OBJS_C_B = $(SRCS_C_B:.c=.o)

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

bonus :	$(OBJS_S_B) $(OBJS_C_B)
	$(CC) $(OBJS_S_B) libftmax/libftmax.a -o $(NAME_S)
	$(CC) $(OBJS_C_B) libftmax/libftmax.a -o $(NAME_C)

clean :
	$(RM) $(OBJS_S) $(OBJS_C) $(OBJS_S_B) $(OBJS_C_B)

fclean : clean
	$(RM) $(NAME_C) $(NAME_S)

re : fclean all

.PHONY : all bonus clean fclean re