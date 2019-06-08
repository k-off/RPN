/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_elems.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 17:48:16 by pacovali      #+#    #+#                 */
/*   Updated: 2019/04/21 17:48:16 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list		*new_ops(void)
{
	t_list	*ops;

	ops = (t_list*)malloc(sizeof(t_list));
	ops->is_num = 0;
	ops->num = 0;
	ops->str = NULL;
	ops->next = NULL;
	return (ops);
}

static int	add_oper(t_list *ops, char *s, int *i)
{
	t_list	*next;

	next = ops;
	if (!ops->is_num || !ops->next)
		return (0);
	while (next->next)
		next = next->next;
	next->next = new_ops();
	next->next->str = (char*)malloc(sizeof(char) * 2);
	next->next->str[0] = s[*i];
	(*i)++;
	return (1);
}

static int	add_num(t_list *ops, char *s, int *i)
{
	t_list	*next;
	int		digits;

	next = ops;
	digits = *i;
	while (next->next)
		next = next->next;
	if (next->is_num || next->str)
	{
		next->next = new_ops();
		next = next->next;
	}
	next->num = atoi(&s[*i]);
	if (next->num < 0 && s[*i] != '-')
		return (0);
	next->is_num = 1;
	while (ft_isnum(s, i))
		(*i)++;
	if ((s[*i] != '-' && *i - digits > 11) || *i - digits > 10)
		return (0);
	if (!(ft_isspace(s[*i]) || s[*i] == 0))
		return (0);
	return (1);
}

int			get_ops(t_list *ops, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (ft_isoper(s, &i))
			if (add_oper(ops, s, &i) == 0)
				return (0);
		if (ft_isnum(s, &i))
			if (add_num(ops, s, &i) == 0)
				return (0);
		if (!(ft_isspace(s[i]) || ft_isoper(s, &i) \
			|| ft_isnum(s, &i) || s[i] == 0))
			return (0);
	}
	return (1);
}
