# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 14:22:11 by rjuarez-          #+#    #+#              #
#    Updated: 2025/12/11 14:39:12 by rjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# ==============================================================================
#	CATEGORIES
# ==============================================================================

FAUXILIARS	  = ft_auxiliars_libft.c
PUTS		  = ft_puts.c
CONVERSIONS   = ft_conver.c ft_conver_numbers.c
PRINTING	  = ft_printf.c

# ==============================================================================
#	GROUPS
# ==============================================================================

ALL	= $(FAUXILIARS) $(PUTS) $(CONVERSIONS) $(PRINTING)

# ==============================================================================
#	COMPILER CONFIGURATION
# ============================================================================== 
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ==============================================================================
#	FILE CONVERSION
# ==============================================================================
OBJS = $(ALL:.c=.o)

# ==============================================================================
#	LIBRARY CREATION
# ==============================================================================
${NAME}: ${OBJS}
	@ar crs ${NAME} ${OBJS}

# ==============================================================================
#	RULES
# ==============================================================================
#	Default (Only "make")
all: ${NAME}

#	Object Compilation
#		%  - wildcard
#		@  - echo off
#		$@ - output file (.o)
#		$< - input file (.c)
%.o : %.c
#	Compile command
	@$(CC) $(CFLAGS) -c -o $@ $<

#	Cleaning rules
#		clean  - objects files
#		fclean - objects files and librery
#		re     - compile everything again
#			rm = remove
#				-r = recursive (recursively removes directories and their contents)
#				-f = force (forces removal without prompting)
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

# Avoid conflicts
.PHONY: all clean fclean re 
