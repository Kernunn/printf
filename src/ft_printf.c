/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:46:56 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/14 09:34:35 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_global.h"

static void	ft_size(const char **s, t_format *f)
{
	f->l = 0;
	f->ll = 0;
	f->h = 0;
	f->hh = 0;
	if (**s == 'l')
	{
		if (*(*s + 1) == 'l')
			f->ll = 1;
		else
			f->l = 1;
		*s = *s + 1;
	}
	if (**s == 'h')
	{
		if (*(*s + 1) == 'h')
			f->hh = 1;
		else
			f->h = 1;
		*s = *s + 1;
	}
	if (**s == 'h' || **s == 'l')
		*s = *s + 1;
}

static void	ft_flags(const char **s, t_format *f)
{
	f->l_align = 0;
	f->plus = 0;
	f->space = 0;
	f->sharp = 0;
	f->zero = 0;
	while (**s == '-' || **s == '+' || **s == ' ' || **s == '#' || **s == '0')
	{
		if (**s == '-')
			f->l_align = 1;
		if (**s == '+')
			f->plus = 1;
		if (**s == ' ')
			f->space = 1;
		if (**s == '#')
			f->sharp = 1;
		if (**s == '0')
			f->zero = 1;
		*s = *s + 1;
	}
}

static void	checkformat(char const **s, va_list ap, t_format *f)
{
	ft_flags(s, f);
	f->width = ft_atoi(*s);
	if (**s == '*')
	{
		f->width = va_arg(ap, int);
		*s = *s + 1;
	}
	if (f->width < 0)
	{
		f->width = -f->width;
		f->l_align = 1;
	}
	while (**s >= '0' && **s <= '9')
		*s = *s + 1;
	ft_precision(s, ap, f);
	while (**s >= '0' && **s <= '9')
		*s = *s + 1;
	ft_size(s, f);
}

static int	print(char const **s, va_list ap, int count)
{
	int			i;
	t_format	frm;

	i = 0;
	if (!s || !*s || !**s)
		return (0);
	checkformat(s, ap, &frm);
	while (i < 13 && ft_strncmp(g_typetab[i].type, *s, 1) != 0)
		i++;
	if (i == 2 || i == 6)
		frm.base_number = "0123456789abcdef";
	if ((i > 2 && i < 6) || (i > 7 && i < 11))
		frm.base_number = "0123456789";
	if (i == 7)
		frm.base_number = "0123456789ABCDEF";
	if (i == 12)
		frm.count = count;
	i = g_typetab[i].f(ap, &frm);
	*s = *s + (**s ? 1 : 0);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	int			count;
	const char	*tmp;
	va_list		ap;

	count = 0;
	va_start(ap, format);
	while (format && *format)
	{
		tmp = ft_strchr(format, '%');
		if (tmp)
		{
			count += tmp - format;
			write(1, format, tmp - format);
			format = tmp + 1;
		}
		else
		{
			count += (int)ft_strlen(format);
			ft_putstr_fd((char *)format, 1);
			format = NULL;
		}
		count += print(&format, ap, count);
	}
	va_end(ap);
	return (count);
}
