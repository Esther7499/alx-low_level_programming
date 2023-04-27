#include "main.h"
#include <stdio.h>

/**
 *_isupper - A function that checks for uppercase character.
 *@c: An input character
 *Return: 1 if c is uppercase or 0 otherwise
 */

int _isupper(int c)
{
	char i;
	int isupper;

	i = 'A';
	isupper = 0;
	while (i <= 'Z')
	{
		if (i == c)
		{
			isupper = 1;
			break;
		}
		else
		{
			isupper = 0;
		}
		i++;
	}
	return (isupper);
}
