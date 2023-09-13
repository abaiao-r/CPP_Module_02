# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 18:08:05 by abaiao-r          #+#    #+#              #
#    Updated: 2023/09/13 13:39:05 by abaiao-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings	
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

# Directories
SRCDIR = src
OBJDIR = objs

# Source Files

SRCS = 	$(SRCDIR)/main.cpp \
		$(SRCDIR)/Fixed.cpp


OBJS = 	$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Targets
NAME = My_First_Class_in_Canonical_Form

all: 	$(NAME)


clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -f $(NAME)

run:	fclean all
		./$(NAME)

re:		fclean all

test: 	all
		./$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o  $(NAME) 

%.o: %.cpp
	$(CXX) -Wall -Wextra -Werror -c $< -o $@ 

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean fclean re run test