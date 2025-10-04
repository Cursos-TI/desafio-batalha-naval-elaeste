/**
 * Desafio Nível Mestre - Jogo de Batalha Naval
 *
 * Este programa expande o jogo de Batalha Naval, adicionando três habilidades
 * especiais com áreas de efeito (AoE) distintas: Cone, Cruz e Octaedro.
 *
 * - O tabuleiro é 10x10 e os 4 navios são posicionados primeiro.
 * - As áreas de efeito das habilidades são geradas dinamicamente usando loops e condicionais.
 * - As habilidades são sobrepostas no tabuleiro, marcando a água afetada com o valor '5'.
 * - Uma regra chave foi implementada: as habilidades afetam apenas a água ('0') e NUNCA
 * se sobrepõem a uma posição de navio ('3').
 *
 * A exibição final do tabuleiro mostra:
 * - 0: Água
 * - 3: Navio
 * - 5: Área de Efeito da Habilidade
 */

#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()

// --- Requisitos Não Funcionais: Legibilidade e Manutenção ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Usando 5x5 para as matrizes de habilidade
#define MARCA_AGUA 0
#define MARCA_NAVIO 3
#define MARCA_HABILIDADE 5

int main() {
    // =================================================================
    // 1. INICIALIZAÇÃO DO TABULEIRO E VARIÁVEIS
    // =================================================================
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenche todo o tabuleiro com 0, que representa "água".
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = MARCA_AGUA;
        }
    }

    // =================================================================
    // 2. POSICIONANDO OS 4 NAVIOS (MESMAS POSIÇÕES DA VERSÃO ANTERIOR)
    // =================================================================
    
    // --- NAVIO 1: HORIZONTAL ---
    int linhaH = 1, colunaH = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = MARCA_NAVIO;
    }

    // --- NAVIO 2: VERTICAL ---
    int linhaV = 5, colunaV = 8;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = MARCA_NAVIO;
    }

    // --- NAVIO 3: DIAGONAL (Cima-Esquerda para Baixo-Direita) ---
    int linhaD1 = 3, colunaD1 = 2;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = MARCA_NAVIO;
    }
    
    // --- NAVIO 4: DIAGONAL (Cima-Direita para Baixo-Esquerda) ---
    int linhaD2 = 0, colunaD2 = 8;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = MARCA_NAVIO;
    }

    // =================================================================
    // 3. CRIAR E APLICAR HABILIDADES ESPECIAIS
    // =================================================================

    int centroHabilidade = TAMANHO_HABILIDADE / 2;

    // --- HABILIDADE 1: OCTAEDRO (LOSANGO) ---
    int origemOctaedroLinha = 3, origemOctaedroColuna = 6;
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centroHabilidade) + abs(j - centroHabilidade) <= centroHabilidade) {
                habilidadeOctaedro[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidadeOctaedro[i][j] == 1) {
                int targetLinha = origemOctaedroLinha + (i - centroHabilidade);
                int targetColuna = origemOctaedroColuna + (j - centroHabilidade);
                if (targetLinha >= 0 && targetLinha < TAMANHO_TABULEIRO && targetColuna >= 0 && targetColuna < TAMANHO_TABULEIRO) {
                    if(tabuleiro[targetLinha][targetColuna] == MARCA_AGUA) {
                         tabuleiro[targetLinha][targetColuna] = MARCA_HABILIDADE;
                    }
                }
            }
        }
    }

    // --- HABILIDADE 2: CRUZ ---
    int origemCruzLinha = 7, origemCruzColuna = 2;
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centroHabilidade || j == centroHabilidade) {
                habilidadeCruz[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidadeCruz[i][j] == 1) {
                int targetLinha = origemCruzLinha + (i - centroHabilidade);
                int targetColuna = origemCruzColuna + (j - centroHabilidade);
                if (targetLinha >= 0 && targetLinha < TAMANHO_TABULEIRO && targetColuna >= 0 && targetColuna < TAMANHO_TABULEIRO) {
                    if(tabuleiro[targetLinha][targetColuna] == MARCA_AGUA){
                         tabuleiro[targetLinha][targetColuna] = MARCA_HABILIDADE;
                    }
                }
            }
        }
    }
    
    // --- HABILIDADE 3: CONE (LÓGICA CORRIGIDA) ---
    int origemConeLinha = 7, origemConeColuna = 6; // Posição do topo (vértice) do cone
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    // *** CORREÇÃO APLICADA AQUI ***
    // Lógica para criar uma matriz de cone/triângulo real.
    // A condição 'abs(j - centro) <= i' forma o padrão de cone apontando para baixo.
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(j - centroHabilidade) <= i) {
                 habilidadeCone[i][j] = 1;
            }
        }
    }
    // Aplicar a habilidade Cone ao tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidadeCone[i][j] == 1) {
                // O cálculo do alvo é relativo ao topo do cone
                int targetLinha = origemConeLinha + i;
                int targetColuna = origemConeColuna + (j - centroHabilidade);
                if (targetLinha >= 0 && targetLinha < TAMANHO_TABULEIRO && targetColuna >= 0 && targetColuna < TAMANHO_TABULEIRO) {
                    if(tabuleiro[targetLinha][targetColuna] == MARCA_AGUA) {
                         tabuleiro[targetLinha][targetColuna] = MARCA_HABILIDADE;
                    }
                }
            }
        }
    }

    // =================================================================
    // 4. EXIBIR O TABULEIRO FINAL
    // =================================================================
    printf("=== TABULEIRO BATALHA NAVAL (MESTRE) ===\n");
    
    printf("    A B C D E F G H I J \n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }

    printf("\nPrograma finalizado.\n");
    
    return 0;
}