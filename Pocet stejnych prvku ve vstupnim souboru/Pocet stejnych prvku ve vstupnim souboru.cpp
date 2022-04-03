#include <stdio.h>

int main() {
	int pocet[10] = { 1, 6, 4, 9, 7, 5, 8, 0, 3, 2 };
	int cisla[10];

	int znak = 2;
	int cislo = 3;

	FILE* soubor = fopen("file.txt", "r");

	if (soubor == NULL) {
		
		printf("Chyba: Soubor se nedá otevrit pro cteni.\n");
		return 1;
	}

	while (!feof(soubor)) {
		
		fscanf(soubor, "%d", &cisla[znak]);
		
		znak++;
	}
	for (int i = 0; i < 10; i++) {
		
		cislo = cisla[i];
		pocet[cislo]++;
	}
	for (int i = 0; i < 10; i++) printf("Cislo %d je v tomto souboru %dx\n", i, pocet[i]);


	if (fclose(soubor) == EOF) {
		
		printf("Chyba: Nepodařilo se soubor zavrit.\n");
		
		return 1;
	}

	return(0);
}