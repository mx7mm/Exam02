# 42 Exam Rank 02 - Level 1 Roadmap

Dieses Dokument enthält alle potenziellen Aufgaben aus dem Pool von **Level 1** im *Common Core* des 42-Netzwerks sowie die exakten Fähigkeiten, die du für jede Aufgabe beherrschen musst.

---

## Grundlegende Kernkompetenzen für Level 1

Um dieses Level mit 100/100 Punkten zu bestehen, musst du im Schlaf beherrschen:
1. **Das `argv`-Prinzip:** Sicheres Navigieren durch ein zweidimensionales Array (`argv[1][i]`), ohne Speicherfehler (*Segmentation Faults*) zu verursachen.
2. **Die ASCII-Mathematik:** Wissen, dass `'A' = 65`, `'a' = 97` und der Abstand dazwischen exakt `32` beträgt.
3. **Der Kontrollfluss:** Der bewusste Einsatz von `if`, `else if` und `else`, um unkontrollierte Kettenreaktionen im Speicher zu verhindern.
4. **Whitespaces filtern:** Leerzeichen (`' '`) und Tabulatoren (`'\t'`) gezielt als Trenner oder Überspring-Signal nutzen.

---

## Aufgabenübersicht & Anforderungen


| Aufgabenname | Typ | Was das Programm tun muss | Das musst du dafür können |
| :--- | :--- | :--- | :--- |
| **`fizzbuzz`** | Programm | Zählt von 1 bis 100. Ersetzt Vielfache von 3 durch "fizz", von 5 durch "buzz", von beiden durch "fizzbuzz". | Mathematische Zerlegung von Zahlen (`/ 10` und `% 10`) für eine eigene Druckfunktion (`putnbr`), da `printf` verboten ist. Modulo-Hierarchie beachten. |
| **`first_word`** | Programm | Erhält einen String und gibt ausschließlich das allererste echte Wort aus, gefolgt von einem `\n`. | **Whitespaces überspringen:** Eine `while`-Schleife bauen, die am Anfang alle Leerzeichen/Tabs ignoriert, das Wort druckt und beim nächsten Leerzeichen sofort stoppt. |
| **`last_word`** | Programm | Erhält einen String und gibt ausschließlich das allerletzte Wort aus. | **Rückwärts-Navigation:** Entweder den String bis zum `\0` ablaufen und von dort rückwärts das Wort fixieren, oder Whitespaces am String-Ende gezielt ignorieren. |
| **`rev_print`** | Programm | Gibt einen im Terminal übergebenen String komplett rückwärts aus. | **Längenmessung & Dekrementierung:** Erst das String-Ende finden, dann den Index-Zähler mittels `i--` rückwärts bis zur Position 0 laufen lassen. |
| **`rotone`** | Programm | Verschiebt jeden Buchstaben um 1 Position im Alphabet nach vorne (`a` ➔ `b`, `z` ➔ `a`). Fallhöhe bleibt gleich. | **Gezielte Ausnahmen:** `else if`-Weichen für die Endbuchstaben `z` und `Z` einbauen, damit sie wieder auf `a` bzw. `A` zurückgesetzt werden. |
| **`rot_13`** | Programm | Verschiebt jeden Buchstaben um 13 Positionen nach vorne (rotiert das halbe Alphabet). | **Halbierungs-Logik:** Das Alphabet gedanklich in der Mitte teilen (`m`/`M`). Bis dorthin `+13` rechnen, ab dort `-13` rechnen, um den Überlauf abzufangen. |
| **`ulstr`** | Programm | Invertiert die Groß- und Kleinschreibung eines Strings. Alle anderen Zeichen bleiben unberührt. | **ASCII-Verschiebung:** Buchstabenbereiche abgrenzen und den magischen Wert von `32` addieren (wird klein) oder subtrahieren (wird groß). |
| **`repeat_alpha`** | Programm | Gibt jeden Buchstaben so oft aus, wie es seiner Position im Alphabet entspricht (`a` = 1-mal, `c` = 3-mal). | **Dynamische Schleifen:** Die Anzahl der inneren Schleifendurchläufe live aus dem ASCII-Wert berechnen (`c - 'a' + 1` oder `c - 'A' + 1`). |
| **`search_and_replace`** | Programm | Ersetzt in einem String (Argument 1) alle Vorkommen eines Zeichens (Argument 2) durch ein anderes (Argument 3). | **Multi-Argument-Handling:** Den Sicherheitscheck zwingend auf `argc == 4` anheben und Zeichen gezielt in einer Schleife austauschen. |
| **`ft_strlen`** | Funktion | Gibt die Länge eines übergebenen Strings als Zahl (`int`) zurück. | **Zähler-Schleife:** Eine einfache Funktion schreiben, die beim Null-Terminator (`\0`) anhält und den erreichten Index zurückgibt. |
| **`ft_strcpy`** | Funktion | Kopiert den Inhalt eines Quell-Strings in einen Ziel-String. | **Pointer-Zuweisung:** Zeichen für Zeichen übertragen und am Ende das lebenswichtige `\0`-Zeichen manuell am Ziel-String setzen. |
| **`ft_swap`** | Funktion | Vertauscht die Werte von zwei Integer-Variablen mithilfe ihrer Speicheradressen. | **Pointer-Dereferenzierung:** Der sichere Umgang mit Zeigern (`*a` und `*b`) und das Verwenden einer temporären Zwischenvariable (`int tmp`). |
| **`ft_putstr`** | Funktion | Gibt einen übergebenen String auf dem Bildschirm aus. | **Basis-Schleife:** Die absolute Standard-Übung. Eine `while`-Schleife mit `write(1, &str[i], 1)` bis zum String-Ende steuern. |

---

## Goldene Prüfungsregeln für Level 1
* Wenn die Anzahl der Argumente (`argc`) nicht exakt der Vorgabe entspricht, darf das Programm **nur einen Zeilenumbruch (`\n`)** ausgeben.
* Funktionen (alle Aufgaben mit `ft_` am Anfang) benötigen **keine** eigene `main`-Funktion bei der Abgabe! Du gibst dort nur die reine Logik ab.
* Kompiliere im Terminal immer mit `-Wall -Wextra -Werror`, um versteckte Fehler (wie ungenutzte Variablen oder falsche Typen) sofort zu sehen.
