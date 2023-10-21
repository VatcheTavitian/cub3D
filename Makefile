# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 12:19:25 by vtavitia          #+#    #+#              #
#    Updated: 2023/10/19 13:07:48 by vtavitia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_BONUS = cub3d_bonus
GCC      = gcc
CFLAGS   = -g #-fsanitize=address
RM       = rm -rf
LIBS     = -I./includes/ -I./minilibx -I./Libft
HEADER = includes/cube3d.h
HEADER_BONUS = includes/cube3d.h

#MACOS
LDFLAGS  = -LminilibX -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#Linux
#LDFLAGS = -LminiLibX -lmlx -lGL -lX11 -lm -lXext -o $(NAME)
# LIBS_DIR = includes


# Compiled directories
SRC = src
SRC_BONUS = src_bonus
OBJ = obj
OBJ_BONUS = obj_bonus
SUBDIRS = main parser raycasting

# Folder directions
SRC_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(SRC)/, $(dir)))
OBJ_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ)/, $(dir)))
SRC_BONUS_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(SRC_BONUS)/, $(dir)))
OBJ_BONUS_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ_BONUS)/, $(dir)))

# File directions
SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJS = $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))

SRCS_BONUS = $(foreach dir, $(SRC_BONUS_DIR), $(wildcard $(dir)/*.c))
OBJS_BONUS = $(subst $(SRC_BONUS), $(OBJ_BONUS), $(SRCS_BONUS:.c=.o))

LIB_DIR = $(foreach dir, $(LIBS_DIR), $(wildcard $(dir)/*.h))

# Libft
LIBFT     = ft
LIBFT_DIR = ./Lib$(LIBFT)/

# Minilibx
MINILIBX_DIR = ./minilibx/

# Colors
RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m

all: $(NAME) 

$(NAME): $(LIB_DIR) Makefile $(OBJS)
	@make WAIT_COMPILE_MSG
	@echo "${GREEN}-> Compiling LIBFT...${RESET}"
	@make -C $(LIBFT_DIR) all
	@make -C $(MINILIBX_DIR) all
	@$(GCC) $(OBJS) $(CFLAGS) $(LIBS) $(LDFLAGS) -L$(LIBFT_DIR) -l$(LIBFT) -o $(NAME)
	@make DONE_MSG

$(OBJ)/%.o: $(SRC)/%.c $(LIB_DIR)
	@mkdir -p $(OBJ) $(OBJ_DIR)
	@echo "${YELLOW}Compiling $<${RESET}"
	@$(GCC) $(CFLAGS) $(LIBS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIB_DIR) Makefile $(OBJS_BONUS)
	@make WAIT_COMPILE_MSG
	@echo "${GREEN}-> Compiling LIBFT for bonus...${RESET}"
	@make -C $(LIBFT_DIR) all
	@make -C $(MINILIBX_DIR) all
	@$(GCC) $(OBJS_BONUS) $(CFLAGS) $(LIBS) $(LDFLAGS) -L$(LIBFT_DIR) -l$(LIBFT) -o $(NAME_BONUS)
	@make DONE_MSG_BONUS


$(OBJ_BONUS)/%.o: $(SRC_BONUS)/%.c $(LIB_DIR)
	@mkdir -p $(OBJ_BONUS) $(OBJ_BONUS_DIR)
	@echo "${YELLOW}Compiling $<${RESET}"
	@$(GCC) $(CFLAGS) $(LIBS) -c $< -o $@

clean: DELETE_OBJ_MSG
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean DELETE_PROGRAM_MSG
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MINILIBX_DIR) clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(RDLINE)

re: fclean all

# Helper messages

WAIT_COMPILE_MSG:
	@echo "${YELLOW}Please wait until program compiling...${RESET}"
DONE_MSG:
	@echo "${GREEN}! Cub3d is ready !${RESET}"
DONE_MSG_BONUS:
	@echo "${GREEN}! Cub3d Bonus is ready !${RESET}"
DELETE_OBJ_MSG:
	@echo "${RED}Object files deleting...${RESET}"
DELETE_PROGRAM_MSG:
	@echo "${RED}! ATTENTION !\Cub3d is deleting...${RESET}"

.PHONY: all clean fclean re
