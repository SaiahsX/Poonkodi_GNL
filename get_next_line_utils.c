/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:43:03 by pchennia          #+#    #+#             */
/*   Updated: 2023/12/07 13:43:06 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int len)
{
	char	*result;
	int		cp;

	if (!str || !len)
		return (NULL);
	cp = -1;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (++cp < len)
		result[cp] = str[cp];
	result[cp] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	int		s2_len;
	int		tot_len;
	char	*result;

	s2_len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2, s2_len));
	tot_len = s2_len + ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (tot_len + 1));
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	tot_len = 0;
	while (s1[i])
		result[tot_len++] = s1[i++];
	i = 0;
	while (s2[i])
		result[tot_len++] = s2[i++];
	result[tot_len] = '\0';
	free(s1);
	return (result);
}
