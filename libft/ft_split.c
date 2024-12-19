/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:33:42 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 15:10:04 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char delimiter)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != delimiter)
		{
			count++;
			while (*s && *s != delimiter)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static int	get_word_length(char const *s, char delimiter)
{
	int	length;

	length = 0;
	while (s[length] && s[length] != delimiter)
		length++;
	return (length);
}

static char	**allocate_result(int total_words)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (total_words + 1));
	return (result);
}

static int	fill_result(char **result, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = get_word_length(s, c);
			result[i] = ft_substr(s, 0, len);
			if (!result[i])
				return (-1);
			i++;
			s += len;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		total_words;

	if (!s)
		return (NULL);
	total_words = count_words(s, c);
	result = allocate_result(total_words);
	if (!result)
		return (NULL);
	if (fill_result(result, s, c) == -1)
		return (NULL);
	return (result);
}
/*
int	main(void)
{
	char str[] = "Bonjour,42!Etudiants";
	char **result;
	int i;

	result = ft_split(str, 'u');
	if (result)
	{
		for (i = 0; result[i]; i++)
			printf("Mot %d: %s\n", i, result[i]);
		for (i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}
	else
	{
		printf("Erreur de division de la chaîne.\n");
	}
	return (0);
}*/