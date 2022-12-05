/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulain <sboulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:30:51 by sboulain          #+#    #+#             */
/*   Updated: 2022/12/05 10:29:28 by sboulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H
#  include <stddef.h>
#  include <stdlib.h>
#  include <unistd.h>

char	*get_next_line(int fd);
#endif


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2

#endif

