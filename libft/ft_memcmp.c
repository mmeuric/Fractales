/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:26:57 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:27:17 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		is_different;
	size_t	i;

	is_different = 0;
	i = -1;
	while (!is_different && ++i < n)
		is_different = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (is_different);
}
/*
int	main(void)
{
	char str1[] = "Hello, World!";
	char str2[] = "Hello, World!";
	char str3[] = "Hello, everyone!";

	int result1 = memcmp(str1, str2, sizeof(str1));
	int result2 = ft_memcmp(str1, str2, sizeof(str1));
	printf("memcmp result: %d\n", result1);
	printf("ft_memcmp result: %d\n\n", result2);

	result1 = memcmp(str1, str3, sizeof(str1));
	result2 = ft_memcmp(str1, str3, sizeof(str1));
	printf("memcmp result: %d\n", result1);
	printf("ft_memcmp result: %d\n", result2);

	return (0);
}*/
