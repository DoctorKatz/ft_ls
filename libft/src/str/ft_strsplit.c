/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 03:03:50 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/28 08:17:16 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		count_word(char const *s, char c)
{
	size_t	count;
	int		token;

	count = 0;
	token = 0;
	while (*s)
	{
		if (token == 1 && *s == c)
			token = 0;
		if (token == 0 && *s != c)
		{
			token = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t		len_wrd(char const *s, char c)
{
	size_t		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**ret;
	size_t		nb_words;
	size_t		word;

	word = 0;
	if (s == NULL)
		return (NULL);
	nb_words = count_word(s, c);
	ret = (char **)malloc(sizeof(char *) * nb_words + 1);
	if (ret == NULL)
		return (NULL);
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		ret[word] = ft_strsub(s, 0, len_wrd(s, c));
		if (ret[word] == NULL)
			return (NULL);
		s = s + len_wrd(s, c);
		word++;
	}
	ret[word] = NULL;
	return (ret);
}
