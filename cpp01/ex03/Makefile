# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 13:53:36 by ctaboada          #+#    #+#              #
#    Updated: 2026/01/21 13:56:17 by ctaboada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= weapon

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -D__USE_MINGW_ANSI_STDIO=0
SRCS		= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS		= $(SRCS:.cpp=.o)

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compilado exitosamente$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)✓ Compilado: $<$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)✗ Archivos objeto eliminados$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) eliminado$(RESET)"

re: fclean all

.PHONY: all clean fclean re