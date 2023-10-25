NAME = push_swap
DESTDIR = test
LIBFT_DIR = inc/libft
SRCS_DIR = src
OBJS_DIR = objs
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -Iinc/libft/inc
SRCS = 	$(wildcard $(SRCS_DIR)/*c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

##RULES

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)/

$(NAME): $(LIBFT) $(OBJS)
	@mkdir -p $(DESTDIR)
	@$(CC) $(CFLAGS)	-o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft
	@cp $(NAME) $(DESTDIR)
	@echo "push_swap compiled successfully!"
	@echo "push_swap copied into $(DESTDIR)!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR)/ -I inc/ -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)/
	@rm -rf $(OBJS_DIR)
	@echo "Objet files and directory removed!"

fclean: clean
	@make fclean -C $(LIBFT_DIR)/
	@rm -f $(DESTDIR)/$(NAME)
	@rm -f $(NAME)
	@echo "Executable and librery removed!"

re: fclean all

.PHONY: all clean fclean re
