#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strjoin_c(char const *s1, char s2)
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

int is_quote(char line, int quote)
{
	int result = quote;

	if (line == '\'')
	{
		if (quote == 1)
			result = 0;
		else if (quote == 2)
			result = 2;
		else
			result = 1;
	}
	else if (line == '\"')
	{
		if (quote == 2)
			result = 0;
		else if (quote == 1)
			result = 1;
		else
			result = 2;
	}
	return (result);
}

void	test_parse(char *line)
{
	char *str = NULL;
	int index = 0;
	int pipe = 0;
	int quote = 0;
	int space = 1;

	while (*line)
	{
		quote = is_quote(*line, quote);
		if (*line == ' ' && space == 0 && quote == 0)
		{
			printf("[%d] : %s\n", index, str);
			free (str);
			space = 1;
			index++;
		}
		else if (*line == '|' && quote == 0)
		{
			if (space == 0)
			{
				printf("[%d] : %s\n", index, str);
				free (str);
			}
			if (pipe == 1)
			{
				printf("test exit : ||\n");
				exit(1);
			}
			index = 0;
			space = 1;
			pipe = 1;
		}
		else
		{
			if ((*line == ';' || *line == '\\') && quote == 0)
			{
				printf("test exit : %s\n", line);
				exit(1);
			}
			if (!(*line == ' ' && space == 1))
			{
				str = strjoin_c(str, line[0]);
				space = 0;
				pipe = 0;
			}
		}
		line++;
	}
	if (quote != 0)
	{
		printf("test exit : quotes error\n");
		exit(1);
	}
	if (str != NULL)
	{
		printf("[%d] : %s\n", index, str);
		free (str);
	}
}

int main()
{
	char *line = "ls;";
	test_parse(line);
}
