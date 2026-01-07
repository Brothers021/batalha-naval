#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    char colunas [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
//criando tabuleiro 10x10
    int tabuleiro [10][10];

    printf(" Exibindo o tabuleiro:\n");

 // iniciar o tabuleiro com água 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // Inicializa todas as posições do tabuleiro com 0 (água)
        }
    }
// posiçionando navios no tabuleiro em diagonais tamanho 3
   for (int i = 0; i < 3; i++){
    tabuleiro[i][i] = 3;
   }
 // posiçionando navios no tabuleiro na diagonal tamanho 3  
   for (int i = 0; i < 3; i++){
    tabuleiro[i][9 - i] = 3;
   }
// posiçionando navios no tabuleiro horizontalmente tamanho 3
    for (int j = 4; j < 7; j++) {
        tabuleiro[2][j] = 3;
    }
 // posiçionando o navio na vertical tamanho 3
    for (int i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3;
    }
// aparecer cabeçalho da coluna
    printf("  ");
    for (int j = 0; j < 10; j++){
        printf(" %c ", colunas[j]);
    }
    printf("\n");


// aparecer o tabuleiro com números nas linhas
   for (int i = 0; i < 10; i++){
    printf("%d ", i);
   for (int j = 0; j < 10; j++) {
   printf("%2d ", tabuleiro[i][j]);
}
   printf("\n");
}
    return 0;
}
