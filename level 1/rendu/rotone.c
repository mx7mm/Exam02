#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];
		while (*s)
		{
			char c = *s;
			if (c == 'Z')
				c = 'A';
			else if (c == 'z')
				c = 'a';
			else if ((c >= 'A' && c <= 'Y') || (c >= 'a' && c <= 'y'))
				c++;
			write(1, &c, 1);
			s++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
