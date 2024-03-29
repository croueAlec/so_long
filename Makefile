# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroue <acroue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 11:51:52 by acroue            #+#    #+#              #
#    Updated: 2024/01/17 18:56:56 by acroue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = so_long
BONUS = so_long_bonus

# Colors
DEFAULT    = \033[0m
BLACK    = \033[0;30m
RED        = \033[0;31m
GREEN    = \033[0;32m
YELLOW    = \033[0;33m
BLUE    = \033[0;34m
PURPLE    = \033[0;35m
CYAN    = \033[0;36m
BWHITE    = \033[1;37m

# Directories
LIBS_DIR = libs
SRCS_DIR = srcs
INCS_DIR = includes
BONUS_DIR = bonus
OBJS_DIR = objs
LIBFT_DIR = $(LIBS_DIR)/libft
LIBMLX_DIR = $(LIBS_DIR)/minilibx-linux

# Files
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a

define LIB :=
	$(LIBFT)
	$(LIBMLX)
	-lX11
	-lXext
endef
LIB := $(strip $(LIB))

define INCLUDES :=
	$(INCS_DIR)
	$(LIBFT_DIR)/includes
	$(LIBMLX_DIR)
endef
INCLUDES := $(strip $(INCLUDES))

define SRC :=
	error_handling.c
	load_assets.c
	manage_window.c
	map_building.c
	map_check.c
	map_line_check.c
	map_parsing.c
	pates_finding.c
	player_movement.c
	player.c
	put_string.c
	so_long.c
endef
SRC := $(strip $(SRC))

define BONUS_SRC :=
	$(addprefix $(BONUS_DIR)/, enemy_bonus.c \
	error_handling_bonus.c \
	load_assets_bonus.c \
	manage_window_bonus.c \
	map_building_bonus.c \
	map_check_bonus.c \
	map_line_check_bonus.c \
	map_parsing_bonus.c \
	pates_finding_bonus.c \
	player_movement_bonus.c \
	player_bonus.c \
	put_string_bonus.c \
	so_long_bonus.c \
	sprite_animation_bonus.c)
endef
BONUS_SRC := $(strip $(BONUS_SRC))

OBJ := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC))
BONUS_OBJ := $(patsubst %.c,$(OBJS_DIR)/%.o,$(BONUS_SRC))

# Utils
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
INCLUDES_FLAGS := $(addprefix -I , $(INCLUDES))
LIB_FLAGS = --no-print-directory --silent

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)/$(BONUS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAGS) -c $< -o $@

clean:
	@echo "$(RED)! Removing$(DEFAULT) ${OBJS_DIR} files"
	@${RM} ${OBJS_DIR}

fclean: clean
	@echo "$(RED)! Removing$(DEFAULT) $(NAME)"
	@$(RM) $(NAME)
	@echo "$(RED)! Removing$(DEFAULT) $(BONUS)"
	@$(RM) $(BONUS)

re: fclean all

$(LIBFT):
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

$(LIBMLX):
	@echo "$(YELLOW)$(WD) ./$(LIBMLX_DIR)$(DEFAULT)"
	@make -C $(LIBMLX_DIR) $(LIB_FLAGS)
	@echo "$(GREEN)* Assembling $(BWHITE)libmlx_Linux.a$(DEFAULT)"
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

cleanlib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make clean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"
	@echo "$(YELLOW)$(WD) ./$(LIBMLX_DIR)$(DEFAULT)"
	@make clean -C $(LIBMLX_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

fcleanlib:
	@echo "$(YELLOW)$(WD) ./$(LIBFT_DIR)$(DEFAULT)"
	@make fclean -C $(LIBFT_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"
	@echo "$(YELLOW)$(WD) ./$(LIBMLX_DIR)$(DEFAULT)"
	@make clean -C $(LIBMLX_DIR) $(LIB_FLAGS)
	@echo "$(YELLOW)$(WD) ./$(DEFAULT)"

relib: fcleanlib $(LIBFT) $(LIBMLX)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(LIBMLX) $(BONUS_OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB) -o $(BONUS)

cre:
	@clear
	@make re --no-print-directory

norm:
	@norminette $(SRCS_DIR) $(INCS_DIR) $(BONUS_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(PURPLE)Norm O.K.$(DEFAULT)"}'
	@norminette $(LIBFT_DIR) | awk '/'Error'/ {print; found=1} END {if (!found) print "$(YELLOW)Norm libft O.K.$(DEFAULT)"}'

valerie: cre
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
