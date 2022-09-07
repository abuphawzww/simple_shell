#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int a, b, p, q, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(str[a], d))
			a++;
		p = 0;
		while (!is_delim(str[a + p], d) && str[a + p])
			p++;
		s[b] = malloc((p + 1) * sizeof(char));
		if (!s[b])
		{
			for (p = 0; p < b; p++)
				free(s[p]);
			free(s);
			return (NULL);
		}
		for (q = 0; q < p; q++)
			s[b][q] = str[a++];
		s[b][q] = 0;
	}
	s[b] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int a, b, p, q, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
		    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; j < numwords; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		p = 0;
		while (str[a + p] != d && str[a + p] && str[a + p] != d)
			p++;
		s[b] = malloc((p + 1) * sizeof(char));
		if (!s[b])
		{
			for (p = 0; p < b; p++)
				free(s[p]);
			free(s);
			return (NULL);
		}
		for (q = 0; q < p; q++)
			s[b][q] = str[a++];
		s[b][q] = 0;
	}
	s[b] = NULL;
	return (s);
}
