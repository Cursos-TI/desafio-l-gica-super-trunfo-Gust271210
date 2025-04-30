#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTD_CARTAS 2

struct Carta {
    char estado[50];
    char codcarta[50];
    char nomecidade[50];
    int populacao;
    int area;
    float densidadepop;
    int pib;
    int pibpercap;
    int numeroponto;
};

// Função para formatar número com ponto como separador de milhar
void formatar_milhar(int valor, char *saida) {
    char buffer[50];
    sprintf(buffer, "%d", valor);  // Converte o número para string

    int len = strlen(buffer);
    int pontoCount = (len - 1) / 3;
    int novaLen = len + pontoCount;

    saida[novaLen] = '\0';

    int i = len - 1;
    int j = novaLen - 1;
    int contador = 0;

    while (i >= 0) {
        if (contador == 3) {
            saida[j--] = '.';
            contador = 0;
        }
        saida[j--] = buffer[i--];
        contador++;
    }
}

int main() {
    struct Carta cartas[QTD_CARTAS];
    char entrada[100]; // buffer para leitura com fgets

    for (int i = 0; i < QTD_CARTAS; i++) {
        printf("\n--- Preenchendo dados da carta %d ---\n", i + 1);

        // Lendo estado
        printf("Digite o estado:\n");
        fgets(cartas[i].estado, sizeof(cartas[i].estado), stdin);
        cartas[i].estado[strcspn(cartas[i].estado, "\n")] = '\0';

        // Lendo código
        printf("Digite o código:\n");
        fgets(cartas[i].codcarta, sizeof(cartas[i].codcarta), stdin);
        cartas[i].codcarta[strcspn(cartas[i].codcarta, "\n")] = '\0';

        // Lendo nome da cidade
        printf("Digite o nome da cidade:\n");
        fgets(cartas[i].nomecidade, sizeof(cartas[i].nomecidade), stdin);
        cartas[i].nomecidade[strcspn(cartas[i].nomecidade, "\n")] = '\0';

        // Lendo população
        printf("Digite a população:\n");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%d", &cartas[i].populacao);

        // Lendo área
        printf("Digite a área em km²:\n");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%d", &cartas[i].area);

        // Lendo PIB
        printf("Digite o PIB:\n");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%d", &cartas[i].pib);

        // Lendo número de pontos turísticos
        printf("Digite o número de pontos turísticos:\n");
        fgets(entrada, sizeof(entrada), stdin);
        sscanf(entrada, "%d", &cartas[i].numeroponto);

        // Cálculos de densidade populacional e PIB per capita
        if (cartas[i].populacao != 0 && cartas[i].area != 0) {
            cartas[i].densidadepop = cartas[i].populacao / cartas[i].area;
            cartas[i].pibpercap = cartas[i].pib / cartas[i].populacao;
        } else {
            cartas[i].densidadepop = 0;
            cartas[i].pibpercap = 0;
        }
    }

    // Comparação por PIB (pode trocar para outro atributo se desejar)
    printf("\n===== COMPARAÇÃO DE PIB =====\n");
    if (cartas[0].pib > cartas[1].pib) {
        printf("Carta vencedora: %s (PIB: %d)\n", cartas[0].nomecidade, cartas[0].pib);
    } else if (cartas[1].pib > cartas[0].pib) {
        printf("Carta vencedora: %s (PIB: %d)\n", cartas[1].nomecidade, cartas[1].pib);
    } else {
        printf("Empate entre as cidades. PIB: %d\n", cartas[0].pib);
    }

    // Exibindo os dados das cartas
    printf("\n===== CARTAS DIGITADAS =====\n");
    for (int i = 0; i < QTD_CARTAS; i++) {
        char populacaoFormatada[50];
        formatar_milhar(cartas[i].populacao, populacaoFormatada);

        printf("\n--- Carta %d ---\n", i + 1);
        printf("Estado: %s\n", cartas[i].estado);
        printf("Código da carta: %s\n", cartas[i].codcarta);
        printf("Nome da cidade: %s\n", cartas[i].nomecidade);
        printf("População: %s\n", populacaoFormatada);
        printf("Área: %d km²\n", cartas[i].area);
        printf("PIB: %d\n", cartas[i].pib);
        printf("Número de pontos turísticos: %d\n", cartas[i].numeroponto);
        printf("Densidade Populacional: %d hab/km²\n", cartas[i].densidadepop);
        printf("PIB per capita: %d\n", cartas[i].pibpercap);
    }

    return 0;
}
