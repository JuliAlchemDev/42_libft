CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc

NAME = tests

SRCS_DIR =  srcs/
OBJS_DIR =  objs/

SRCS =  $(SRCS_DIR)ft_isalpha.c \
		$(SRCS_DIR)ft_isdigit.c \
		$(SRCS_DIR)ft_isalnum.c \
		$(SRCS_DIR)ft_isascii.c \
		$(SRCS_DIR)ft_isprint.c	\
		\
		$(SRCS_DIR)ft_toupper.c \
		$(SRCS_DIR)ft_tolower.c \
		$(SRCS_DIR)ft_atoi.c  \
		\
		$(SRCS_DIR)ft_strlen.c \
		$(SRCS_DIR)ft_strlcpy.c \
		$(SRCS_DIR)ft_strlcat.c \
		$(SRCS_DIR)ft_strchr.c \
		$(SRCS_DIR)ft_strrchr.c \
		\
		$(SRCS_DIR)ft_memset.c \
		$(SRCS_DIR)ft_bzero.c \
		$(SRCS_DIR)ft_memcpy.c  \
# 		$(SRCS_DIR)ft_memmove.c 

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c -o $(NAME)

clean: 
	@rm -f $(OBJS)
	rm -rf $(OBJS_DIR) 

fclean: clean
	rm -f $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re


# TO CHECK

# OBJS = $(SRCS: $(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
# $(OBJS_DIR)%.o: $(SRCS_DIR)%.c
# 	mkdir -f objs
#     $(CC) $(CFLAGS) -c $< -o $@
