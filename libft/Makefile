# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jraleman@student.42.us.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#              #
#    Updated: 2020/03/10 01:33:26 by lgunship         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = libft.a
SRC    = src/char/ft_isalnum.c\
         src/char/ft_isalpha.c\
         src/char/ft_isascii.c\
         src/char/ft_isdigit.c\
         src/char/ft_isprint.c\
         src/char/ft_tolower.c\
         src/char/ft_toupper.c\
         src/conv/ft_atoi.c\
         src/conv/ft_itoa.c\
         src/conv/ft_swap.c\
         src/lines/ft_count_word.c\
         src/lines/ft_getlines.c\
         src/lines/get_next_line.c\
         src/lst/ft_lstadd.c\
         src/lst/ft_lstdel.c\
         src/lst/ft_lstdelone.c\
         src/lst/ft_lstiter.c\
         src/lst/ft_lstmap.c\
         src/lst/ft_lstnew.c\
         src/lst/ft_lstrev.c\
         src/lst/ft_push_ptr.c\
         src/lst/ft_strnewnull.c\
         src/math/ft_clamp.c\
         src/math/ft_isprime.c\
         src/math/ft_iterative_power.c\
         src/math/ft_sqrt.c\
         src/mem/ft_bzero.c\
         src/mem/ft_memalloc.c\
         src/mem/ft_memccpy.c\
         src/mem/ft_memchr.c\
         src/mem/ft_memcmp.c\
         src/mem/ft_memcpy.c\
         src/mem/ft_memdel.c\
         src/mem/ft_memmove.c\
         src/mem/ft_memrchr.c\
         src/mem/ft_memset.c\
         src/put/ft_putchar.c\
         src/put/ft_lprintf.c\
         src/put/ft_putchar_fd.c\
         src/put/ft_putendl.c\
         src/put/ft_putendl_fd.c\
         src/put/ft_putnbr.c\
         src/put/ft_putnbr_fd.c\
         src/put/ft_putstr.c\
         src/put/ft_putstr_fd.c\
         src/str/ft_findchr.c\
         src/str/ft_strcat.c\
         src/str/ft_strchr.c\
         src/str/ft_strclr.c\
         src/str/ft_strcmp.c\
         src/str/ft_strcpy.c\
         src/str/ft_strdel.c\
         src/str/ft_strdup.c\
         src/str/ft_strequ.c\
         src/str/ft_striter.c\
         src/str/ft_striteri.c\
         src/str/ft_strjoin.c\
         src/str/ft_strlcat.c\
         src/str/ft_strlen.c\
         src/str/ft_strlower.c\
         src/str/ft_strmap.c\
         src/str/ft_strmapi.c\
         src/str/ft_strncat.c\
         src/str/ft_strncmp.c\
         src/str/ft_strncpy.c\
         src/str/ft_strndup.c\
         src/str/ft_strnequ.c\
         src/str/ft_strnew.c\
         src/str/ft_strnstr.c\
         src/str/ft_strrchr.c\
         src/str/ft_strsplit.c\
         src/str/ft_strstr.c\
         src/str/ft_strsub.c\
         src/str/ft_strtrim.c
CC     = gcc
CFLAGS = -Wall -Wextra -Werror -I inc/.
OBJ     = $(SRC:.c=.o)

all: $(NAME)
%.o: %.c
	@printf "[Libft] Compiling [:.]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[Libft] Compiling [.:]\r"
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "[Libft] Compiled successfuly! [OK]\n"
clean:
	@/bin/rm -f $(OBJ)
	@printf "[Libft] Removed object files!\n"
nofclean:
	@/bin/rm -f $(NAME)
	@printf "[Libft] Removed libft binary!\n"
fclean: nofclean clean
re: fclean all

.PHONY: all clean fclean re
