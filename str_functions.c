#include "shell.h"

/**
 * _strrev - Function that reverse a string
 * @str: string to reverse
 * Return: reversed string
 */

char *_strrev(char *str)
{
	int i;
	int len = 0;
	char c;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (str);
}

/**
 * _itoa - Function that converts any value from int to string
 * @i: Value entered type integer
 * @strout: Standar Out
 * @base: Base to convert values
 * Return: A value type char
 */

char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	_strrev(strout);
	return (strout);
}

/**
* _strcat - function that concatenates two strings
* @dest: string one where concatenated string is saved.
* @src: string two that will be copied in dest.
* Return: concatenated string.
*/

char *_strcat(char *dest, char *src)
{
	int i = 0, n = 0;

	i = _strlen(dest);

	for (n = 0; src[n] != '\0'; n++)
	{
		dest[i] = src[n];
		i++;
	}
	return (dest);
}

/**
* _strcmp - function that compares two strings.
* @s1: string 1 to compare.
* @s2: string 2 to compare.
* Return: 0 if strings are equal, 1 if strings are different.
*/

int _strcmp(char *s1, char *s2)
{
	int k = 0, equal = 0, dif = 0, len1 = _strlen(s1), len2 = _strlen(s2);

	for (k = 0; s1[k] != '\0' && s2[k] != '\0'; k++)
	{
		if (s1[k] == s2[k])
		{
			equal++;
		}
		if (s1[k] != s2[k])
		{
			dif++;
		}
	}

	if (dif > 0 || len1 != len2)
		return (1);

	return (0);
}

/**
 * _strdup -  function that duplicates a string
 * in a newly allocated space in memory.
 * @str: string to be copied.
 * Return: Duplicated string in success.
 */

char *_strdup(char *str)
{
	int i = 0, j = 0;
	char *new_s = NULL;

	if (str == NULL)
		return (NULL);

	i = _strlen(str);

	new_s = malloc(sizeof(char) * (i + 1));

	if (new_s == NULL)
	{
		perror("./hsh");
		return (NULL);
	}

	if (i == 0 || new_s == 0)
		return (NULL);

	while (j < (i + 1))
	{
		new_s[j] = str[j];
		j++;
	}

	return (new_s);
}
