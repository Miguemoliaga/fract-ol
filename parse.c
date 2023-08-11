/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:32:46 by mmartine          #+#    #+#             */
/*   Updated: 2023/08/11 15:16:24 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	showleaks(void)
{
	system("leaks -q fractol");
}

int	crossclose(t_env *env)
{
	mlx_destroy_image(env->data->mlx, env->data->img);
	mlx_destroy_window(env->data->mlx, env->data->win);
	properclose(env);
	return (0);
}

int	parsecomp(char *arg, char *fix, int len)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(arg) != len)
		return (1);
	while (arg[i] && fix[i])
	{
		if (arg[i] != fix[i])
			return (1);
		i++;
	}
	if (arg[i] || fix[i])
		return (1);
	return (0);
}

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
	if (!parsecomp(arg[1], "MANDELBROT", 10) && i == 2)
		return (1);
	else if (!parsecomp(arg[1], "JULIA", 5) && i == 4)
	{
		num->fixreal = ft_strtod(arg[2]);
		num->fiximag = ft_strtod(arg[3]);
		if (!(validnum(arg[2]) && validnum(arg[3])) || (num->fixreal < -2
				&& num->fixreal > 2) || (num->fiximag < -2 || num->fiximag > 2))
			return (outputmsg(2));
		return (2);
	}
	else
		return (outputmsg(3));
}
