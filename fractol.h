/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:16:15 by mmartine          #+#    #+#             */
/*   Updated: 2023/08/10 16:53:36 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 700 
# define WIDTH 1280
# include "mlx.h"
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

typedef struct s_img {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	double	zoom;	
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_num{
	double	real;
	double	imag;
	double	fixreal;
	double	fiximag;
	int		sw;
}			t_num;

typedef struct s_dims{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom;
}			t_dims;

typedef struct s_env{
	t_dims	*dims;
	t_num	*num;
	t_img	*data;
}			t_env;

void	printfract(t_img *data, t_num *num, t_dims *dims, int sw);
int		getfractol(char **arg, int argc, t_num *num);
int		handle_mouse(int button, int x, int y, t_env *env);
void	properclose(t_env *env);
int		crossclose(t_env *env);
void	showleaks(void);

#endif