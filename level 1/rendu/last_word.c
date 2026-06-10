#include <unistd.h>

int main(int argc, char **argv)
{
	char *str;

	if (argc ==2)
	{
		str = argv[1];															//wir deklarieren str als das erste argument
		while (*str)															//solange wie in str was drinsteht
			str++;																//erhohen wir die stelle von str um an das ende zu kommen
		while (str > argv[1] && *(str - 1) != ' ' && *(str - 1) != '\t')	
			str--;
		while(*str)
			write(1, str++, 1);
	}
	write(1, "\n", 1);
	return 0;
}

str > argv[1] 		//nicht weiter als das erste zeichen
*(str - 1) != ' ' 	//solange das zeichen links von dem inhalt von str kein leerzeichen ist
*(str - 1) != '\t' 	//kein Tabulator

