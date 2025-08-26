# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 17:53:42 by adrocha-          #+#    #+#              #
#    Updated: 2025/08/26 20:29:10 by adrocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client 

CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
RM = rm -f

SRCS_DIR = srcs

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_CLIENT), $(SRCS_SERVER))

OBJ_DIR = obj
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/, $(SRCS_CLIENT:.c=.o))
OBJ_SERVER = $(addprefix $(OBJ_DIR)/, $(SRCS_SERVER:.c=.o))

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	@$(RM) -r $(NAME_SERVER) $(NAME_CLIENT) $(OBJ_DIR)

re: fclean all

s:
	make re && clear && ./server
	
.PHONY: all clean fclean re