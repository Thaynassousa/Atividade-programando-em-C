#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ocorrenciaImpar(int c) {
    if (c % 2 != 0) {
        return 1;
    }
    return 0;
}

int ocorrenciaPar(int c) {
    if (c % 2 == 0) {
        return 1;
    }
    return 0;
}

int compararDecrescente(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x < y) - (x > y);
}

int main() {
    int valor[12];
    int distinto[12], cont[12];
    int qtdDistintos = 0, qtdImpar = 0, qtdPar = 0;
    int *vetImpar, *vetPar;
    char nome[12][50];
    float preco[12];
    char nomeAux[50];
    float precoAux;
    int i, j, c, repetido;
    int ii = 0, ip = 0;

    printf("Digite os 12 valores:\n");
    for (i = 0; i < 12; i++) {
        scanf("%d", &valor[i]);
    }

    for (i = 0; i < 12; i++) {
        repetido = 0;
        for (j = 0; j < i; j++) {
            if (valor[j] == valor[i]) {
                repetido = 1;
            }
        }
        if (!repetido) {
            c = 0;
            for (j = 0; j < 12; j++) {
                if (valor[j] == valor[i]) {
                    c++;
                }
            }
            distinto[qtdDistintos] = valor[i];
            cont[qtdDistintos] = c;
            qtdDistintos++;

            if (ocorrenciaImpar(c)) {
                qtdImpar++;
            }
            if (ocorrenciaPar(c)) {
                qtdPar++;
            }
        }
    }

    vetImpar = (int *)malloc(sizeof(int) * qtdImpar);
    vetPar = (int *)malloc(sizeof(int) * qtdPar);

    for (i = 0; i < qtdDistintos; i++) {
        if (ocorrenciaImpar(cont[i])) {
            vetImpar[ii++] = distinto[i];
        }
        if (ocorrenciaPar(cont[i])) {
            vetPar[ip++] = distinto[i];
        }
    }

    qsort(vetPar, qtdPar, sizeof(int), compararDecrescente);

    for (i = 0; i < qtdImpar; i++) {
        printf("\nProduto %d (comprar %d unidades)\n", i + 1, vetImpar[i]);
        printf("Nome: ");
        scanf(" %49[^\n]", nome[i]);
        printf("Preco unitario: ");
        scanf("%f", &preco[i]);
    }

    /* ordena por nome, trocando nome e preco juntos */
    for (i = 0; i < qtdImpar - 1; i++) {
        for (j = 0; j < qtdImpar - 1 - i; j++) {
            if (strcmp(nome[j], nome[j + 1]) > 0) {
                strcpy(nomeAux, nome[j]);
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], nomeAux);

                precoAux = preco[j];
                preco[j] = preco[j + 1];
                preco[j + 1] = precoAux;
            }
        }
    }

    printf("\nNumeros informados: ");
    for (i = 0; i < 12; i++) {
        printf("%d ", valor[i]);
    }

    printf("\n\nQuantidade de cada numero:\n");
    for (i = 0; i < qtdDistintos; i++) {
        printf("%d aparece %d vez(es)\n", distinto[i], cont[i]);
    }

    printf("\nProdutos (ordem alfabetica):\n");
    for (i = 0; i < qtdImpar; i++) {
        printf("%s - R$ %.2f\n", nome[i], preco[i]);
    }

    printf("\nNumeros com ocorrencia par (decrescente): ");
    for (i = 0; i < qtdPar; i++) {
        printf("%d ", vetPar[i]);
    }
    printf("\n");

    free(vetImpar);
    free(vetPar);
    return 0;
}
