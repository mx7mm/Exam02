#include <unistd.h>

void putnbr(int num)
{
	char digit; // digit ist die aktuele bzw hintere zahl

	if(num >= 10)
		putnbr(num / 10);
	digit = num % 10 + '0';
	write(1, &digit, 1);
}

int main(void)
{
	int i;
	i = 1;

	while (i <= 100)
	{
		if(i % 5 == 0 && i % 3 == 0)
			write(1, "fuzzbuzz", 8);
		else if(i % 5 == 0)
			write (1, "buzz", 4);
		else if(i % 3 == 0)
			write(1, "fizz", 4);
		else
			putnbr(i);
		i++;
		write(1, "\n", 1);
	}

}
