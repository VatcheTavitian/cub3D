/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:21:25 by vtavitia          #+#    #+#             */
/*   Updated: 2023/01/27 19:04:42 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	t_list	**start;

	if (lst == NULL)
		return (NULL);
	head = NULL;
	start = &head;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(start, del);
			return (NULL);
		}
		if (head == NULL)
			head = new;
		else
			ft_lstlast(head)->next = new;
		lst = lst->next;
	}
	return (*start);
}
