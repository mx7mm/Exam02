#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[i])
		{
			if (argv[i] >= 'A' && argv[i] <= 'Z')
				argv[i] = (argv[i] - 'A' + 1) % 26 + 'A';
			else if (argv[i] >= 'a' && argv[i] <= 'z')
				argv[i] = (argv[i] - 'a' + 1) % 26 + 'a';
			
			write(1, &argv[i++], 1);
		}
	}
	return (write(1, "\n", 1), 0);
}
