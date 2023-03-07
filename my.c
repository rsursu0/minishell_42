#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin_char(char const *s1, char s2)
{
	char	*ret;
	size_t	s1_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (strdup(&s2));
	else if (!s2)
		return (strdup(s1));
	s1_len = strlen(s1);
	ret = (char *)malloc(sizeof(char) * (s1_len + 2));
	if (!ret)
		return (0);
	strlcpy(ret, s1, s1_len + 1);
	strlcpy(ret + s1_len, &s2, 2);
	return (ret);
}

int	parse_set_quotes(char line, int quotes)
{
	int	result;

	result = quotes;
	if (line == '\'')
	{
		if (quotes == 1)
			result = 0;
		else if (quotes == 2)
			result = 2;
		else
			result = 1;
	}
	else if (line == '\"')
	{
		if (quotes == 2)
			result = 0;
		else if (quotes == 1)
			result = 1;
		else
			result = 2;
	}
	return (result);
}

void	test_parse(char *line)
{
	char	*str = NULL;
	int		quotes = 0;
	int		index = 0;
	int		space = 1;
	int		pipe = 0;

	while (*line)
	{
		quotes = parse_set_quotes(*line, quotes);
		if (*line == ' ' && space == 0 && quotes == 0)
		{
			printf("[%d] : %s\n", index, str);
			free(str);
			space = 1;
			index++;
		}
		else if (*line == '|' && quotes == 0)
		{
			if (space == 0)
			{
				printf("[%d] : %s\n", index, str);
				free(str);
			}
			if (pipe == 1)
			{
				printf("test exit: ||\n");
				exit(1);
			}
			index = 0;
			space = 1;
			pipe = 1;
		}
		else
		{
			if ((*line == ';' || *line == '\\') && quotes == 0)
			{
				printf("test exit: %c\n", *line);
				exit(1);
			}
			if (!(*line == ' ' && space == 1))
			{
				str = ft_strjoin_char(str, line[0]);
				space = 0;
				pipe = 0;
			}
		}
		line++;
	}
	if (quotes != 0)
	{
		printf("test exit: quotes error\n");
		exit(1);
	}
	if (str != NULL)
	{
		printf("[%d] : %s\n", index, str);
		free(str);
	}
}

int main(void)
{
	char *line = "pipe 1 | pipe 2";
	test_parse(line);
}
