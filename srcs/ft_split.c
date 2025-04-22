/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melrose <melrose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:20:38 by melrose           #+#    #+#             */
/*   Updated: 2025/04/21 23:45:49 by melrose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!s || !*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	*allocate_word(const char **s, char c)
{
	size_t	word_len;
	char	*word;

	if (**s && ft_strchr(*s, c))
		word_len = ft_strchr(*s, c) - *s;
	else
		word_len = ft_strlen(*s);
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (word)
		ft_strlcpy(word, *s, word_len + 1);
	*s += word_len;
	return (word);
}

static char	**free_words(char **lst, int i)
{
	while (i > 0)
		free(lst[--i]);
	free(lst);
	return (NULL);
}

static char	**split_words(char **lst, const char **s, char c, int *i)
{
	while (**s)
	{
		while (**s == c && **s)
			(*s)++;
		if (**s)
		{
			lst[*i] = allocate_word(s, c);
			if (!lst[*i])
				return (free_words(lst, *i));
			(*i)++;
		}
	}
	lst[*i] = NULL;
	return (lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;

	if (!s)
		return (NULL);
	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	return (split_words(lst, &s, c, &i));
}
