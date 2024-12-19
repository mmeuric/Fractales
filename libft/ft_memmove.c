/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:27:45 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/16 00:12:46 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if ((!dst && !src) && len > 0)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

/*
int	main(void)
{
	char overlap1[] = "Hello, World!";
	memmove(overlap1 + 7, overlap1, 6);
	printf("Overlap memmove: %s\n", overlap1);

	char overlap2[] = "Hello, World!";
	ft_memmove(overlap2 + 7, overlap2, 6);
	printf("Overlap ft_memmove: %s\n", overlap2);

	return (0);
}*/
