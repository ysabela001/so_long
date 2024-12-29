/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytavares <ytavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:04:16 by ytavares          #+#    #+#             */
/*   Updated: 2024/12/14 13:38:51 by ytavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strchr_2(const char *s, int c);
char	*ft_strjoin_2(char *s1, char const *s2);
char	*ft_strdup_2(const char *str);
size_t	ft_strlcpy_2(char *dst, const char *src, size_t size);

#endif