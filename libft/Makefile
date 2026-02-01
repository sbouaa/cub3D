SRC_F := \
		checkers/ft_isalpha.c \
		checkers/ft_isdigit.c \
		checkers/ft_isalnum.c \
		checkers/ft_isascii.c \
		checkers/ft_isprint.c \
		\
		converters/ft_toupper.c \
		converters/ft_tolower.c \
		\
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memset.c \
		mem/ft_bzero.c \
		mem/ft_calloc.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		\
		itoa_atoi/ft_atoi.c \
		itoa_atoi/ft_itoa.c \
		itoa_atoi/ft_stoa.c \
		\
		put_fd/ft_putchar_fd.c \
		put_fd/ft_putstr_fd.c \
		put_fd/ft_putendl_fd.c \
		put_fd/ft_putnbr_fd.c \
		put_fd/ft_puterror_fd.c \
		\
		put/ft_putchar.c \
		put/ft_putstr.c \
		put/ft_putnbr.c \
		\
		str/ft_strlen.c \
		str/ft_strslen.c \
		str/ft_strlcpy.c \
		str/ft_strlcat.c \
		str/ft_strchr.c \
		str/ft_strrchr.c \
		str/ft_strncmp.c \
		str/ft_strcmp.c \
		str/ft_strnstr.c \
		str/ft_substr.c \
		str/ft_strjoin.c \
		str/ft_strjoin3.c \
		str/ft_strsjoin.c \
		str/ft_strappend.c \
		str/ft_split.c \
		str/ft_split_sp.c \
		str/ft_split_by_one.c \
		str/ft_strtrim.c \
		str/ft_strmapi.c \
		str/ft_striteri.c \
		str/ft_strdup.c \
		\
		linked_lists/ft_lstnew.c \
		linked_lists/ft_lstadd_front.c \
		linked_lists/ft_lstsize.c \
		linked_lists/ft_lstlast.c \
		linked_lists/ft_lstadd_back.c \
		linked_lists/ft_lstdelone.c \
		linked_lists/ft_lstclear.c \
		linked_lists/ft_lstiter.c \
		linked_lists/ft_lstmap.c \
		\
		ft_printf/ft_printf.c \
		ft_printf/ft_print_char.c \
		ft_printf/ft_print_str.c \
		ft_printf/ft_print_nbr.c \
		ft_printf/ft_print_hex.c \
		ft_printf/toolbox_flags.c \
		ft_printf/toolbox_nbr.c \
		ft_printf/toolbox_hex.c \
		\
		get_next_line/get_next_line.c


OBJ_F = $(SRC_F:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ_F)
	$(AR) $(NAME) $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_F)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
