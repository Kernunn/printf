#	ifndef LIBFTPRINTF_H
#	define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_format {
  int l_align;
  int zero;
  int plus;
  int space;
  int sharp;
  int l;
  int ll;
  int h;
  int hh;
  int width;
  int prec_bool;
  int precision;
  char *base_number;
  int count;
  int minus;
  int nul;
} t_format;

typedef struct s_type {
  char *type;
  int (*f)(va_list ap, t_format *frm);
} t_type;

int ft_printf(const char *format, ...);
int ft_addzero(t_format *frm, int len_n);
int ft_addspace(t_format *frm, int len_n);
int ft_addzero_double(t_format *frm, int len_to_dot);
int ft_addspace_double(t_format *frm, int len_to_dot);
int ft_adr_null(t_format *frm);
char *ft_itoa_unsigned(unsigned int n, char *base);
char *ft_itoa_ull(unsigned long long n, char *base);
char *ft_itoa_ll(long long n);
char *ft_ftoa(double n);
int ft_print_char(va_list ap, t_format *frm);
int ft_print_str(va_list ap, t_format *frm);
int ft_print_adr(va_list ap, t_format *frm);
int ft_print_number(va_list ap, t_format *frm);
int ft_print_unsigned(va_list ap, t_format *frm);
int ft_print_float(va_list ap, t_format *frm);
int ft_print_exp(va_list ap, t_format *frm);
int ft_print_g(va_list ap, t_format *frm);
int ft_print_percent(va_list ap, t_format *frm);
int ft_record(va_list ap, t_format *frm);
int ft_return(va_list ap, t_format *frm);
void ft_write_adr(char *adr);
int ft_write_double(char *num, t_format *frm, int len_to_dot);
void ft_is_exp(char **num, int *degree, t_format *frm);
int ft_write_exp(t_format *frm, int count, int degree);
void ft_digit(char *num, int len_to_dot, t_format *frm);
char *ft_size_signed(va_list ap, t_format *frm);
char *ft_size_unsigned(va_list ap, t_format *frm);
int ft_print_sign(t_format *frm, int n_double);
int ft_print_dot(t_format *frm);
void ft_changeflag(t_format *frm);
void ft_precision(char const **s, va_list ap, t_format *f);
int ft_is_nan(char *num, t_format *f);
int ft_is_inf(char *num, t_format *f);

#	endif
