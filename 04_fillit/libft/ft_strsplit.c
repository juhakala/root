/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:33:39 by jhakala           #+#    #+#             */
/*   Updated: 2019/10/30 18:54:48 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(const char *str, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char	*ft_make_string(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		len;
	char	**s;

	i = 0;
	j = 0;
	len = ft_count(str, c);
	if (!str || !c)
		return (0);
	if (!(s = (char **)malloc(sizeof(s) * (len + 2))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < len && str[i])
	{
		s[j] = ft_make_string(str, c, &i);
		j++;
	}
	s[j] = NULL;
	return (s);
}
