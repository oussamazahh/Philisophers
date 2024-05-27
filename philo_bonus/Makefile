# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 12:25:39 by ozahidi           #+#    #+#              #
#    Updated: 2024/05/26 19:41:43 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror
#  -fsanitize=thread -g 
NAME = philo_bonus

SRCS = ft_philo_bonus.c check_bonus.c create_table_bonus.c \
		 tools_bonus.c create_data_bonus.c ft_sleep_bonus.c\
		create_treads_bonus.c display_message_bonus.c \
		death_note_bonus.c destroy_mutex_bonus.c

OBJS = ${SRCS:.c=.o}

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

%.o: %.c philo_bonus.h
	@${CC} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	@echo  "${RED}["Building philo_bonus"]${NC}"
	@${CC}  ${CFLAGS} ${OBJS} -o ${NAME}
	@echo  "${GREEN}>>DONE<<${NC}" 
 

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