/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:29:22 by vphilipp          #+#    #+#             */
/*   Updated: 2023/10/25 16:29:23 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr_base_fdr(long long nbr, int i, char *base, int fd);
int		ft_putui_base_fdr(unsigned int nbr, int i, char *base, int fd);
int		ft_putul_base_fdr(unsigned long nbr, int i, char *base, int fd);

long	ft_strllen(char *str);

int		ft_strstr_bool(char *str, char *to_find);
int		find_dupc(char *str);
int		ft_voidhex_fdr(void *ptr, int i, int fd);
int		ft_putint_fdr(int n, int i, int fd);
int		ft_putuint_fdr(unsigned int n, int i, int fd);
int		ft_putnbr_fdr(long long n, int i, int fd);
int		ft_putchar_fdr(char c, int fd);
int		ft_putstr_fdr(char *s, int fd);
#endif
