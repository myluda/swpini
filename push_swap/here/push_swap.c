/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:36:29 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/07/06 10:36:31 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct element
{
    int nombre;
    struct element *content;
    struct element *next;
}              t_element;

typedef struct list
{
    struct element *last;
    struct element *premier;
}               t_list;

void    ft_initilisation(t_list *node)
{
    node->last = NULL;
    node->premier = NULL;
}

t_list  *ft_lstnew(void *content)
{
	t_element	*elt;

	if (!(elt = (t_list*)malloc(sizeof(*elt))))
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_element *t;

	if (*alst)
	{
		t = ft_lstlast(*alst);
		t->next = &*new;
	}
	else
		*alst = new;
}
void	ft_lstadd_front(t_list **alst, t_element *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_element *t;
	t_element *tmp;

	t = *lst;
	while (t)
	{
		tmp = t->next;
		ft_lstdelone(t, del);
		t = tmp;
	}
	*lst = NULL;
}
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}


int main(int argc , char **argv)
{
    t_list *p;
    p = ft_lstnew("myluda");
    ft_lstadd_front("psps","psps");
    return 0;
}