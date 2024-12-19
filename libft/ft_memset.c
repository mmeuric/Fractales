/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:28:02 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 14:28:12 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *k, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)(k + i)) = (unsigned char)c;
		i++;
	}
	return (k);
}
/*
int	main(void)
{
	char str1[50];
	char str2[50];

	strcpy(str1, "Bonjour, monde!");
	strcpy(str2, "Bonjour, monde!");

	printf("Avant ft_memset: %s\n", str1);

	ft_memset(str1, 'X', 3);

	printf("Après ft_memset: %s\n", str1);

	memset(str2, 'X', 3);

	printf("Après memset: %s\n", str2);

	return (0);
}*/
