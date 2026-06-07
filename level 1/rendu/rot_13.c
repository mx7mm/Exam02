#include <unistd.h>

int main(int argc, char **argv)
{
	char *str;

	if (argc == 2)
	{
		str = argv;
		while (*str)
		{
			if ((*str >= 'A' && *str <= 'Z'))
				*str = (*str - 'A' + 13) % 26 + 'A';
			else if (*str >= 'a' && *str <= 'z')
				*str = (*str - 'a' + 13) % 26 + 'a';
			write(1, str++, 1);
		}
	}
	return (write(1, "\n", 1), 0);
}
