#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas

int main() {
    int codigo;              // Código da cidade
    char nome[50];               // Nome da cidade
    int populacao;           // População da cidade
    float area;              // Área da cidade (em km²)
    float pib;               // PIB da cidade (em bilhões)
    int pontos_turisticos;   // Número de pontos turísticos
    
    //Cadastro das cartas

    printf("Codigo Da Cidade: \n");
    scanf("%d", &codigo);

    printf("Nome Da Cidade: \n");
    scanf("%s", &nome);

    printf("População Da cidade: \n");
    scanf("%d", &populacao);

    printf("Área Da Cidade (em km²): \n");
    scanf("%f", &area);

    while (getchar() != '\n');

    printf("PIB da cidade (em bilhões): \n");
    scanf(" %f", &pib);

    while (getchar() != '\n');

    printf("Número de pontos turísticos: \n");
    scanf(" %d", &pontos_turisticos);

    

    // Exibição das cartas
    
    
    printf("codigo da cidade: %d \n", codigo);

    printf("Nome da cidade: %s \n", nome);

    printf("População da cidade: %d \n", populacao);

    printf("Área da Cidade: %f \n", area);

    printf("PIB da Cidade: %f \n", pib);

    printf("Numero de pontos turísticos: %d \n", pontos_turisticos);



    return 0;
}
