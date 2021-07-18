#	ifndef FT_GLOBAL_H
#	define FT_GLOBAL_H

#include "libftprintf.h"

t_type g_typetab[] =
	{
		{"c", &ft_print_char},
		{"s", &ft_print_str},
		{"p", &ft_print_adr},
		{"d", &ft_print_number},
		{"i", &ft_print_number},
		{"u", &ft_print_unsigned},
		{"x", &ft_print_unsigned},
		{"X", &ft_print_unsigned},
		{"f", &ft_print_float},
		{"g", &ft_print_g},
		{"e", &ft_print_exp},
		{"%", &ft_print_percent},
		{"n", &ft_record},
		{"", &ft_return}
	};

#	endif
