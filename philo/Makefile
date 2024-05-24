# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 12:25:39 by ozahidi           #+#    #+#              #
#    Updated: 2024/05/24 11:45:10 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 
#  -g  -fsanitize=address-fsanitize=thread -g 
NAME = philo

SRCS = ft_philo.c check.c create_table.c \
		 tools.c create_data.c ft_sleep.c\
		create_treads.c display_message.c \
		death_note.c destroy_mutex.c

OBJS = ${SRCS:.c=.o}

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

%.o: %.c philo.h
	@${CC} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	@echo  "${RED}[Building philo]${NC}"
	@${CC}  ${CFLAGS} ${OBJS} -o ${NAME}
	@echo  "${GREEN} >>DONE<<${NC}" 
 

clean:
	@echo  "${RED}[Deleting objects]${NC}"
	@rm -rf ${OBJS}
	@echo  "${GREEN} >>DONE<<${NC}" 

fclean: clean
	@echo  "${RED}[Deleting Program]${NC}"
	@rm -rf ${NAME}
	@echo  "${GREEN} >>DONE<<${NC}" 

re: fclean all

.PHONY : all clean fclean re