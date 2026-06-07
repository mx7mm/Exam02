#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[i])
			i++;
		while (--i >= 0)
			write(1, &argv[i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
