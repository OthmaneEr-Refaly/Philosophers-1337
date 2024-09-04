White 	= \e[0;30m
Yellow 	= \x1b[33m
Red	= \e[0;31m
Blue	= \e[0;34m
Green 	= \033[1;32m

NAME	 = thinkers
COMPILER = cc
FLAGS	 = -Wall -Werror -Wextra
SRCS	 = philo.c parcing.c helper_functions.c data_init.c mutex_thread_handle.c

OBJS	 = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)
%.o: %.c
	@$(COMPILER) -c $< -o $@
	@echo "$(Red) [📂] Compiling File Named $<"
	@echo "$(Green) [✔] Compilation Complete ... ! "
	@echo "\n"
clean:
	@rm -rf $(OBJS)
fclean:
	@rm -rf $(OBJS) $(NAME)
re:
	all fclean