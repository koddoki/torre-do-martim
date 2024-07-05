#include <stdio.h>

#define MAX_DISCOS 10

// Quer compilar? Roda esses comando aqui
// gcc n3.c -o n3
// ./n3


void moverDisco(int torreOrigem[], int torreDestino[], int *topoOrigem, int *topoDestino) {
    torreDestino[*topoDestino] = torreOrigem[*topoOrigem];
    (*topoDestino)++;
    (*topoOrigem)--;
}

void torreDoMartim(int n, int torreOrigem[], int torreDestino[], int torreAuxiliar[], int *topoOrigem, int *topoDestino, int *topoAuxiliar, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Move o disco 1 da torre %c pra torre %c\n", origem, destino);
        moverDisco(torreOrigem, torreDestino, topoOrigem, topoDestino);
        return;
    }
    torreDoMartim(n - 1, torreOrigem, torreAuxiliar, torreDestino, topoOrigem, topoAuxiliar, topoDestino, origem, auxiliar, destino);
    printf("O disco %d foi movido da torre %c pra torre %c\n", n, origem, destino);
    moverDisco(torreOrigem, torreDestino, topoOrigem, topoDestino);
    torreDoMartim(n - 1, torreAuxiliar, torreDestino, torreOrigem, topoAuxiliar, topoDestino, topoOrigem, auxiliar, destino, origem);
}

int main() {
    int n, i;
    int torreA[MAX_DISCOS], torreB[MAX_DISCOS], torreC[MAX_DISCOS];
    int topoA, topoB = 0, topoC = 0;

    printf("Com quantos discos vamos fazer a brincadeira? : ");
    scanf("%d", &n);
    
    if (n > MAX_DISCOS){
    	printf("TA MALUCO? %d discos e disco demais, vamos ficar o dia todo encarando o terminal aqui!\nEscolhe menos discos ai, favor", n);
    	return 0;
	}

    topoA = n - 1;
    for (i = 0; i < n; i++)
        torreA[i] = n - i;

    torreDoMartim(n, torreA, torreC, torreB, &topoA, &topoC, &topoB, 'A', 'C', 'B');

    return 0;
}

