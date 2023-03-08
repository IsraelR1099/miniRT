/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:55:36 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/08 09:58:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		b;
	int		ll;
	int		end;
}	t_window;

void	ft_my_mlx_pxput(t_window *mlx, int x, int y, int colour);

#endif
