/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:33:42 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/01 15:33:44 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct s_list
{
  char  *str;
  char  spfx;
  char  *flg;
  struct s_list *next;
} t_list;

size_t        ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
char *ft_itos(int i);
char *ft_itoa_16(size_t n);
t_list    *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **alst, t_list *new);
t_list        *l_lstnew(char *str,char *spfx, char *flg);
int get_spf(int pos, char* str);
void get_ob(char *str, t_list **ob);
void    ft_printf(char *str, ...);
char	*ft_strdup(const char *s1);
char *ft_itoa_long16(long n);
int		ft_isdigit(int c);
void str_spf_d(va_list ap, t_list *tmp);
char *get_s_p(char *val, char *prec, int a);
char  *neg_nbr(char *str);
char *cut_prec(va_list ap, char *flgs, int *i);
char *cut_width(va_list ap, char *flgs, int *i, char *flg);
char cut_flg(char *flgs, int *i);
void str_spf_s(va_list ap, t_list *tmp);

#endif
