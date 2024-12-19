/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:27:20 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/14 16:07:43 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	size_t	i;
	char	*csrc;
	char	*cdest;

	if (!src && !dst)
		return (NULL);
	csrc = (char *)src;
	cdest = (char *)dst;
	i = 0;
	while (i < num)
	{
		cdest[i] = (unsigned char)csrc[i];
		i++;
	}
	return (cdest);
}
// int main()
// {
//     char mystring[50] = "YELLLO TO FUN WORLD BABY!!!!!!!";
//     char dst[50] = "HELLO LADIES, ITS JOHNNY!";
//     printf("Before: %s\n", dst);
//     ft_memcpy(dst, mystring, 30);
//     printf("After: %s\n", dst);
//     return(0);
// }
