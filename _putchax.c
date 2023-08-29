#include "main.h"
/**
 * _putchax - print a character
 * @c: character input
 * Return: 1
 */
int _putchax(char c)
{
	return (write(1, &c, 1));
}
