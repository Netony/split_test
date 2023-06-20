int	main(void)
{
	char	*s;
	char	*pattern;

	s = ft_strdup("01233,0x939103");
	pattern = ft_strdup("\d,\x");


}

int	ft_check_pattern(char *s, char *pattern)
{
	int		i;
	t_list	*lst;
	t_list	*new;

	i = 0;
	lst = NULL;
	while (s[i])
	{
		if (ft_iseq(s[i], '\'))
		{
			i++;
			if (s[i] == 'd')
			{
				new = ft_lstnew(ft_strdup("\d"));
				if (new == NULL)
				{
					ft_lstclear(&lst, free);
					return (NULL);
				}
				ft_lstadd_back(&lst, new);
			}
			else if (s[i] == 'x')
				;
		}
		else
			ft_substr(s, i, ft_isinlen(s[i], '\'));


		i++;
	}
}

int	check_pattern(char *s, t_list *pattern)
{
	int	i;

	i = 0;
	while (pattern)
	{
		ft_lstget_char(pattern);
		pattern = pattern->next;
	}
}

char	*ft_lstget_char(t_list *lst)
{
	return ((char *)(lst->content));
}

int	pattern_d(char const *s)
{
	return (ft_isinlen(s, "0123456789", 0))
}

int	pattern_x_lower(char const *s);
{
	if (ft_strncmp(s, "0x", 2) != 0)
		return (0);
	return (ft_isinlen(s + 2, "01234567889abcdef", 0));
}

int	pattern_x_upper(char const *s);
{
	if (ft_strncmp(s, "0X", 2) != 0)
		return (0);
	return (ft_isinlen(s + 2, "01234567889ABCDEF", 0));
}
