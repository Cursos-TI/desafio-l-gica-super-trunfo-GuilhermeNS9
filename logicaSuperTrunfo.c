#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1
    char pais1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;

    // Dados da Carta 2
    char pais2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;

    // Cálculo de densidade demográfica
    float densidade1, densidade2;

    // Leitura da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", pais1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Leitura da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", pais2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo de densidade
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    // Atributos para comparação
    int attr1, attr2;

    // Menu para seleção do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &attr1);

    // Menu para o segundo atributo (dinâmico)
    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == attr1) continue;
        switch(i) {
            case 1: printf("%d - População\n", i); break;
            case 2: printf("%d - Área\n", i); break;
            case 3: printf("%d - PIB\n", i); break;
            case 4: printf("%d - Pontos Turísticos\n", i); break;
            case 5: printf("%d - Densidade Demográfica\n", i); break;
        }
    }
    printf("Opção: ");
    scanf("%d", &attr2);

    // Variáveis para somar os valores numéricos
    float valor1_card1 = 0, valor2_card1 = 0;
    float valor1_card2 = 0, valor2_card2 = 0;

    // Função de comparação por atributo
    printf("\n--- Comparação de Atributos ---\n");

    // Primeiro atributo
    printf("Atributo 1: ");
    switch(attr1) {
        case 1:
            printf("População\n");
            valor1_card1 = (float)populacao1;
            valor1_card2 = (float)populacao2;
            break;
        case 2:
            printf("Área\n");
            valor1_card1 = area1;
            valor1_card2 = area2;
            break;
        case 3:
            printf("PIB\n");
            valor1_card1 = pib1;
            valor1_card2 = pib2;
            break;
        case 4:
            printf("Pontos Turísticos\n");
            valor1_card1 = (float)pontosTuristicos1;
            valor1_card2 = (float)pontosTuristicos2;
            break;
        case 5:
            printf("Densidade Demográfica\n");
            valor1_card1 = densidade1;
            valor1_card2 = densidade2;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Segundo atributo
    printf("Atributo 2: ");
    switch(attr2) {
        case 1:
            printf("População\n");
            valor2_card1 = (float)populacao1;
            valor2_card2 = (float)populacao2;
            break;
        case 2:
            printf("Área\n");
            valor2_card1 = area1;
            valor2_card2 = area2;
            break;
        case 3:
            printf("PIB\n");
            valor2_card1 = pib1;
            valor2_card2 = pib2;
            break;
        case 4:
            printf("Pontos Turísticos\n");
            valor2_card1 = (float)pontosTuristicos1;
            valor2_card2 = (float)pontosTuristicos2;
            break;
        case 5:
            printf("Densidade Demográfica\n");
            valor2_card1 = densidade1;
            valor2_card2 = densidade2;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Exibição dos valores
    printf("\nValores:\n");
    printf("%s - %.2f, %.2f\n", pais1, valor1_card1, valor2_card1);
    printf("%s - %.2f, %.2f\n", pais2, valor1_card2, valor2_card2);

    // Regras de comparação e soma
    float soma1 = 0, soma2 = 0;

    // Regra para o primeiro atributo
    if (attr1 == 5) {  // densidade - menor vence
        printf("Resultado Atributo 1: %s venceu!\n", valor1_card1 < valor1_card2 ? pais1 : (valor1_card2 < valor1_card1 ? pais2 : "Empate!"));
        soma1 += (1 / valor1_card1); // quanto menor, melhor
        soma2 += (1 / valor1_card2);
    } else {
        printf("Resultado Atributo 1: %s venceu!\n", valor1_card1 > valor1_card2 ? pais1 : (valor1_card2 > valor1_card1 ? pais2 : "Empate!"));
        soma1 += valor1_card1;
        soma2 += valor1_card2;
    }

    // Regra para o segundo atributo
    if (attr2 == 5) {
        printf("Resultado Atributo 2: %s venceu!\n", valor2_card1 < valor2_card2 ? pais1 : (valor2_card2 < valor2_card1 ? pais2 : "Empate!"));
        soma1 += (1 / valor2_card1);
        soma2 += (1 / valor2_card2);
    } else {
        printf("Resultado Atributo 2: %s venceu!\n", valor2_card1 > valor2_card2 ? pais1 : (valor2_card2 > valor2_card1 ? pais2 : "Empate!"));
        soma1 += valor2_card1;
        soma2 += valor2_card2;
    }

    // Exibir soma final
    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", pais1, soma1);
    printf("%s: %.2f\n", pais2, soma2);

    // Resultado final
    printf("\nResultado Final: ");
    if (soma1 > soma2)
        printf("%s venceu a rodada!\n", pais1);
    else if (soma2 > soma1)
        printf("%s venceu a rodada!\n", pais2);
    else
        printf("Empate!\n");

    return 0;
}