/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:43:11 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/28 13:31:54 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_point	get_lines(t_point point, char *line)
{
	int	y;
	int	i;

	y = 0;
	point.lbl_err = 0;
	point.label = (char **)malloc(sizeof(char *) * 273);
	while (get_next_line(point.fd, &line) != 0)
	{
		i = -1;
		point.label[y] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (ft_strncmp(line, ".", 1) == 0)
			point.lbl_err = -1;
		while (ft_strncmp(line, "#", 1) != 0
				&& ft_strncmp(line, "\0", 1) != 0 && line[++i])
			point.label[y][i] = line[i];
		if (i != -1)
			point.label[y][i] = '\0';
		y++;
		free(line);
	}
	point.lbl_size = y;
	point.label[y] = "";
	return (point);
}

t_point	get_comment(t_point point, char *line)
{
	int	i;
	int	l;
	int	len;

	i = 0;
	l = 0;
	while (line[i] != '"')
		i++;
	len = ft_strlen(line) - (i + 2);
	if (len <= 2048)
	{
		while (line[++i] != '"' && l <= 2048)
		{
			point.comment[l] = line[i];
			l++;
		}
		point.comment[l] = '\0';
		point.i++;
	}
	return (point);
}

t_point	get_name(t_point point, char *line)
{
	int		i;
	int		l;
	int		len;

	i = 0;
	l = 0;
	while (line[i] != '"')
		i++;
	len = ft_strlen(line) - (i + 2);
	if (len <= 128)
	{
		while (line[++i] != '"' && l <= 128)
		{
			point.name[l] = line[i];
			l++;
		}
		point.name[l] = '\0';
		point.i++;
	}
	return (point);
}

int		file_open(t_point point)
{
	if (point.fd < 0)
	{
		print_error(2);
		return (-1);
	}
	return (0);
}

int		text(t_point point, char *file_name)
{
	char	*line;

	point.file = ft_strcpy(point.file, file_name);
	point.fd = open(file_name, O_RDWR);
	if (file_open(point) == -1)
		return (-1);
	while (get_next_line(point.fd, &line) != 0 && point.i != 2)
	{
		if (ft_strncmp(line, ".name", 5) == 0)
			point = get_name(point, line);
		if (ft_strncmp(line, ".comment", 8) == 0)
			point = get_comment(point, line);
		free(line);
	}
	if (point.i != 2)
		return (-1);
	point = get_lines(point, line);
	if (point.fd_2 == -1 || (point.lbl_err == -1))
		return (-1);
	print(point);
	ft_free(point);
	return (0);
}
