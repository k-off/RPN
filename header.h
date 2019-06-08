/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                             :+:    :+:          */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 17:48:16 by pacovali      #+#    #+#                 */
/*   Updated: 2019/04/21 17:48:16 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	char			*str;
	int				is_num;
	int				num;
	struct s_list	*next;
}					t_list;

int					main(int argc, char **argv);
int					get_ops(t_list *ops, char *s);
t_list				*new_ops(void);
int					ft_isspace(char c);
int					ft_isoper(char *s, int *i);
int					ft_isnum(char *s, int *i);

#endif
