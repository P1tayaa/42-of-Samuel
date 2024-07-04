/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:30:51 by sboulain          #+#    #+#             */
/*   Updated: 2022/12/10 18:55:22 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

char	*free_those(char **char_rd, char **char_rding);

char	*revome_fist_line_in_buffer(char *buffer);

int		get_first_line_len(char *buffer);

char	*strjoin_an_malloc(char *s1, char *s2, int size_of_s1, int size_of_s2);

char	*get_next_line(int fd);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#endif

#ifndef MAX_FD
# define MAX_FD 10032
#endif