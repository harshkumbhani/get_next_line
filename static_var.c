/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:22:13 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/08 09:51:34 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_function(void)
{
	static int static_num1 = 0;

	static_num1++;
	return (static_num1);
}

int	function2(int num)
{
	return (num++);
}

int	main(void)
{
	printf("Itr1: %d\n",ft_function());
	printf("Itr2: %d\n",ft_function());
	printf("Itr3: %d\n",ft_function());
	return (0);
}