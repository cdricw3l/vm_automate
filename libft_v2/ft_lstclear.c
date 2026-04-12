/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:48:43 by cdric.b           #+#    #+#             */
/*   Updated: 2026/03/09 23:56:25 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*root;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	root = *lst;
	while (root)
	{
		tmp = root;
		root = root->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
