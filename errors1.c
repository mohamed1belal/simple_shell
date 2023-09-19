#include "shell.h"
/**
* _erratoi - converts a string to an integer
* @s: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
int _erratoi(const char *s)
{{
int result = 0;
int sign = 1;

if (*s == '+')
{
s++;
}
else if (*s == '-')
{
sign = -1;
s++;
}

for (; *s != '\0'; s++)
{
if (*s >= '0' && *s <= '9')
{
int digit = *s - '0';

if (result > (INT_MAX - digit) / 10)
{
return (-1);
}

result = result * 10 + digit;
}
else
{
return (-1);
}
}

return (result *sign);
}
/**
* print_error - prints an error message
* @info: the parameter & return info struct
* @estr: string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
void print_error(const char *filename, int line_count,
		const char *command, const char *error)
{
fprintf(stderr, "%s: %d: %s: %s\n", filename, line_count, command, error);
}
/**
* print_d - function prints a decimal (integer) number (base 10)
* @input: the input
* @fd: the filedescriptor to write to
*
* Return: number of characters printed
*/
int print_d(int input, FILE *file)
{
int count = 0;
unsigned int abs_value = (input < 0) ? -input : input;

if (input < 0)
count += fprintf(file, "-");

int divisor = 1;
while (abs_value / divisor >= 10)
divisor *= 10;

while (divisor != 0)
int digit = abs_value / divisor;
abs_value %= divisor;
divisor /= 10;
count += fprintf(file, "%d", digit);

return (count);
}
/**
* convert_number - converter function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
*
* Return: string
*/
char *convert_number(long int num, int base, int flags)
{
static char buffer[50];
const char *array = (flags & CONVERT_LOWERCASE) ?
	"0123456789abcdef" : "0123456789ABCDEF";
char sign = 0;
char *ptr = &buffer[49];
*ptr = '\0';

if (!(flags & CONVERT_UNSIGNED) && num < 0)
num = -num;
sign = '-';

do {
*--ptr = array[num % base];
num /= base;
} while (num != 0);

if (sign)
*--ptr = sign;

return (ptr);
}
/**
* remove_comments - function replaces first instance of '#' with '\0'
* @buf: address of the string to modify
*
* Return: Always 0;
*/
void remove_comments(char *buf)
{
for (int i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == '#' && (i == 0 || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
}

int main(void))
{
char str[] = "12345";
int num = erratoi(str);
printf("Converted number: %d\n", num);

char filename[] = "example.c";
int line_count = 10;
char command[] = "my_command";
char error[] = "Error message";
print_error(filename, line_count, command, error);

int number = 9876;
print_d(number, stdout);
printf("\n");

long int num2 = -54321;
char *converted = convert_number(num2, 16, 0);
printf("Converted number: %s\n", converted);

char buf[] = "This is a # comment";
remove_comments(buf);
printf("Without comments: %s\n", buf);

return (0);
}
