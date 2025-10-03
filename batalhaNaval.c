#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[10][10];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10]; // matriz do tabuleiro 10x10
    int navioHorizontal[3] = {3, 3, 3}; // vetor que representa navio horizontal
    int navioVertical[3]   = {3, 3, 3}; // vetor que representa navio vertical

    // 1. Inicializar o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definindo coordenadas iniciais dos navios (fixas no código)
    int linhaH = 2, colunaH = 4; // navio horizontal começa na linha 2, coluna 4
    int linhaV = 5, colunaV = 7; // navio vertical começa na linha 5, coluna 7

    // 3. Validar e posicionar navio horizontal
    if (colunaH + 3 <= 10) { // verifica se cabe no tabuleiro
        for (int j = 0; j < 3; j++) {
            tabuleiro[linhaH][colunaH + j] = navioHorizontal[j];
        }
    }

    // 4. Validar e posicionar navio vertical
    if (linhaV + 3 <= 10) { // verifica se cabe no tabuleiro
        for (int i = 0; i < 3; i++) {
            // verificar sobreposição
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    // 5. Exibir o tabuleiro
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n");

    // imprimir cabeçalho (A, B, C...)
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", linha[j]);//indice de Coluna Letras EX: A B C ...
    }
    printf("\n");

    // imprimir matriz com índices das linhas
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // índice da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);//Preenche o Tabuleiro
        }
        printf("\n");
    }

    return 0;
}
