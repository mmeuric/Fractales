/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:48 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/16 02:21:03 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		size;

	size = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
/*
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
*/
/*
int	main(void)
{
	const char	*original = "Hello, World!";
	char		*duplicate;
	char		*duplicate_ft;

	duplicate = strdup(original);
	duplicate_ft = ft_strdup(original);
	printf("Original : %s\n", original);
	printf("strdup    : %s\n", duplicate);
	printf("ft_strdup : %s\n", duplicate_ft);
	free(duplicate);
	free(duplicate_ft);
	return (0);
}
*/
