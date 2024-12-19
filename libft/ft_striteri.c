/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:35:33 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:35:47 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, s + i);
}
/*
void	to_uppercase_with_index(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - ('a' - 'A');  // Convert to uppercase if index is even
	else if (i % 2 != 0 && *c >= 'A' && *c <= 'Z')
		*c = *c + ('a' - 'A');  // Convert to lowercase if index is odd
}

int	main(void)
{
	char	str[] = "hello world";

	printf("Avant ft_striteri: %s\n", str);
	ft_striteri(str, to_uppercase_with_index);
	printf("Après ft_striteri: %s\n", str);
	return (0);
}
*/
