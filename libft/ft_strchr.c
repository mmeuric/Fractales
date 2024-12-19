/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:22 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/16 01:48:37 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while ((*s != '\0') && (*s != uc))
	{
		s++;
	}
	if (*s == uc)
	{
		return ((char *)s);
	}
	return ((char *) NULL);
}
/*
int	main(void)
{
	const char	s1[] = "Hello, World!";
	char		c1;
	char		c2;

	c1 = 'W';
	c2 = 'z';
	printf("strchr: %s\n", strchr(s1, c1));
	printf("ft_strchr: %s\n\n", ft_strchr(s1, c1));
	printf("strchr: %s\n", strchr(s1, c2));
	printf("ft_strchr: %s\n", ft_strchr(s1, c2));
	return (0);
}
*/
