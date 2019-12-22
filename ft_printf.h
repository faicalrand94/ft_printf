/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:33:42 by fbouibao          #+#    #+#             */
/*   Updated: 2019/12/21 21:29:41 by fbouibao         ###   ########.fr       */
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
  char  valn;
  struct s_list *next;
} t_list;

typedef struct v_list
{
  char *flgs;
  char flg;
  int width;
  char *val;
  int prec;
  char *str_c;
  int val_i;
  unsigned int u_val;
  size_t st_val;
} vr_list;

int    ft_printf(char *str, ...);
size_t        ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(long n);
char *ft_itos(int i);
char *ft_itoa_16(size_t n);
t_list    *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **alst, t_list *new);
t_list        *l_lstnew(char *str,char *spfx, char *flg);
int get_spf(int pos, char* str);
void get_ob(char *str, t_list **ob);
char	*ft_strdup(const char *s1);
char *ft_itoa_int16(unsigned int n);
int		ft_isdigit(int c);
int str_spf_d(va_list ap, t_list *tmp);
int str_spf_u(va_list ap, t_list *tmp);
int str_spf_x(va_list ap, t_list *tmp);
int str_spf_p(va_list ap, t_list *tmp);
char  *neg_nbr(char *str);
int		cut_prec(va_list ap, char *flgs, int *i);
int		cut_width(va_list ap, char *flgs, int *i, char *flg);
char cut_flg(char *flgs, int *i);
char *get_s_p_u(char *val, int prec);
void	*ft_memset(void *str, int c, size_t n);
vr_list        *l_lstnew_vrbs();
int   ft_width(t_list *tmp, vr_list *vrbs);
int  ft_width_cnt(t_list *tmp, vr_list *vrbs);
char *get_s_p(char *val, int prec);
int str_spf_s(va_list ap, t_list *tmp);
int str_spf_c(va_list ap, t_list *tmp);
int   ft_width_str(t_list *tmp, vr_list *vrbs);
void	ft_width_cnt_str(t_list *tmp, vr_list *vrbs);
int	str_spf_pct(va_list ap, t_list *tmp);
char *get_s_p_s(char *val, int prec);

#endif
