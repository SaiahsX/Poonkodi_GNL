/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:42:39 by pchennia          #+#    #+#             */
/*   Updated: 2023/12/12 12:38:42 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		*s_temp[1024];
	char			*buffer;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(s_temp[fd]), s_temp[fd] = NULL, NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(s_temp[fd]);
		s_temp[fd] = NULL;
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		s_temp[fd] = ft_strjoin(s_temp[fd], buffer);
		if (found_nl(s_temp[fd]))
			break ;
	}
	free_buffer(buffer);
	return (ft_printline(&s_temp[fd]));
}

void	free_buffer(char *buffer)
{
	if (buffer)
		free(buffer);
	buffer = NULL;
}

int	found_nl(char	*s_temp)
{
	int		cp;

	if (!s_temp)
		return (0);
	cp = -1;
	while (s_temp[++cp])
		if (s_temp[cp] == '\n')
			return (1);
	return (0);
}

char	*ft_printline(char **s_temp)
{
	int		n_pos;
	char	*result;
	char	*str;

	if (!*s_temp)
		return (NULL);
	str = *s_temp;
	n_pos = 0;
	while (str[n_pos] && str[n_pos] != '\n')
		n_pos++;
	if (str[n_pos] == '\n')
		n_pos++;
	result = ft_strdup(str, n_pos);
	if (result == NULL)
	{
		free(*s_temp);
		*s_temp = NULL;
		return (result);
	}
	*s_temp = ft_strdup(str + n_pos, ft_strlen(str + n_pos));
	if (str)
		free(str);
	str = NULL;
	return (result);
}

/*int main(void)
{
	int fd = open("fd", O_RDONLY);
	char	*str;
	int		i = 0;
	
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	return (0);
}*/
