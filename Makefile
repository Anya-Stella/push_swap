# **************************************************************************** #X
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tishihar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 00:33:04 by tishihar          #+#    #+#              #
#    Updated: 2025/01/05 05:34:48 by tishihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===============================================================================
#                                基本設定
#===============================================================================

# name of project
NAME := push_swap

# compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# for dev and debug
DEVFLAGS := -O0 -g -fsanitize=address
#===============================================================================
#                               ディレクトリ設定
#===============================================================================

# source_code and object_code directory
SRC_DIR := src
OBJ_DIR := bin

# libft
LIBFT_DIR := libft
LIBFT_INC_DIR := $(LIBFT_DIR)

# include
INC_DIR := include
INCLUDES := -I$(INC_DIR) -I$(LIBFT_INC_DIR)
#===============================================================================
#                              ソースファイル設定
#===============================================================================

SRCS := \
    stack_init_utils.c \
	validation.c \
    main.c

# replace object (.c → .o)
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
#===============================================================================
#                              ライブラリ設定
#===============================================================================

# PATH of libft.a
LIBFT := $(LIBFT_DIR)/libft.a
#===============================================================================
#                                ルール定義
#===============================================================================

all: $(NAME)

# use: make dev
dev: CFLAGS += $(DEVFLAGS)
dev: LDFLAGS += $(DEVFLAGS)
dev: all

# main(linker) rule
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT) $(LDFLAGS)

# compile rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# generate libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# cleans
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean
fclean: clean
	rm -f $(NAME)
re: fclean all
devre: fclean dev

# phony
.PHONY: all dev devre clean fclean re






