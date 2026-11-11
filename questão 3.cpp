#include <stdio.h>

int main() {
    int passos, total = 0, horas = 0;

    while (total < 10000) {
        printf("Digite a quantidade de passos da hora: ");
        scanf("%d", &passos);

        total += passos;
        horas++;
    }

    printf("\nMeta atingida!\n");
    printf("Total de passos: %d\n", total);
    printf("Horas necessarias: %d\n", horas);

    return 0;
}

