# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 17:53:42 by adrocha-          #+#    #+#              #
#    Updated: 2025/08/29 18:06:39 by adrocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS_DIR = srcs

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
SRCS_PRINTF = ft_printf/ft_printf.c \
              ft_printf/ft_put_hexa.c \
              ft_printf/ft_put_ptr.c \
              ft_printf/ft_put_unsigned.c \
              ft_printf/ft_putchar.c \
              ft_printf/ft_putnbr.c \
              ft_printf/ft_putstr.c

SRCS_CLIENT_FULL = $(addprefix $(SRCS_DIR)/, $(SRCS_CLIENT))
SRCS_SERVER_FULL = $(addprefix $(SRCS_DIR)/, $(SRCS_SERVER))
SRCS_PRINTF_FULL = $(addprefix $(SRCS_DIR)/, $(SRCS_PRINTF))

OBJ_DIR = obj
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/, $(SRCS_CLIENT:.c=.o))
OBJ_SERVER = $(addprefix $(OBJ_DIR)/, $(SRCS_SERVER:.c=.o))
OBJ_PRINTF = $(addprefix $(OBJ_DIR)/, $(SRCS_PRINTF:.c=.o))

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_PRINTF)
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_PRINTF)
	@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/ft_printf

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_PRINTF)

fclean: clean
	@$(RM) -r $(NAME_SERVER) $(NAME_CLIENT) $(OBJ_DIR)

re: fclean all

s:
	make re && clear && ./server

.PHONY: all clean fclean re s
