/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:26:13 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 16:49:06 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

/*
int	main(void) {
	char str[] = "Hello, World!";
	char c = 'W';

	char *result_orig = memchr(str, c, sizeof(str));
	char *result_ft = ft_memchr(str, c, sizeof(str));

	if (result_orig)
		printf("memchr: Caractère '%c' trouvé à l'adresse : %p\n", c,
			result_orig);
	else
		printf("memchr: Caractère '%c' non trouvé.\n", c);

	if (result_ft)
		printf("ft_memchr: Caractère '%c' trouvé à l'adresse : %p\n", c,
			result_ft);
	else
		printf("ft_memchr: Caractère '%c' non trouvé.\n", c);

	return (0);
}*/
