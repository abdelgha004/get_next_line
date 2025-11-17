# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 16:50:04 by aakourya          #+#    #+#              #
#    Updated: 2025/11/17 15:41:19 by aakourya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

NAME    = libget_next_line.a

SRC     = get_next_line.c
OBJ     = $(SRC:.c=.o)

# BONUS     = get_next_line_bonus.c get_next_line_utils_bonus.c
# BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	
bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re:	fclean all

.PHONY: all clean fclean re