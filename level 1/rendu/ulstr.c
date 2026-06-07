#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[i])
		{
			if (argv[i] >= 'a' && argv[i] <= 'z')
				argv[i] -= 32;
			else if (argv[i] >= 'A' && argv[i] <= 'Z')
				argv[i] += 32;
			write(1, &argv[i++], 1);
		}
	}
	return (write(1, "\n", 1), 0);
}
