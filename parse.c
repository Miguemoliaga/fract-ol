/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:32:46 by mmartine          #+#    #+#             */
/*   Updated: 2023/08/03 18:47:38 by mmartine         ###   ########.fr       */
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
	//cambiar printf for ft_printf
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
			printf("El numero imaginario introducido es incorrecto.\n");
			printf("Cada parte del numero imaginario debe ser mayor que -2 ");
			printf("y menor que 2.\n");
			return (-1);
		}	
		return (2);
	}
	else
	{
		printf("Has introducido un argumento inválido.\n");
		printf("Los argumentos válidos son: MANDELBROT, JULIA\n");
		return (-1);
	}
}
