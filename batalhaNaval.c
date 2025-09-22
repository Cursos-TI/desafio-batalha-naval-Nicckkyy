#include <stdio.h>

#define N 10  // Tamanho do tabuleiro

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 ");  // Água
            else if (tabuleiro[i][j] == 3)
                printf("3 ");  // Navio
            else if (tabuleiro[i][j] == 5)
                printf("5 ");  // Área afetada
        }
        printf("\n");
    }
}

// Função para adicionar o efeito da habilidade Cone ao tabuleiro
void aplicarCone(int tabuleiro[N][N], int origemLinha, int origemColuna, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = origemColuna - i; j <= origemColuna + i; j++) {
            if (origemLinha + i < N && j >= 0 && j < N) {
                tabuleiro[origemLinha + i][j] = 5;  // Marca a área afetada
            }
        }
    }
}

// Função para adicionar o efeito da habilidade Cruz ao tabuleiro
void aplicarCruz(int tabuleiro[N][N], int origemLinha, int origemColuna, int tamanho) {
    for (int i = -tamanho + 1; i < tamanho; i++) {
        if (origemLinha + i >= 0 && origemLinha + i < N) {
            tabuleiro[origemLinha + i][origemColuna] = 5;  // Linha central da cruz
        }
        if (origemColuna + i >= 0 && origemColuna + i < N) {
            tabuleiro[origemLinha][origemColuna + i] = 5;  // Coluna central da cruz
        }
    }
}

// Função para adicionar o efeito da habilidade Octaedro ao tabuleiro
void aplicarOctaedro(int tabuleiro[N][N], int origemLinha, int origemColuna, int tamanho) {
    for (int i = -tamanho + 1; i < tamanho; i++) {
        for (int j = -tamanho + 1; j < tamanho; j++) {
            if (origemLinha + i >= 0 && origemLinha + i < N &&
                origemColuna + j >= 0 && origemColuna + j < N &&
                abs(i) + abs(j) < tamanho) {
                tabuleiro[origemLinha + i][origemColuna + j] = 5;  // Marca a área afetada
            }
        }
    }
}

int main() {
    int tabuleiro[N][N] = {0};  // Inicializa o tabuleiro com água (0)

    // Colocando alguns navios no tabuleiro (valor 3)
    tabuleiro[2][3] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[7][7] = 3;
    tabuleiro[4][6] = 3;

    // Definindo as coordenadas de origem para as habilidades
    int origemConeLinha = 0, origemConeColuna = 4; // Cone na linha 0, coluna 4
    int origemCruzLinha = 5, origemCruzColuna = 5; // Cruz na linha 5, coluna 5
    int origemOctaedroLinha = 2, origemOctaedroColuna = 3; // Octaedro na linha 2, coluna 3

    // Aplicando as habilidades no tabuleiro
    aplicarCone(tabuleiro, origemConeLinha, origemConeColuna, 4);  // Cone de tamanho 4
    aplicarCruz(tabuleiro, origemCruzLinha, origemCruzColuna, 3);  // Cruz de tamanho 3
    aplicarOctaedro(tabuleiro, origemOctaedroLinha, origemOctaedroColuna, 3);  // Octaedro de tamanho 3

    // Exibindo o tabuleiro com as habilidades aplicadas
    printf("Tabuleiro com Habilidades Aplicadas:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
