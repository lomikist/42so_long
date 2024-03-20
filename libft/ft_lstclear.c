/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:20:41 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/31 16:39:51 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_list;
	t_list	*next;

	if (!lst || !del)
		return ;
	current_list = *lst;
	while (current_list && current_list->content && del)
	{
		next = current_list->next;
		del(current_list->content);
		free(current_list);
		current_list = next;
	}
	*lst = NULL;
}
