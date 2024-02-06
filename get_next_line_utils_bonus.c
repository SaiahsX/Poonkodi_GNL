/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:44:11 by pchennia          #+#    #+#             */
/*   Updated: 2023/12/07 13:44:13 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	cp;

	cp = 0;
	if (!s)
		return (0);
	while (s[cp])
		cp++;
	return (cp);
}

char	*ft_strdup(char *str, int len)
{
	char	*result;
	int		cp;

	if (!str || !len)
		return (NULL);
	cp = -1;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (++cp < len)
		result[cp] = str[cp];
	result[cp] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	cp;
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
	cp = 0;
	tot_len = 0;
	while (s1[cp])
		result[tot_len++] = s1[cp++];
	cp = 0;
	while (s2[cp])
		result[tot_len++] = s2[cp++];
	result[tot_len] = '\0';
	free(s1);
	return (result);
}
