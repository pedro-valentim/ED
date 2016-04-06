#include<stdio.h>
#include<stdlib.h>

struct cel {
	int valor;   // conteúdo
	struct cel *seg;  // seguinte
};
typedef struct cel celula;

struct cel_f {
	struct cel *s; // seguinte
	struct cel *t; // seguinte
};
typedef struct cel_f fila;


void Insere (int y, fila *f) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->valor = y;
    nova->seg = NULL;
    if (f->t == NULL) f->t = f->s = nova;
    else {
        f->t->seg = nova;
        f->s = nova;
    }
}

int Remove (fila *f) {
    celula *p;
    int x;
    p = f->s;
    /* p aponta o primeiro elemento da fila */
    x = p->valor;
    f->s = p->seg;
    free (p);
    if (f->s == NULL) f->t = NULL;
    return x;
}


void Imprima (fila *f) {
	/*celula *p;
	printf ("\n[ ");
	for (p = f->s; p != NULL; p = p->seg)
		printf ("%d ", p->valor);
    printf ("]");*/
}

void main (){

	fila *Alta, *Media, *Baixa;

    Alta->s = Alta->t = Media->s = Media->t = Baixa->s = Baixa->t = NULL;

	int entrada;

	while (scanf("%d", &entrada) && (entrada != -1))
    {
        if (entrada >= 10 && entrada < 20) Insere(entrada, Alta);
        if (entrada >= 20 && entrada < 30) Insere(entrada, Media);
        if (entrada >= 30 && entrada < 40) Insere(entrada, Baixa);

        if (entrada == 1)
        {
            Imprima(Alta);
            Imprima(Media);
            Imprima(Baixa);
        }

        if (entrada == 0)
        {
            if (Alta != NULL)
                printf("%d \n", Remove(Alta));
            else if (Media != NULL)
                printf("%d \n", Remove(Media));
            else if (Baixa != NULL)
                printf("%d \n", Remove(Baixa));
        }
	}

}


