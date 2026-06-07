#include <unistd.h>															//bib fur write 

int main(int argc, char **argv)
{
	int i;																	//zahler deklarieren

	i = 0;																	//zahler initialisieren

	if (argc == 2) 															//argument anzahl prufung wenn nicht genau zwei argumente
	{

		while (argv[1][i] == ' ' || argv[1][i] == '\t') 						//solange momentane position tab oder leerzeichen ist
			i++; 																//die aktuelle stelle uberspringne 
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')	//solange aktuelles zeichen nicht ende \0 ist oder leerzeichen oder tab
			write(1, &argv[1][i++], 1);											//schreibe aktuelles zeichen
	}
		write(1, "\n", 1);
		return 0;																//null zuruckgeben
}

/*wir prufen ob genau zwei argumente da sind wenn ja uberspringen wir
 alle nicht buchstaben beim wort angekommen drucken wir das aktuelle 
 zeichen bis eine unterbrechung kommt*/
