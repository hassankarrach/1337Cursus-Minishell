/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbasri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:07:55 by aelbasri          #+#    #+#             */
/*   Updated: 2023/11/10 20:16:13 by aelbasri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	p = lst;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return (i);
}