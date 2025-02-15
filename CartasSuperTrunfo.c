#include <stdio.h>

// Função para calcular a densidade populacional
float calcular_densidade_populacional(int populacao, float area) {
    return (float)populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return (pib * 1e9) / populacao; // Converte o PIB para dólares e divide pela população
}

int main() {
    int codigo;              // Código da cidade
    char nome[50];           // Nome da cidade
    int populacao;           // População da cidade
    float area;              // Área da cidade (em km²)
    float pib;               // PIB da cidade (em bilhões)
    int pontos_turisticos;   // Número de pontos turísticos

    // Cadastro das cartas
    printf("Codigo Da Cidade: \n");
    scanf("%d", &codigo);

    printf("Nome Da Cidade: \n");
    getchar(); // Limpa o buffer do teclado
    fgets(nome, 50, stdin); // Lê o nome da cidade com espaços
    nome[strcspn(nome, "\n")] = '\0'; // Remove a quebra de linha do final

    printf("População Da cidade: \n");
    scanf("%d", &populacao);
    while (getchar() != '\n'); // Limpa o buffer de entrada

    printf("Área Da Cidade (em km²): \n");
    scanf("%f", &area);

    printf("PIB da cidade (em bilhões): \n");
    scanf("%f", &pib);

    printf("Número de pontos turísticos: \n");
    scanf("%d", &pontos_turisticos);

    // Cálculos adicionais

    float densidade = calcular_densidade_populacional(populacao, area);

    float pib_per_capita = calcular_pib_per_capita(pib, populacao);

    // Exibição das cartas

    printf("\n--- Informações da Cidade ---\n");

    printf("Código da cidade: %d \n", codigo);

    printf("Nome da cidade: %s \n", nome);

    printf("População da cidade: %d habitantes\n", populacao);

    printf("Área da Cidade: %.2f km²\n", area);

    printf("PIB da Cidade: US$ %.2f bilhões\n", pib);

    printf("Número de pontos turísticos: %d \n", pontos_turisticos);

    printf("Densidade Populacional: %.2f habitantes/km²\n", densidade);

    printf("PIB per Capita: US$ %.2f\n", pib_per_capita);

    return 0;
}