# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktorvi <ktorvi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 07:03:04 by ktorvi            #+#    #+#              #
#    Updated: 2023/10/03 14:11:45 by ktorvi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRC =	ft_isalpha.c       \
	  	ft_isdigit.c       \
	  	ft_isalnum.c       \
	  	ft_isascii.c       \
	  	ft_isprint.c       \
	  	ft_strlen.c        \
	  	ft_memset.c        \
	  	ft_bzero.c         \
	  	ft_memcpy.c        \
	  	ft_memmove.c       \
	  	ft_strlcpy.c       \
	  	ft_strlcat.c       \
		ft_toupper.c       \
		ft_tolower.c       \
		ft_strchr.c        \
		ft_strrchr.c       \
		ft_strncmp.c       \
		ft_strnstr.c       \
		ft_memchr.c        \
		ft_memcmp.c        \
		ft_strnstr.c       \
		ft_atoi.c          \
		ft_calloc.c        \
    	ft_strdup.c        \
		ft_substr.c        \
		ft_strjoin.c 	   \
		ft_strtrim.c       \
		ft_split.c		   \
		ft_itoa.c   	   \
		ft_strmapi.c       \
		ft_striteri.c      \
		ft_putchar_fd.c    \
		ft_putstr_fd.c     \
		ft_putendl_fd.c    \
		ft_putnbr_fd.c     \
		get_next_line.c          \
		get_next_line_utils.c    \
		

BONUS = ft_lstnew_bonus.c        \
		ft_lstsize_bonus.c       \
		ft_lstlast_bonus.c       \
		ft_lstadd_back_bonus.c   \
		ft_lstadd_front_bonus.c  \
		ft_lstdelone_bonus.c     \
		ft_lstclear_bonus.c      \
		ft_lstiter_bonus.c       \
		ft_lstmap_bonus.c        \

INC = libft.h         \

CC = cc

FLAGS = -Wall -Wextra -Werror -arch arm64

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(INC)
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	@rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
