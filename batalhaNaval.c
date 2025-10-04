/**
 *  Desafio Nível Aventureiro - Jogo de Batalha Naval
 * Este programa posiciona quatro navios de tamanho 3 em um
 * tabuleiro 10x10: um na horizontal, um na vertical e dois nas diagonais.
 * A exibição do tabuleiro mostra '0' para água e '3' para navios.
 * O código inclui validação de limites e de sobreposição para todos os navios.
 */

#include <stdio.h>

// --- Requisitos Não Funcionais: Legibilidade e Manutenção ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // =================================================================
    // 1. INICIALIZAÇÃO DO TABULEIRO E VARIÁVEIS
    // =================================================================
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int sobreposicaoDetectada = 0; 

    // Preenche todo o tabuleiro com 0, que representa "água".
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =================================================================
    // 2. DEFININDO COORDENADAS E POSICIONANDO OS 4 NAVIOS
    // =================================================================
    
    // --- NAVIO 1: HORIZONTAL ---
    int linhaH = 1, colunaH = 1;
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = 3;
        }
    } else {
        printf("ERRO: Navio horizontal fora dos limites!\n");
    }

    // --- NAVIO 2: VERTICAL ---
    int linhaV = 4, colunaV = 8;
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        sobreposicaoDetectada = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicaoDetectada = 1;
                break;
            }
        }
        if (!sobreposicaoDetectada) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("ERRO: Sobreposicao detectada para o navio vertical!\n");
        }
    } else {
        printf("ERRO: Navio vertical fora dos limites!\n");
    }

    // --- NAVIO 3: DIAGONAL (Cima-Esquerda para Baixo-Direita) ---
    int linhaD1 = 3, colunaD1 = 2;
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        sobreposicaoDetectada = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
                sobreposicaoDetectada = 1;
                break;
            }
        }
        if (!sobreposicaoDetectada) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        } else {
            printf("ERRO: Sobreposicao detectada para o navio diagonal 1!\n");
        }
    } else {
        printf("ERRO: Navio diagonal 1 fora dos limites!\n");
    }
    
    // --- NAVIO 4: DIAGONAL (Cima-Direita para Baixo-Esquerda) ---
    int linhaD2 = 0, colunaD2 = 8;
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD2 - (TAMANHO_NAVIO - 1) >= 0) {
        sobreposicaoDetectada = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
                sobreposicaoDetectada = 1;
                break;
            }
        }
        if (!sobreposicaoDetectada) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        } else {
            printf("ERRO: Sobreposicao detectada para o navio diagonal 2!\n");
        }
    } else {
        printf("ERRO: Navio diagonal 2 fora dos limites!\n");
    }

    // =================================================================
    // 3. EXIBIR O TABULEIRO FINAL
    // =================================================================
    printf("=== TABULEIRO BATALHA NAVAL (Aventureiro) ===\n");
    
    // Imprime o cabeçalho das colunas (A, B, C...)
    printf("   "); 
    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c ", c);
    }
    printf("\n");

    // Imprime o tabuleiro com os números das linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // *** AJUSTE REALIZADO AQUI ***
            // Agora imprime o valor numérico da célula (0 para água, 3 para navio)
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("Programa finalizado.\n");
    
    return 0;
}