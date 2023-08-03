/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:55:28 by mmartine          #+#    #+#             */
/*   Updated: 2023/08/03 18:38:07 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r)
{
	return (t << 24 | ((r * 2) % 256) << 16
		| ((r * 5) % 256) << 8 | (r * 3) % 256);
}

int	mandelbrot(t_num *num)
{
	int		it;
	double	zx;
	double	zy;
	double	tmp;

	zx = 0;
	zy = 0;
	it = 0;
	while ((zx * zx + zy * zy < 4) && (it < 100))
	{
		tmp = zx * zx - zy * zy + num->real;
		zy = 2 * zx * zy + num->imag;
		zx = tmp;
		it++;
	}
	return (it);
}

int	julia(t_num *num)
{
	int		it;
	double	zx;
	double	zy;
	double	tmp;

	zx = num->real;
	zy = num->imag;
	it = 0;
	while ((zx * zx + zy * zy < 4) && (it < 100))
	{
		tmp = zx * zx - zy * zy;
		zy = 2 * zx * zy + num->fiximag;
		zx = tmp + num->fixreal;
		it++;
	}
	return (it);
}

int	selectfract(t_num *num, int sw)
{
	if (sw == 2)
		return (julia(num));
	else if (sw == 1)
		return (mandelbrot(num));
	return (0);
}

void	printfract(t_img *data, t_num *num, t_dims *dims, int sw)
{
	int		i;
	int		j;
	char	*dst;
	int		color;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			num->real = dims->xmin + (j * (dims->xmax - dims->xmin)) / WIDTH;
			num->imag = dims->ymin + (i * (dims->ymax - dims->ymin)) / HEIGHT;
			color = selectfract(num, sw);
			dst = data->addr + (i * data->line_length + j * (data->bpp / 8));
			*(unsigned int *)dst = create_trgb(0, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
