/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:51:09 by sesnowbi          #+#    #+#             */
/*   Updated: 2020/12/26 22:19:43 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define NO_FLAGS	0b00000000
# define F_MINUS	0b00000001
# define F_PLUS		0b00000010
# define F_ZERO		0b00000100
# define F_SPACE	0b00001000
# define F_OCTOTROP	0b00010000
# define F_L		0b00000001
# define F_LL		0b00000010
# define F_H		0b00000100
# define F_HH		0b00001000

typedef struct		s_str
{
	unsigned char	flags;
	int				width;
	int				dot;
	int				precision;
	unsigned char	lh_flags;
	char			type;
	int				print_len;
}					t_str;

int					ft_printf(const char *format, ...);
void				ft_parse_and_handle
					(const char *format, va_list *args, t_str *strct);
void				ft_default_init_strct(t_str *strct);
char				*ft_parser(char *ptr, va_list *args, t_str *strct);
char				*ft_print_before_percent(char *ptr, t_str *strct);
char				*ft_read_percent(char *ptr, va_list *args, t_str *strct);
char				*ft_form_flags(char *ptr, t_str *strct);
char				*ft_form_width(char *ptr, va_list *args, t_str *strct);
char				*ft_form_precision(char *ptr, va_list *args, t_str *strct);
char				*ft_form_lh_flags(char *ptr, t_str *strct);
char				*ft_form_type(char *ptr, t_str *strct);
void				ft_handle_args(va_list *args, t_str *strct);
void				ft_int_handle(va_list *args, t_str *strct);
int					ft_precision_diff(t_str *strct, long int num, int dig_rank);
int					ft_dig_rank(long int num);
void				ft_char_handle(va_list *args, t_str *strct);
void				ft_t_precent_handle(t_str *strct);
void				ft_string_handle(va_list *args, t_str *strct, char *nulll);
void				ft_pointer_handle(va_list *args, t_str *strct);
void				ft_x_low_handle(va_list *args, t_str *strct);
void				ft_x_up_handle(va_list *args, t_str *strct);
int					ft_precision_diff_x
					(t_str *strct, int dig_rank);
int					ft_len_x(unsigned int num);
void				ft_putnbr_x(unsigned int ptr, char *base);
void				ft_uns_handle(va_list *args, t_str *strct);
int					ft_len_u(unsigned int num);
int					ft_precision_diff_u
					(t_str *strct, int dig_rank);
void				ft_putnbr_u(unsigned int n);

#endif
