#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 09:58:36 by lleodev           #+#    #+#              #
#    Updated: 2024/12/30 18:48:33 by lleodev          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -g
INCLUDES = -I./includes

SRC =	./src/philo.c	\
		./src/handle_input.c	\
		./src/utils.c			\
		./src/validation.c		\
		./src/create.c			\
		./src/behavior.c		\
		./src/handle_free.c		\
		./src/timestamp.c		\
		./src/init.c

OBJ = $(SRC:./src/%.c=obj/%.o)

################################COLORS######################################

WHITE_TEXT = \033[1;37m
GREEN_TEXT = \033[1;32m
RED_TEXT = \033[1;31m
ORANGE_TEXT = \033[1;33m
BLUE_TEXT = \033[1;34m
GREEN_BG = \033[42m
RED_BG = \033[41m
ORANGE_BG = \033[43m
BLUE_BG = \033[44m
RESET = \033[0m
date= date

all: $(NAME)
	make lleodev_header
	@echo "$(GREEN_TEXT)>_ Project ready! $(RESET)"
	@echo "$(ORANGE_TEXT)>_ $(NAME) is now avaliable try run ./$(NAME) n_philo t_die t_eat t_sleep n_times_philo_eat(optional)$(RESET)"

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	make lleodev_header
	@echo "$(GREEN_BG)All libs Compiled! $(RESET)"

obj/%.o: src/%.c
	clear
	@mkdir -p $(dir $@)
	make lleodev_header
	@echo "$(BLUE_BG)compiling $(NAME) sources...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: lleodev_header
	@rm -rf ./obj
	make lleodev_header
	@echo "$(RED_BG)All objects cleaned! $(RESET)"
fclean: clean lleodev_header
	@rm -rf $(NAME)
	make lleodev_header
	@echo "$(RED_BG)Project cleaned! $(RESET)"

norm_lleodev:
	@norminette ./src	\
	./includes

lleodev_header:
	@clear
	@echo "$(RED_TEXT)>_ In search of incrible!$(RESET)🎓"
	@echo "$(GREEN_BG)$(WHITE_TEXT)>_Wellcome$(RESET)👋"
	@echo "$(GREEN_TEXT)"
	@echo " ___	  "	" ___	     "	" ________ "	"  _______    " "_______     "		" ________ "	"  ___     _____"
	@echo "/__/|	  "	"/__/|     "	"/_______/|"	" / 	   \ "	"/_______ \  "	    "/_______/|"	" /___/\    \____\ "
	@echo "|  ||	  "	"|  ||     "	"|  ||___/  "	"| \____/ |"	"|  ||    \ \ "  "|  ||___/  "		"\   \ \  /   / /"
	@echo "|  ||	  "	"|  ||     "	"|  ||___   "	"| /    \ |"	"|  ||    | | "  "|  ||___   "		" \   \ \/   / /"
	@echo "|  ||	  "	"|  ||     "	"|  |/___/  "	"| |    | |"	"|  ||    | | "  "|  |/___/  "		"  \   \/   / /"
	@echo "|  ||____ "	"|  ||____ "	"|  ||____  "	"| |    | |"	"|  ||    | | "  "|  ||____  "		"   \   \  / /"
	@echo "|  |/___/|"	"|  |/___/|"	"|  ||___/| "	"| \___/  |"	"|  ||   /  / "  "|  ||___/| "		"    \   \/ /"
	@echo "|_______|/"	"|_______|/"	"|_______|/ "	"\_______/ "	"|__||__/_ /  "	   "|_______|/ "	"     \__/\/ "
	@echo "$(RESET)"
	@echo "$(BLUE_TEXT)Makefile created by lleodev $(RESET)"
	@echo "$(BLUE_TEXT)" && date
	@echo "$(RESET)"


re: fclean all
