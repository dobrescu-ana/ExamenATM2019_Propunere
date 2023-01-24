#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Ruta
{
	char* oras_sursa;
	char* oras_destinatie;
	float distanta;
};


typedef struct Harta
{
	int numarator;
	int numitor;
	int nr_masuratori;
	Ruta* rute;
};

Harta ParsareFisierHarta(const char* nume_fisier)
{
	Harta rezultat;
	FILE* f = fopen(nume_fisier, "r");
	if (f == NULL)
		printf("Nu exista fisier de intrare\n");

	// Se citeste prima linie din fisier.
	char* line = (char*)malloc(150);
	fgets(line, 150, f);

	// Se prelucreaza numaratrul hartii.
	char* p = strtok(line, ":");
	rezultat.numarator = atoi(p);

	// Se prelucreaza numitorul hartii.
	p = strtok(NULL, "\n");
	rezultat.numitor = atoi(p);

	// Se citeste a doua linie
	// good practice: golim memoria si o alocam din nou
	fgets(line, 150, f);

	// Se preia numarul de masuratori.
	rezultat.nr_masuratori = atoi(line);

	// Se aloca rutele in functie de numarul de masuratori.
	rezultat.rute = (Ruta*)malloc(sizeof(Ruta) * rezultat.nr_masuratori);

	// Index pentru rute. (cate rute am adaugat)
	int i = 0;

	while (!feof(f))
	{
		fgets(line, 150, f);

		// Se preia orasul sursa.
		char* p = strtok(line, "-");

		// Se adauga orasul sursa in ruta.
		rezultat.rute[i].oras_sursa = (char*)malloc((strlen(p) + 1) * sizeof(char));
		strcpy(rezultat.rute[i].oras_sursa, p);

		// Se preia orasul destinatie.
		p = strtok(NULL, ":");

		// Se adauga orasul in rute.
		rezultat.rute[i].oras_destinatie = (char*)malloc((strlen(p) + 1) * sizeof(char));
		strcpy(rezultat.rute[i].oras_destinatie, p);

		// Se preia distanta.
		p = strtok(NULL, "\n");

		// Se adauga distanta in ruta.
		rezultat.rute[i].distanta = atof(p);

		// de cautat cum pastrezi doar 2 zecimale dupa virgula

		// Se trece la urmatoarea ruta.
		i++;
	}

	return rezultat;
}

void AfisareHarta(Harta h)
{
	printf("%d:%d\n", h.numarator, h.numitor);
	printf("%d\n", h.nr_masuratori);
	for (int i = 0; i < h.nr_masuratori; i++)
	{
		printf("%s - %s : %f", h.rute[i].oras_sursa, h.rute[i].oras_destinatie, h.rute[i].distanta);
		printf("\n");
	}
}

int main()
{
	Harta h1 = ParsareFisierHarta("masuratori1.txt");
	AfisareHarta(h1);
	return 0;
}