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

int main() {
    int codigo_estado;       // Código do estado (1 a 8, correspondente a A a H)
    int codigo_cidade;       // Código da cidade (1 a 4)
    char nome[50];           // Nome da cidade
    int populacao;           // População da cidade
    float area;              // Área da cidade (em km²)
    float pib;               // PIB da cidade (em bilhões)
    int pontos_turisticos;   // Número de pontos turísticos

    // Cadastro das cartas
    printf("Codigo do Estado (1 a 8, onde 1 = A, 2 = B, ..., 8 = H): \n");
    scanf("%d", &codigo_estado);
    while (getchar() != '\n'); // Limpa o buffer de entrada

    printf("Codigo da Cidade (1 a 4): \n");
    scanf("%d", &codigo_cidade);
    while (getchar() != '\n'); 

    printf("Nome Da Cidade: \n");
    fgets(nome, 50, stdin); // Lê o nome da cidade com espaços
    nome[strcspn(nome, "\n")] = '\0'; // Remove a quebra de linha do final

    printf("População Da cidade: \n");
    scanf("%d", &populacao);
    while (getchar() != '\n'); 

    printf("Área Da Cidade (em km²): \n");
    scanf("%f", &area);
    while (getchar() != '\n'); 

    printf("PIB da cidade (em bilhões): \n");
    scanf("%f", &pib);
    while (getchar() != '\n'); 

    printf("Número de pontos turísticos: \n");
    scanf("%d", &pontos_turisticos);
    while (getchar() != '\n'); 

    // Gera o código da carta (ex: A01, B02, etc.)
    char estado = 'A' + (codigo_estado - 1); // Converte o número do estado para letra (A-H)

    char codigo_carta[5]; // Armazena o código da carta (ex: A01)

    sprintf(codigo_carta, "%c%02d", estado, codigo_cidade); // Formata o código

    // Cálculos adicionais
    float densidade = calcular_densidade_populacional(populacao, area);

    float pib_per_capita = calcular_pib_per_capita(pib, populacao);

    // Exibição das cartas
    printf("\n--- Informações da Cidade ---\n");

    printf("Código da Carta: %s \n", codigo_carta);

    printf("Nome da cidade: %s \n", nome);

    printf("População da cidade: %d habitantes\n", populacao);

    printf("Área da Cidade: %.2f km²\n", area);

    printf("PIB da Cidade: US$ %.2f bilhões\n", pib);

    printf("Número de pontos turísticos: %d \n", pontos_turisticos);

    printf("Densidade Populacional: %.2f habitantes/km²\n", densidade);
    
    printf("PIB per Capita: US$ %.2f\n", pib_per_capita);

    return 0;
}