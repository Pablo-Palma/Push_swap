NAME = push_swap
LIBFT_DIR = inc/libft
SRCS_DIR = src
OBJS_DIR = objs
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SRCS = 	$(wildcard $(SRCS_DIR)/*c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

##RULES

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)/

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS)	-o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft
	@echo "push_swap compiled successfully!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR)/ -I inc/ -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)/
	@rm -rf $(OBJS_DIR)
	@echo "Objet files and directory removed!"

fclean: clean
	@make fclean -C $(LIBFT_DIR)/
	@rm -f $(NAME)
	@echo "Executable and librery removed!"

re: fclean all

.PHONY: all clean fclean re
