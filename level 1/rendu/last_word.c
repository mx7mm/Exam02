#include <unistd.h>

int main(int argc, char **argv)
{
	char *str;

	if (argc ==2)
	{
		str = argv[1];
		while (*str)
			str++;
		while (str > argv[1] && *(str - 1) != ' ' && *(str - 1) != '\t')
			str--;
		while(*str)
			write(1, str++, 1);
	}
	write(1, "\n", 1);
	return 0;
}