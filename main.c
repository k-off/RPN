/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 17:48:16 by pacovali      #+#    #+#                 */
/*   Updated: 2019/04/21 17:48:16 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	calc_val(int *res, int num, char op)
{
	if (op == '+')
		*res += num;
	else if (op == '-')
		*res -= num;
	else if (op == '*')
		*res *= num;
	else if (op == '/' && num == 0)
		return (0);
	else if (op == '/' && num != 0)
		*res /= num;
	else if (op == '%' && num == 0)
		return (0);
	else if (op == '%' && num != 0)
		*res %= num;
	return (1);
}

static void	del_ops(t_list *ops)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = ops->next;
	tmp_2 = ops->next->next;
	ops->next = ops->next->next->next;
	if (tmp_2->str)
		free(tmp_2->str);
	if (tmp_1->str)
		free(tmp_1->str);
	free(tmp_2);
	free(tmp_1);
	tmp_2 = NULL;
	tmp_1 = NULL;
}

static int	calc_rpn(t_list *ops)
{
	if (ops->next->is_num && ops->next->next->is_num)
		calc_rpn(ops->next);
	if (ops->next->is_num && ops->next->next && !ops->next->next->is_num)
	{
		if (!calc_val(&(ops->num), ops->next->num, ops->next->next->str[0]))
			return (0);
		else
			del_ops(ops);
	}
	else if (ops->next->is_num && !ops->next->next)
		return (0);
	if (ops->next && ops->next->next && ops->next->is_num)
		calc_rpn(ops);
	if (ops->next)
		if (ops->next->next == NULL)
			return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_list	*ops;

	ops = new_ops();
	if (argc == 2 && get_ops(ops, argv[1]) == 1 && calc_rpn(ops) == 1)
		printf("%d\n", ops->num);
	else
		printf("Error\n");
	return (0);
}
