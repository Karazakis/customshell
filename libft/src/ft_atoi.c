/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:24:08 by dimolin2          #+#    #+#             */
/*   Updated: 2023/08/17 15:11:38 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	k;
	int	sgn;
	int	toi;

	k = 0;
	toi = 0;
	sgn = 1;
	while (nptr[k] == 32 || (nptr[k] >= 9 && nptr[k] <= 13))
		k++;
	if (nptr[k] == '-' || nptr[k] == '+')
	{
		if (nptr[k] == '-')
			sgn = -1;
		k++;
	}
	while (nptr[k] >= '0' && nptr[k] <= '9')
	{
		toi *= 10;
		toi += nptr[k] - 48;
		k++;
	}
	return (toi * sgn);
}
