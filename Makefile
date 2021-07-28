# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 18:33:46 by sesnowbi          #+#    #+#              #
#    Updated: 2020/12/26 22:13:47 by sesnowbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT_D	= ./libft
LIBFT_A	= libft.a
SRCS	= printf/ft_printf.c \
		  printf/ft_parse_and_handle.c \
		  printf/ft_default_init_strct.c \
		  parser/ft_parser.c \
		  parser/ft_print_before_percent.c \
		  parser/ft_read_percent.c \
		  parser/ft_form_flags.c \
		  parser/ft_form_width.c \
		  parser/ft_form_precision.c \
		  parser/ft_form_lh_flags.c \
		  parser/ft_form_type.c \
		  args_handlers/ft_handle_args.c \
		  args_handlers/ft_int_handle.c \
		  args_handlers/ft_int_utils.c \
		  args_handlers/ft_char_handle.c \
		  args_handlers/ft_string_handle.c \
		  args_handlers/ft_pointer_handle.c \
		  args_handlers/ft_x_low_handle.c \
		  args_handlers/ft_x_up_handle.c \
		  args_handlers/ft_x_utils.c \
		  args_handlers/ft_uns_handle.c \
		  args_handlers/ft_uns_utils.c
INC		= includes/libftprintf.h
OBJS	= $(SRCS:.c=.o)

BONUS	= 
B_OBJS	= $(BONUS:.c=.o)


CC		= gcc
RM		= /bin/rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -include $(INC) -o $(<:.c=.o)

$(NAME):		$(OBJS)
					$(MAKE) bonus -C libft
					cp $(LIBFT_D)/$(LIBFT_A) $(NAME)
					ar rc $(NAME) $(OBJS)

all:			$(INC) $(NAME)

clean:
				$(RM) $(OBJS) $(B_OBJS)
				$(MAKE) clean -C $(LIBFT_D)

fclean:			clean
					$(RM) $(NAME)
					$(MAKE) fclean -C $(LIBFT_D)

re:				fclean all

bonus:			$(OBJS) $(B_OBJS)
					$(MAKE) bonus -C $(LIBFT_D)
					cp $(LIBFT_D)/$(LIBFT_A) $(NAME)
					ar rc $(NAME) $(OBJS) $(B_OBJS)

.PHONY:			all clean fclean re bonus
