NAME = push_swap
INC_DIR = inc
CHECKER = checker
DESTDIR = test
LIBFT_DIR = inc/libft
SRCS_DIR = src
SHARED_DIR = shared
CHECKER_DIR = bonus
OBJS_DIR = objs
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g3 -I$(LIBFT_DIR)/inc -I$(INC_DIR)
SHARED_FILES = ft_input2_utils.c ft_order2_operations.c ft_stack_operations.c \
               ft_input_utils.c ft_order_operations.c
SHARED_SRCS = $(addprefix $(SHARED_DIR)/, $(SHARED_FILES))
SRC_FILES = ft_hundred_utils.c ft_sort_five_numbers.c ft_sort_three_numbers.c \
            ft_push_swap.c ft_sort_hundred.c main.c
PUSH_SWAP_SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

CHECKER_FILES = checker_bonus.c
CHECKER_SRCS =$(addprefix $(CHECKER_DIR)/, $(CHECKER_FILES))
SHARED_OBJS = $(SHARED_SRCS:$(SHARED_DIR)/%.c=$(OBJS_DIR)/%.o)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
CHECKER_OBJS = $(CHECKER_SRCS:$(CHECKER_DIR)/%.c=$(OBJS_DIR)/%.o) 

##RULES

default: $(NAME)

all: default $(CHECKER)

bonus: all $(CHECKER)

$(LIBFT):
	@make -C $(LIBFT_DIR)/

$(NAME): $(LIBFT) $(SHARED_OBJS) $(PUSH_SWAP_OBJS)
	@mkdir -p $(DESTDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(SHARED_OBJS) $(PUSH_SWAP_OBJS) $(LDFLAGS) -L$(LIBFT_DIR) -lft
	@cp $(NAME) $(DESTDIR)/
	@echo "push_swap compiled successfully!"
	@echo "push_swap copied into $(DESTDIR) succesfully!"

$(CHECKER):$(LIBFT) $(SHARED_OBJS) $(CHECKER_OBJS)
	@mkdir -p $(DESTDIR)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(SHARED_OBJS) $(CHECKER_OBJS) -L$(LIBFT_DIR) -lft
	@cp $(CHECKER) $(DESTDIR)
	@echo "Checker compiled successfully!"
	@echo "Checker copied into $(DESTDIR) successfully!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFT_DIR)/ -I inc/ -c $< -o $@

$(OBJS_DIR)/%.o: $(SHARED_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFT_DIR)/ -I inc/ -c $< -o $@

$(OBJS_DIR)/%.o: $(CHECKER_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR)/ -I inc/ -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)/
	@rm -rf $(OBJS_DIR)
	@echo "Objet files and directory removed!"

fclean: clean
	@make fclean -C $(LIBFT_DIR)/
	@rm -f $(DESTDIR)/$(NAME) $(DESTDIR)/$(CHECKER)
	@rm -f $(NAME) $(CHECKER)
	@echo "Executable and librery removed!"

re: fclean all

.PHONY: all clean fclean re
