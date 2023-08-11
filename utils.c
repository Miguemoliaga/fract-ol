/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:08:42 by mmartine          #+#    #+#             */
/*   Updated: 2023/08/11 15:24:08 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	outputmsg(int ex)
{
	if (ex == 1)
	{
		ft_printf("Número de argumentos inválido.\nLos argumentos validos ");
		ft_printf("son:\nMANDELBROT, sin mas argumentos\nJULIA con dos indices");
		ft_printf(" númericos decimales comprendidos entre -2 y 2\n");
	}
	else if (ex == 2)
	{
		ft_printf("El número imaginario introducido es incorrecto.\n");
		ft_printf("Cada parte del numero imaginario debe ser mayor que ");
		ft_printf("-2 y menor que 2.\n");
	}
	else if (ex == 3)
	{
		ft_printf("Has introducido un argumento inválido.\n");
		ft_printf("Los argumentos válidos son: MANDELBROT y JULIA\n");
	}
	ft_printf("Ejemplos válidos recomendados:\n./fractol MANDELBROT\n");
	ft_printf("./fractol JULIA 0.285 0.01\n./fractol JULIA -0.7269 0.1889\n");
	ft_printf("./fractol JULIA 0 0.8\n./fractol JULIA -0.8 0.156\n");
	return (-1);
}
