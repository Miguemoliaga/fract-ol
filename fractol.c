/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:15:55 by mmartine          #+#    #+#             */
/*   Updated: 2023/10/27 17:27:50 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	properclose(t_env *env)
{
	free(env->data);
	free(env->dims);
	free(env->num);
	free(env);
	exit(0);
}

int	escape(int keynum, t_env *env)
{
	if (keynum == 53)
	{
		mlx_destroy_image(env->data->mlx, env->data->img);
		mlx_destroy_window(env->data->mlx, env->data->win);
		properclose(env);
	}
	return (0);
}

t_env	*envinit(t_env *env)
{
	t_dims	*dims;
	t_num	*num;
	t_img	*data;

	num = malloc(sizeof(t_num));
	data = malloc(sizeof(t_img));
	dims = malloc(sizeof(t_dims));
	dims->xmin = -2.0;
	dims->xmax = 2.0;
	dims->ymin = -1.12;
	dims->ymax = 1.12;
	env->num = num;
	env->dims = dims;
	env->data = data;
	env->dims->zoom = 0.5;
	return (env);
}

int	handle_mouse(int button, int x, int y, t_env *env)
{
	double	xoffset;
	double	yoffset;
	t_dims	*aux;

	aux = env->dims;
	xoffset = aux->xmin +(x * (aux->xmax - aux->xmin) / WIDTH);
	yoffset = aux->ymin + (y * (aux->ymax - aux->ymin) / HEIGHT);
	if (button == 4)
	{
		aux->xmin = xoffset + (aux->xmin - xoffset) * (1 / 1 - aux->zoom);
		aux->xmax = xoffset + (aux->xmax - xoffset) * (1 / 1 - aux->zoom);
		aux->ymin = yoffset + (aux->ymin - yoffset) * (1 / 1 - aux->zoom);
		aux->ymax = yoffset + (aux->ymax - yoffset) * (1 / 1 - aux->zoom);
	}
	else if (button == 5)
	{
		aux->xmin = xoffset - (aux->xmin - xoffset) / (aux->zoom - 1);
		aux->xmax = xoffset - (aux->xmax - xoffset) / (aux->zoom - 1);
		aux->ymin = yoffset - (aux->ymin - yoffset) / (aux->zoom - 1);
		aux->ymax = yoffset - (aux->ymax - yoffset) / (aux->zoom - 1);
	}
	printfract(env->data, env->num, env->dims, env->num->sw);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	//atexit(showleaks);
	if (argc < 2 || argc > 4)
	{
		outputmsg(1);
		exit(0);
	}
	env = malloc(sizeof(t_env));
	env = envinit(env);
	env->num->sw = getfractol(argv, argc, env->num);
	if (env->num->sw == -1)
		properclose(env);
	env->data->mlx = mlx_init();
	env->data->win = mlx_new_window(env->data->mlx, WIDTH, HEIGHT, "FRACTOL");
	env->data->img = mlx_new_image(env->data->mlx, WIDTH, HEIGHT);
	env->data->addr = mlx_get_data_addr(env->data->img, &env->data
			->bpp, &env->data->line_length, &env->data->endian);
	printfract(env->data, env->num, env->dims, env->num->sw);
	mlx_key_hook(env->data->win, escape, env);
	mlx_hook(env->data->win, 4, 0, handle_mouse, env);
	mlx_hook(env->data->win, 5, 0, handle_mouse, env);
	mlx_hook(env->data->win, 17, 0, crossclose, env);
	mlx_loop(env->data->mlx);
}
