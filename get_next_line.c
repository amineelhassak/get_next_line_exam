#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 3
#endif

int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return 0;
	while (str[i])
		i++;
	return (i);	
}

int ft_strchr(char *str,char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1,char *s2)
{
	int i = 0;
	int j = 0;
	char *s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	return (s[j] = '\0', free(s1), s);
}

char	*read_all(char *save, int fd)
{
	int handel_var = 1;
	char *str = malloc(BUFFER_SIZE);
	while (handel_var && !ft_strchr(save,'\n'))
	{
		handel_var = read(fd,str,BUFFER_SIZE);
		str[handel_var] = '\0';
		save = ft_strjoin(save, str);
	}
	return (free(str), save);
}

char	*gv_line(char *save,int	*len)
{
	char	*line;
	if (!*save)
		return (NULL);
	while (save[*len] && save[*len] != '\n')
		(*len)++;
	(save[*len] == '\n') && ((*len)++);
	(1) && (line = malloc(*len + 1), *len = -1);
	while (save[++(*len)] && save[*len] != '\n')
		line[(*len)] = save[(*len)];
	(save[*len] == '\n') && (line[(*len)++] = '\n');
	return (line[(*len)] = '\0', line);
}

char	*modifie_save(char *save, int len)
{
	char	*n_save;
	int		i = 0;
	n_save = malloc(ft_strlen(save) - len + 1);
	while (save[len])
		n_save[i++] = save[len++];
	return (n_save[i] = '\0' , free(save), n_save);
}

char	*get_next_line(int fd)
{
	char			*line = NULL;
	int				len = 0;
	static char		*save;
	if (!save)
		(1) && (save = malloc(1), save[0] = '\0');
	save = read_all(save,fd);
	line = gv_line(save, &len);
	save = modifie_save(save, len);
	return (line);
}

