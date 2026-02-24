#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	int	c;

	while ((c = fgetc(f)) != EOF))
	{
		if (!isspace(c))
		{
			ungetc(c, f);
			break ;
		}
	}
	if (ferror(f))
			return (-1);
    return (1);
}

int match_char(FILE *f, char c)
{
    int	ch = fgetc(f);
	if (ch == EOF)
		return (-1)
	if (ch != c)
	{
		unget(ch, f);
		return 0;
	}
    return (1);
}

int scan_char(FILE *f, va_list ap)
{
    int c = fgetc(f);
	if (c == EOF)
		return (0);
	char	*ptr = va_arg(ap, char *);
	*ptr = char(c);
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
    int	n, neg = 0;
	int	num = 0;
	int	read = 0;

	while ((c = fgetc(f)) != EOF && !isspace(c))
		;
	if (c == EOF)
		return (0);
	if (c == '-' || c == '+')
	{
		neg = (c == '-')
		c = fgetc(f);
	}
	while (c != EOF && isdiget(c))
	{
		num = num * 10 + (c - '0');
		read = 1;
		c = fgetc(c);
	}
	if (c != EOF)
		unget(c, f);
	if (!read)
		return (0);
	if (neg)
		num = -num;
	int	*ptr = va_arg(ap, int *);
	*ptr = num;
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
    char *str = va_arg(ap, char *);
    int c, read = 0;

    // Skip initial spaces
    while ((c = fgetc(f)) != EOF && isspace(c))
        ;
    if (c == EOF)
        return 0;
    do
    {
        if (isspace(c) || c == EOF)
        {
            ungetc(c, f);
            break;
        }
        str[read++] = (char)c;
        c = fgetc(f);
    } while (c != EOF);
    str[read] = '\0';
    return read > 0 ? 1 : 0;
    return (0);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;
    va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
