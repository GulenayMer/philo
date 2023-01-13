# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 17:42:11 by mgulenay          #+#    #+#              #
#    Updated: 2022/07/06 18:58:56 by mgulenay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror -pthread -g -fsanitize=thread 

SRCS 	=	main.c \
			utils.c \
			init.c \
			error_check.c \
			actions.c \
			thread.c \
			routine.c \
			free.c \
			
SRC_OBJS	=	$(SRCS:%.c=%.o)

RM          =	rm -f

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_OBJS) 

all : $(NAME)

clean:
		$(RM) $(SRC_OBJS)

fclean:		clean
				$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re