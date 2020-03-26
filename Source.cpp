#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Colet {
	int id;
	char* expeditor;
	char* destinatar;
	float greutate;
};

struct Nod {
	Colet info;
	Nod* next;
};

Colet initColet(int id, const char* expeditor, const char* destinatar, float greutate) {
	Colet c;
	c.destinatar = (char*)malloc(sizeof(char) * (strlen(destinatar) + 1));
	strcpy(c.destinatar, destinatar);
	c.expeditor = (char*)malloc(sizeof(char) * (strlen(expeditor) + 1));
	strcpy(c.expeditor, expeditor);
	c.id = id;
	c.greutate = greutate;
	return c;
}

void inserareNodInListaCirculara(Nod*& cap, Colet c) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = c;
	if (cap) {
		Nod* aux = cap;
		while (cap->next && cap->next != aux) {
			cap = cap->next;
		}
		cap->next = nou;
		nou->next = aux;
		cap = aux;
	}
	else {
		cap = nou;
		cap->next = NULL;
	}
}

void afisareColet(Colet c) {
	printf("{%d, '%s', '%s', %5.2f}\n", c.id, c.expeditor, c.destinatar, c.greutate);
}

Nod* extragereSiStergereNodDinLista(Nod*& capLista, int idNod) {
	Nod* nodExtras = (Nod*)malloc(sizeof(Nod));
	Nod* copieCap = capLista;
	while (capLista->next != copieCap) {
		if (capLista->info.id != idNod) capLista = capLista->next;
		else {
			nodExtras->next = nodExtras;
			nodExtras->info = initColet(capLista->info.id, capLista->info.expeditor, capLista->info.destinatar, capLista->info.greutate);
			free(capLista->info.destinatar);
			free(capLista->info.expeditor);
			Nod* temp = capLista;
			capLista = capLista->next;
			free(temp);
			return nodExtras;
		}
	}
	if (capLista->info.id != idNod) {
		capLista = capLista->next;
	}
	if (capLista->info.id == idNod) {
		nodExtras->next = nodExtras;
		nodExtras->info = initColet(capLista->info.id, capLista->info.expeditor, capLista->info.destinatar, capLista->info.greutate);
		free(capLista->info.destinatar);
		free(capLista->info.expeditor);
		Nod* temp = capLista;
		capLista = capLista->next;
		free(temp);
		return nodExtras;
	}
	else {
		throw "Nod inexistent!";
	}
}

void afisareListaCirculara(Nod* capLista) {
	Nod* copieCap = capLista;
	while (capLista->next != copieCap && capLista != NULL) {
		afisareColet(capLista->info);
		capLista = capLista->next;
	}
	afisareColet(capLista->info);
}

void main() {
	Nod* capListaCirculara = NULL;
	inserareNodInListaCirculara(capListaCirculara, initColet(1, "Stroescu Marius", "Stroescu Diana", 20.5));
	inserareNodInListaCirculara(capListaCirculara, initColet(2, "Stroescu Marius", "Stroescu Ioana", 15.2));
	inserareNodInListaCirculara(capListaCirculara, initColet(3, "Stroescu Traenel", "Stroescu Marius", 54.21));
	inserareNodInListaCirculara(capListaCirculara, initColet(4, "Alt colet 4", "Stroescu Marius", 541.0));
	inserareNodInListaCirculara(capListaCirculara, initColet(5, "Alt colet 5", "Stroescu Marius", 22.2));
	//afisareListaCirculara(capListaCirculara);
	Nod* nodExtras = extragereSiStergereNodDinLista(capListaCirculara, 5);
	afisareListaCirculara(nodExtras);
}
