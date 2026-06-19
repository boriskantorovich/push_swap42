/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkantoro <bkantoro@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 19:34:01 by bkantoro          #+#    #+#             */
/*   Updated: 2026/06/19 12:37:08 by bkantoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_fmt
{
	va_list	args;
	int		count;
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		prec;
}			t_fmt;

int			ft_printf(const char *fmt, ...);
void		ft_reset_flags(t_fmt *f);
int			ft_parse_flags(t_fmt *f, const char *fmt, int i);
int			ft_parse_width_and_prec(t_fmt *f, const char *fmt, int i);

void		ft_putchar_pf(t_fmt *f, char c);
void		ft_putstr_pf(t_fmt *f, char *s);
void		ft_putpading(t_fmt *f, char c, int n);

char		*ft_utoa_base(unsigned long n, const char *base, char *buf);

void		ft_putpad_str(t_fmt *f, char *s, int len);
void		ft_putone(t_fmt *f, char c);
void		ft_print_str(t_fmt *f, char *s);
void		ft_print_ptr(t_fmt *f, unsigned long p);
void		ft_print_base(t_fmt *f, unsigned long nb, char *base, char *prefix);
void		ft_print_nbr(t_fmt *f, char *prefix, char *digits);
void		ft_print_int(t_fmt *f);
void		ft_print_hex(t_fmt *f, int upper);

void		ft_route(t_fmt *f, char c);

#endif
