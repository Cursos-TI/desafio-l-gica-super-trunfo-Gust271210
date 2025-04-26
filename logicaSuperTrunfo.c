#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTD_CARTAS 2

struct Carta {
    char estado[50];
    char codcarta[50];
    char nomecidade[50];
    int populacao;
    float area;
    float densidadepop;
    float pib;
    float pibpercap;
    int numeroponto;
};

int main() {
    struct Carta cartas[QTD_CARTAS];
    char entrada[100]; // buffer para leitura com fgets

    for (int i = 0; i < QTD_CARTAS; i++) {
        printf("\n--- Preenchendo dados da carta %d ---\n", i + 1);

        printf("Digite o estado:\n");
        fgets(cartas[i].estado, sizeof(cartas[i].estado), stdin);
        cartas[i].estado[strcspn(cartas[i].estado, "\n")] = '\0';

        printf("Digite o código:\n");
        fgets(cartas[i].codcarta, sizeof(cartas[i].codcarta), stdin);
        cartas[i].codcarta[strcspn(cartas[i].codcarta, "\n")] = '\0';

        printf("Digite o nome da cidade:\n");
        fgets(cartas[i].nomecidade, sizeof(cartas[i].nomecidade), stdin);
        cartas[i].nomecidade[strcspn(cartas[i].nomecidade, "\n")] = '\0';

        printf("Digite a população:\n");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%d", &cartas[i].populacao);

        printf("Digite a área em km²:\n");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%f", &cartas[i].area);

        printf("Digite o PIB:\n");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%f", &cartas[i].pib);

        printf("Digite o número de pontos turísticos:\n");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%d", &cartas[i].numeroponto);

        if (cartas[i].populacao != 0 && cartas[i].area != 0) {
            cartas[i].densidadepop = cartas[i].populacao / cartas[i].area;
            cartas[i].pibpercap = cartas[i].pib / cartas[i].populacao;
        }
    }

    // Comparação
    printf("\n===== COMPARAÇÃO DE PIB =====\n");
    if (cartas[0].pib > cartas[1].pib) {
        printf("Carta vencedora: %s (PIB: %.2f)\n", cartas[0].nomecidade, cartas[0].pib);
    } else if (cartas[1].pib > cartas[0].pib) {
        printf("Carta vencedora: %s (PIB: %.2f)\n", cartas[1].nomecidade, cartas[1].pib);
    } else {
        printf("Empate entre as cidades. PIB: %.2f\n", cartas[0].pib);
    }

    return 0;
}
