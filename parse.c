/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:32:46 by mmartine          #+#    #+#             */
/*   Updated: 2023/08/10 15:51:02 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	validnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 43 || str[i] == 45)
		i++;
	if (!str[i])
		return (0);
	if (str[i] == 48)
	{
		i++;
		if (str[i] == 46)
			i++;
	}
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			i++;
		else
			return (0);
	}
	return (1);
}

int	getfractol(char **arg, int i, t_num *num)
{
	int	len;

	len = ft_strlen(arg[1]);
	if (!ft_strncmp(arg[1], "MANDELBROT", len) && i == 2)
		return (1);
	else if (!ft_strncmp(arg[1], "JULIA", len) && i == 4)
	{
		num->fixreal = ft_strtod(arg[2]);
		num->fiximag = ft_strtod(arg[3]);
		if (!(validnum(arg[2]) && validnum(arg[3])) || (num->fixreal < -2
				&& num->fixreal > 2) || (num->fiximag < -2 || num->fiximag > 2))
		{
			ft_printf("El numero imaginario introducido es incorrecto.\n");
			ft_printf("Cada parte del numero imaginario debe ser mayor que ");
			ft_printf("-2 y menor que 2.\n");
			return (-1);
		}	
		return (2);
	}
	else
	{
		ft_printf("Has introducido un argumento inválido.\n");
		ft_printf("Los argumentos válidos son: MANDELBROT, JULIA\n");
		return (-1);
	}
}
