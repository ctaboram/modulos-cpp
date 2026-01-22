# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 12:21:52 by ctaboada          #+#    #+#              #
#    Updated: 2026/01/19 12:22:46 by ctaboada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Account

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS		= tests.cpp Account.cpp

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