/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:22:29 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/30 19:23:12 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current_list;
	t_list	*temp;

	current_list = lst;
	if (lst == NULL || f == NULL)
		return ;
	while (current_list)
	{
		temp = current_list->next;
		f(current_list->content);
		current_list = temp;
	}
}
