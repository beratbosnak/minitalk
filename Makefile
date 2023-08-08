# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 03:21:06 by bbosnak           #+#    #+#              #
#    Updated: 2023/08/03 03:21:07 by bbosnak          ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c
SERVER = server.c
CLIENT_NAME = client
SERVER_NAME = server

CLIENT_B = client_bonus.c
SERVER_B = server_bonus.c
CLIENT_B_NAME = client_bonus
SERVER_B_NAME = server_bonus

UTILS = minitalk_utils.c

FLAGS = -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_B_NAME) $(SERVER_B_NAME)

$(CLIENT_NAME):
	gcc $(FLAGS) $(CLIENT) $(UTILS) -o $(CLIENT_NAME)

$(SERVER_NAME):
	gcc $(FLAGS) $(SERVER) $(UTILS) -o $(SERVER_NAME)

$(CLIENT_B_NAME):
	gcc $(FLAGS) $(CLIENT_B) $(UTILS) -o $(CLIENT_B_NAME)

$(SERVER_B_NAME):
	gcc $(FLAGS) $(SERVER_B) $(UTILS) -o $(SERVER_B_NAME)

clean:
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)

fclean: clean
	rm -rf $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_B_NAME) $(SERVER_B_NAME)
re: fclean all

.PHONY: all clean fclean re