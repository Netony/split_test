#include <stdio.h>
#include "libft.h"

static t_list	*makelist(char *s, char *set);
static char		**ft_split_test(t_list *lst);
static char		*get_char(t_list *node);

int	main(void)
{
	char	*hello = "";
	char	**split;
	t_list	*list;

	list = makelist(hello, ", ");
	split = ft_split_test(list);
	if (split == NULL)
	{
		ft_lstclear(list);
		return (NULL);
	}
	while (*split)
		printf("%s", *(split++));
	return (0);
}

static t_list	*makelist(char *s, char *set)
{
	t_list	*head;
	t_list	*node;
	char	*content;
	int		i;
	int		size;

	i = 0;
	head = NULL;
	while (s[i])
	{
		i += ft_isinlen(&s[i], set, 0);
		size = ft_isinlen(&s[i], set, 1);
		if (size != 0)
			content = ft_substr(s, i, size);
		if (content == NULL)
			ft_lstclear(&head, free);
		node = ft_lstnew(content);
		if (node == NULL)
		{
			free(content);
			ft_lstclear(&head, free);
		}
		ft_lstadd_back(&head, node);
		i += size;
	}
	return (head);
}

char	**ft_split_test(t_list *lst)
{
	int		i;
	int		size;
	char	**split;

	size = ft_lstsize(lst);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		split[i++] = get_char(lst);
		lst = lst->next;
	}
	split[i] = NULL;
	return (split);
}

static char	*get_char(t_list *node)
{
	return ((char *)(node->content));
}
