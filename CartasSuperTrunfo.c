#include <stdio.h>
#include <string.h> // Para usar strcspn

// Função para calcular a densidade populacional
float calcular_densidade_populacional(int populacao, float area) {
    return (float)populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return (pib * 1e9) / populacao; // Converte o PIB para dólares e divide pela população
}

// Função para comparar duas cidades
void comparar_cidades(
    char codigo_carta1[5], char nome1[50], int populacao1, float area1, float pib1, int pontos_turisticos1,
    char codigo_carta2[5], char nome2[50], int populacao2, float area2, float pib2, int pontos_turisticos2
) {
    // Cálculos para a primeira cidade
    float densidade1 = calcular_densidade_populacional(populacao1, area1);
    float pib_per_capita1 = calcular_pib_per_capita(pib1, populacao1);
    float super_poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + densidade1 + pib_per_capita1;

    // Cálculos para a segunda cidade
    float densidade2 = calcular_densidade_populacional(populacao2, area2);
    float pib_per_capita2 = calcular_pib_per_capita(pib2, populacao2);
    float super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + densidade2 + pib_per_capita2;

    // Exibe os resultados
    printf("\n--- Comparação das Cidades ---\n");

    // Compara Densidade Populacional
    if (densidade1 < densidade2) {
        printf("%s vence em Densidade Populacional (menor valor)\n", nome1);
    } else if (densidade1 > densidade2) {
        printf("%s vence em Densidade Populacional (menor valor)\n", nome2);
    } else {
        printf("Empate em Densidade Populacional\n");
    }

    // Compara População
    if (populacao1 > populacao2) {
        printf("%s vence em População (maior valor)\n", nome1);
    } else if (populacao1 < populacao2) {
        printf("%s vence em População (maior valor)\n", nome2);
    } else {
        printf("Empate em População\n");
    }

    // Compara Área
    if (area1 > area2) {
        printf("%s vence em Área (maior valor)\n", nome1);
    } else if (area1 < area2) {
        printf("%s vence em Área (maior valor)\n", nome2);
    } else {
        printf("Empate em Área\n");
    }

    // Compara PIB
    if (pib1 > pib2) {
        printf("%s vence em PIB (maior valor)\n", nome1);
    } else if (pib1 < pib2) {
        printf("%s vence em PIB (maior valor)\n", nome2);
    } else {
        printf("Empate em PIB\n");
    }

    // Compara Pontos Turísticos
    if (pontos_turisticos1 > pontos_turisticos2) {
        printf("%s vence em Pontos Turísticos (maior valor)\n", nome1);
    } else if (pontos_turisticos1 < pontos_turisticos2) {
        printf("%s vence em Pontos Turísticos (maior valor)\n", nome2);
    } else {
        printf("Empate em Pontos Turísticos\n");
    }

    // Compara PIB per Capita
    if (pib_per_capita1 > pib_per_capita2) {
        printf("%s vence em PIB per Capita (maior valor)\n", nome1);
    } else if (pib_per_capita1 < pib_per_capita2) {
        printf("%s vence em PIB per Capita (maior valor)\n", nome2);
    } else {
        printf("Empate em PIB per Capita\n");
    }

    // Compara Super Poder
    if (super_poder1 > super_poder2) {
        printf("\n%s tem o maior Super Poder! (%.2f)\n", nome1, super_poder1);
    } else if (super_poder1 < super_poder2) {
        printf("\n%s tem o maior Super Poder! (%.2f)\n", nome2, super_poder2);
    } else {
        printf("\nAs cidades têm o mesmo Super Poder! (%.2f)\n", super_poder1);
    }
}

// Função para coletar os dados de uma cidade
void cadastrar_cidade(char codigo_carta[5], char nome[50], int *populacao, float *area, float *pib, int *pontos_turisticos) {
    int codigo_estado, codigo_cidade;

    printf("\nCadastro da Cidade:\n");

    printf("Código do Estado (1 a 8, onde 1 = A, 2 = B, ..., 8 = H): \n");
    scanf("%d", &codigo_estado);
    while (getchar() != '\n'); // Limpa o buffer de entrada

    printf("Código da Cidade (1 a 4): \n");
    scanf("%d", &codigo_cidade);
    while (getchar() != '\n');

    printf("Nome da Cidade: \n");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove a quebra de linha

    printf("População da Cidade: \n");
    scanf("%d", populacao);
    while (getchar() != '\n');

    printf("Área da Cidade (em km²): \n");
    scanf("%f", area);
    while (getchar() != '\n');

    printf("PIB da Cidade (em bilhões): \n");
    scanf("%f", pib);
    while (getchar() != '\n');

    printf("Número de Pontos Turísticos: \n");
    scanf("%d", pontos_turisticos);
    while (getchar() != '\n');

    // Gera o código da carta (ex: A01, B02, etc.)
    char estado = 'A' + (codigo_estado - 1);
    sprintf(codigo_carta, "%c%02d", estado, codigo_cidade);
}

int main() {
    // Variáveis para a primeira cidade
    char codigo_carta1[5], nome1[50];
    int populacao1, pontos_turisticos1;
    float area1, pib1;

    // Variáveis para a segunda cidade
    char codigo_carta2[5], nome2[50];
    int populacao2, pontos_turisticos2;
    float area2, pib2;

    // Cadastro das cidades
    printf("=== Cadastro da Primeira Cidade ===\n");
    cadastrar_cidade(codigo_carta1, nome1, &populacao1, &area1, &pib1, &pontos_turisticos1);

    printf("\n=== Cadastro da Segunda Cidade ===\n");
    cadastrar_cidade(codigo_carta2, nome2, &populacao2, &area2, &pib2, &pontos_turisticos2);

    // Compara as cidades
    comparar_cidades(
        codigo_carta1, nome1, populacao1, area1, pib1, pontos_turisticos1,
        codigo_carta2, nome2, populacao2, area2, pib2, pontos_turisticos2
    );

    return 0;
}