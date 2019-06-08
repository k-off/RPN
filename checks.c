/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 17:48:16 by pacovali      #+#    #+#                 */
/*   Updated: 2019/04/21 17:48:16 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	ft_isoper(char *s, int *i)
{
	if ((s[*i] == '+' || s[*i] == '-' || s[*i] == '*' || s[*i] == '/' \
		|| s[*i] == '%') && (s[*i + 1] == 0 || ft_isspace(s[*i + 1])))
		return (1);
	return (0);
}

int	ft_isnum(char *s, int *i)
{
	if (((s[*i] == '+' || s[*i] == '-') && s[*i + 1] > 47 && s[*i + 1] < 58) \
		|| ((s[*i] > 47 && s[*i] < 58) && ((s[*i + 1] > 47 && s[*i + 1] < 58) \
		|| ft_isspace(s[*i + 1]))))
		return (1);
	return (0);
}
