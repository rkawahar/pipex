/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:27 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/05 18:03:08 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			*cmd;
	char			*path;
	char			**arg;
	struct s_cmd	*pre;
}			t_cmd;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_cmd	*first_lst(void);
int		ft_here_doc(char *eof);
size_t	ft_strlen(const char *s);
void	malloc_error(int i);
char	*ft_eof(char *eof);
int		checker(char *str, char *eof);
char	*pipex_gnl(char *eof);
char	*re_create(char *str, char tmp);
void	write_error(void);
void	ft_create_lst(int argc, char **argv, char **env, t_cmd **lst);
char	**ft_split(char const *s, char c);
int		split_str(char **ans, char const *s, char c);
void	ft_free(char **s, size_t index);
void	str_index_cpy(size_t start, size_t end, char const *s, char *ans);
size_t	counter(char const *s, char c);
void	ft_connect_nord(t_cmd **lst, t_cmd *new);
void	ft_to_first(t_cmd **lst);
void	ft_insert_info(t_cmd **lst, int argc, char **argv, char **env);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_path(char *cmd, char **env);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_printf(const char *str, ...);
int		ft_mini_printf(const char *str, size_t i, va_list ap);
int		ft_print_address(unsigned long address);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_print_uint(unsigned int num, int len);
int		ft_print_itoa(int num, int len);
int		ft_to_hexaddress(unsigned long int num, int len);
int		ft_to_hex(unsigned int num, int len);
int		ft_to_upperhex(unsigned int num, int len);
char	*ft_path2(char **bin, char *cmd);
void	ft_decide_fd(int *fd, int *last_file_fd, char **argv, char *file);
void	ft_free_bin(char **bin);
void	ft_judge_absolute(t_cmd *lst, char **argv, int index);

#endif